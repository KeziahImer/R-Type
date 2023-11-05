/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** Rtype game
*/

#ifndef _RTYPE_NETWORK_ENGINE_HPP_
#define _RTYPE_NETWORK_ENGINE_HPP_

#include <boost/asio.hpp>
#include <iostream>
#include <map>
#include <optional>
#include <vector>

#include "Packet.hpp"

namespace Network {
class Engine {
public:
  using Buffer = std::array<char, MAX_BUFFER_SIZE>;

public:
  Engine() : _context(), _socket(_context) {
    _socket.open(boost::asio::ip::udp::v4());
    Start();
  }
  Engine(int port)
      : _context(), _socket(_context, boost::asio::ip::udp::endpoint(
                                          boost::asio::ip::udp::v4(), port)) {
    Start();
  }
  ~Engine() = default;

  void Bind(int port);

  void Start();
  void Receiver(const boost::system::error_code &, std::size_t);

  void Poll();

  void Send(const boost::asio::ip::udp::endpoint &receiver,
            const Packet &packet);

  void Send(const boost::asio::ip::udp::endpoint &receiver,
            const std::string &type, const std::string &data);

  void Resend(const boost::asio::ip::udp::endpoint &receiver, int id);

  void PrintTransfer(const std::string &type,
                     const boost::asio::ip::udp::endpoint &endpoint,
                     const Buffer &buffer, const Packet &packet);

  static Buffer ToBinary(const Buffer &buffer);
  static Buffer FromBinary(const Buffer &buffer);

  boost::asio::ip::udp::endpoint Resolve(const std::string &ip,
                                         const std::string &port);

public:
  std::map<boost::asio::ip::udp::endpoint,
           std::map<size_t, std::optional<Packet>>>
      received;
  std::map<boost::asio::ip::udp::endpoint, std::map<size_t, std::string>>
      sended;

  double lastSend = 0.0f;

private:
  boost::asio::io_context _context;
  boost::asio::ip::udp::socket _socket;
  boost::asio::ip::udp::endpoint _endpoint;
  Buffer _buffer;
};
} // namespace Network

#endif