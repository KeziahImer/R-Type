/*
** EPITECH PROJECT, 2023
** R-Type [WSL: Ubuntu]
** File description:
** Network
*/

#include "Network.hpp"
#include "rules/scenes/Lobby.hpp"
#include <cstring>
#include <string>

Rtype::Network::Network(boost::asio::io_context &ioContext, RNGine::Core &core)
    : _socket(ioContext,
              boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), 80)),
      _ioContext(ioContext),
      _endpoint(boost::asio::ip::address::from_string("192.168.1.93"), 8080),
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
  _data.command = command;
  _data.code = code;
  _socket.send_to(boost::asio::buffer(&_data, sizeof(Data)), _endpoint);
}

void Rtype::Network::treatRequest() {
  Rtype::LobbyScene &lobby =
      static_cast<Rtype::LobbyScene &>(_core.manager.getActualScene());
  if (_data.command == LOGIN) {
    if (_data.code == ERROR)
      std::cout << "error login" << std::endl;
    //  throw(std::exception("Already four players connected"));
    if (lobby.getId() == "menu") {
      std::cout << " exit because: " << lobby.getId() << std::endl;
      return;
    }
    std::cout << "login !!!!!!" << std::endl;
    if (!_isConnected) {
      std::cout << "test" << std::stoi((_data.content)) << std::endl;
      lobby.setIDPlayer(std::stoi((_data.content)));
      std::cout << "after set" << std::endl;
      std::cout << "set id:" << std::stoi((_data.content)) << std::endl;
      lobby.setNumberPlayers(std::stoi(_data.content));
      _isConnected = true;
    } else {
      lobby.setNumberPlayers(std::stoi(_data.content));
    }
  } else if (_data.command == START) {
    std::cout << "start !!!!!!" << std::endl;
    lobby.startGame(2);
  } else if (_data.command == MOVE) {
  }
}
