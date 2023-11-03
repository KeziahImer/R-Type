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

  void Resend(const boost::asio::ip::udp::endpoint &receiver, int id);

  boost::asio::ip::udp::endpoint Resolve(const std::string &ip,
                                         const std::string &port);

  static int CalculateCheckSum(const Buffer &buffer);
  static bool IsValidCheckSum(const Buffer &buffer);

  static std::array<int, RECEPTION_AMOUNT> GetReceptions(const Packet &packet);
  static void
  SetReceptions(Packet &packet,
                const std::array<int, RECEPTION_AMOUNT> &receptions);

public:
  std::map<boost::asio::ip::udp::endpoint, std::map<int, std::optional<Buffer>>>
      received;
  std::map<boost::asio::ip::udp::endpoint, std::map<int, Buffer>> sended;

private:
  std::array<int, RECEPTION_AMOUNT>
  _ReceptionsOf(const boost::asio::ip::udp::endpoint &receiver);

  boost::asio::io_context _context;
  boost::asio::ip::udp::socket _socket;
  boost::asio::ip::udp::endpoint _endpoint;
  Buffer _buffer;
};
} // namespace Network

#endif