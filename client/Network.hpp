/*
** EPITECH PROJECT, 2023
** R-Type [WSL: Ubuntu]
** File description:
** Network
*/

#ifndef NETWORK_HPP_
#define NETWORK_HPP_

#include "rngine/Core.hpp"
#include <boost/asio.hpp>
#include <exception>
#include <iomanip>
#include <iostream>
#include <rngine/Registry.hpp>
#include <vector>

enum Command { LOGIN, START, MOVE, SHOOT, NOTHING };

enum Code { SUCCESS, ERROR, NONE };

typedef struct Data_t {
  enum Command command = Command::NOTHING;
  char content[1024] = {0};
  enum Code code = Code::NONE;
} Data;

namespace Rtype {
class Network {
public:
  Network(boost::asio::io_context &ioContext, RNGine::Core *core);
  ~Network() = default;
  void receiveRequest();
  void sendRequest(enum Command command, enum Code code, const char content[]);
  void treatRequest();

private:
  boost::asio::ip::udp::socket _socket;
  boost::asio::ip::udp::endpoint _endpoint;
  boost::asio::io_context &_ioContext;
  bool _isConnected = false;
  Data _data;
  RNGine::Core *_core;
  int _ID = 0;
};
} // namespace Rtype

#endif /* !NETWORK_HPP_ */
