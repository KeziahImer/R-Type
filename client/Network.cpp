/*
** EPITECH PROJECT, 2023
** R-Type [WSL: Ubuntu]
** File description:
** Network
*/

#include "Network.hpp"
#include "rules/scenes/Lobby.hpp"
#include "rules/scenes/MultiplayerGame.hpp"
#include <cstring>
#include <linux/joystick.h>
#include <string>

Rtype::Network::Network(boost::asio::io_context &ioContext, RNGine::Core *core,
                        std::mutex &mutex)
    : _socket(ioContext,
              boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), 12)),
      _ioContext(ioContext),
      _endpoint(boost::asio::ip::address::from_string("192.168.1.93"), 8080),
      _core(core), _mutex(mutex) {
  receiveRequest();
}

void Rtype::Network::receiveRequest() {
  _socket.async_receive_from(
      boost::asio::buffer(&_data, sizeof(Data)), _endpoint,
      [&](const boost::system::error_code &error, std::size_t bytes_received) {
        if (!error)
          treatRequest();
        memset(&_data, 0, sizeof(Data));
        receiveRequest();
      });
}

void Rtype::Network::sendRequest(enum Command command, enum Code code,
                                 const char content[]) {
  strcpy(_data.content, content);
  _data.command = command;
  _data.code = code;
  _socket.send_to(boost::asio::buffer(&_data, sizeof(Data)), _endpoint);
}

void Rtype::Network::treatRequest() {
  _mutex.lock();
  Rtype::LobbyScene &lobby =
      static_cast<Rtype::LobbyScene &>(_core->manager.getScene("lobby"));
  if (_data.command == LOGIN) {
    if (_data.code == ERROR)
      std::cout << "error login" << std::endl;
    //  throw(std::exception("Already four players connected"));
    if (lobby.getId() != "lobby") {
      return;
    }
    if (!_isConnected) {
      lobby.setIDPlayer(std::stoi((_data.content)));
      _ID = std::stoi(_data.content);
      lobby.setNumberPlayers(std::stoi(_data.content));
      _isConnected = true;
    } else {
      lobby.setNumberPlayers(std::stoi(_data.content));
    }
  } else if (_data.command == START) {
    lobby.startGame(2, _core, this);
  } else if (_data.command == MOVE) {
    Rtype::GameMultiScene &multi = static_cast<Rtype::GameMultiScene &>(
        _core->manager.getScene("gameMulti"));
    multi.setVelocity(_data.content);
  } else if (_data.command == SHOOT) {
    Rtype::GameMultiScene &multi = static_cast<Rtype::GameMultiScene &>(
        _core->manager.getScene("gameMulti"));
    multi.makeShoot(_data.content);
  } else if (_data.command == DAMAGE) {
    Rtype::GameMultiScene &multi = static_cast<Rtype::GameMultiScene &>(
        _core->manager.getScene("gameMulti"));
    multi.makeShoot(_data.content);
  }
  _mutex.unlock();
}
