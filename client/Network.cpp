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

Rtype::Network::Network(boost::asio::io_context &ioContext, RNGine::Core *core,
                        std::mutex &coreMutex)
    : _socket(ioContext,
              boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), 80)),
      _ioContext(ioContext),
      _endpoint(boost::asio::ip::address::from_string("127.0.0.1"), 8080),
      _core(core), _coreMutex(coreMutex) {
  receiveRequest();
}

void Rtype::Network::receiveRequest() {
  _socket.async_receive_from(
      boost::asio::buffer(&_data, sizeof(Data)), _endpoint,
      [&](const boost::system::error_code &error, std::size_t bytes_received) {
        if (!error)
          treatRequest();
        std::cout << "memset" << std::endl;
        memset(&_data, 0, sizeof(Data));
        std::cout << "after memset" << std::endl;
        receiveRequest();
        std::cout << "after receiveRequest" << std::endl;
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
  std::cout << "je rentre ici pour traiter" << _core << std::endl;
  //_coreMutex.lock();
  Rtype::LobbyScene &lobby =
      static_cast<Rtype::LobbyScene &>(_core->manager.getScene("lobby"));
  if (_data.command == LOGIN) {
    if (_data.code == ERROR)
      std::cout << "error login" << std::endl;
    //  throw(std::exception("Already four players connected"));
    if (lobby.getId() != "lobby") {
      std::cout << " exit because: " << lobby.getId() << std::endl;
      //_coreMutex.unlock();
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
    std::cout << "start !!!!!!" << std::endl;
    lobby.startGame(2, _core, _coreMutex);
    std::cout << "started !!!!!!" << std::endl;
  } else if (_data.command == MOVE) {
  }
  //_coreMutex.unlock();
}
