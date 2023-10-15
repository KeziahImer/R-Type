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

Rtype::Network::Network(boost::asio::io_context &ioContext, RNGine::Core *core)
    : _socket(ioContext,
              boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), 80)),
      _ioContext(ioContext),
      _endpoint(boost::asio::ip::address::from_string("127.0.0.1"), 8080),
      _core(core) {
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
  std::cout << "befor ecopy: " << strlen(content) << std::endl;
  strcpy(_data.content, content);
  std::cout << "after ecopy" << std::endl;
  _data.command = command;
  _data.code = code;
  std::cout << "befor send: " << _data.content << ", " << _data.command << ", "
            << _data.code << std::endl;
  _socket.send_to(boost::asio::buffer(&_data, sizeof(Data)), _endpoint);
  std::cout << "after send" << std::endl;
}

void Rtype::Network::treatRequest() {
  Rtype::LobbyScene &lobby =
      static_cast<Rtype::LobbyScene &>(_core->manager.getScene("lobby"));
  if (_data.command == LOGIN) {
    if (_data.code == ERROR)
      std::cout << "error login" << std::endl;
    //  throw(std::exception("Already four players connected"));
    if (lobby.getId() != "lobby") {
      std::cout << " exit because: " << lobby.getId() << std::endl;
      return;
    }
    std::cout << "login !!!!!!" << std::endl;
    if (!_isConnected) {
      lobby.setIDPlayer(std::stoi((_data.content)));
      lobby.setNumberPlayers(std::stoi(_data.content));
      _isConnected = true;
    } else {
      lobby.setNumberPlayers(std::stoi(_data.content));
    }
  } else if (_data.command == START) {
    lobby.startGame(2, _core);
  } else if (_data.command == MOVE) {
    Rtype::GameMultiScene &multi = static_cast<Rtype::GameMultiScene &>(
        _core->manager.getScene("gameMulti"));
    std::cout << "SWITCH VELOCITY :::: " << _data.content << std::endl;
    multi.setVelocity(_data.content);
  }
}
