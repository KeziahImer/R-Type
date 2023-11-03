/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** Rtype game implementation
*/

#include "Network/Engine.hpp"
#include "Network/Packet.hpp"
#include <cstring>

void Network::Engine::Bind(int port) {
  _socket.bind(
      boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), port));
}

void Network::Engine::Start() {
  _socket.async_receive_from(boost::asio::buffer(_buffer), _endpoint,
                             [this](const boost::system::error_code &error,
                                    std::size_t bytes_transferred) {
                               Receiver(error, bytes_transferred);
                             });
}

void Network::Engine::Receiver(const boost::system::error_code &err,
                               std::size_t size) {
  if (err) {
    std::cerr << "Error: " << err.message() << std::endl;
  } else {
    Network::Packet packet;
    auto buffer = _buffer;
    std::memcpy(&packet, buffer.data(), sizeof(Packet));
    auto padding = PacketSize[packet.type];
    std::memset(buffer.data() + padding, 0, Network::MAX_BUFFER_SIZE - padding);
    std::cout << "------------------- RECEIVE --------------------"
              << std::endl;
    std::cout << "Endpoint: " << _endpoint.address().to_string() << ":"
              << _endpoint.port() << std::endl;
    std::cout << "Packet: (" << packet.id << ", " << packet.checksum << ", "
              << packet.type << ", ";
    std::cout << "[";
    for (auto r : packet.receptions)
      std::cout << r << ", ";
    std::cout << "])" << std::endl;
    std::cout << "Buffer: ";
    for (auto c : buffer)
      std::cout << std::hex << (int)c;
    std::cout << std::dec << std::endl;
    if (Network::Engine::IsValidCheckSum(buffer)) {
      received[_endpoint][packet.id] = buffer;
      int lastReceptionId = packet.receptions[0];
      for (size_t i = 1; i < RECEPTION_AMOUNT; i++) {
        int receptionId = packet.receptions[i];
        if (receptionId < 0) {
          Resend(_endpoint, lastReceptionId - i);
        }
      }
    } else {
      std::cout << "CHECKSUM INVALID" << std::endl;
    }
  }
  Start();
}

void Network::Engine::Poll() { _context.poll(); }

void Network::Engine::Send(const boost::asio::ip::udp::endpoint &receiver,
                           const Network::Packet &packet) {
  auto p = packet;
  p.id = sended[receiver].size() + 1;
  Network::Engine::SetReceptions(p, _ReceptionsOf(receiver));

  Buffer buffer;
  std::memset(&buffer, 0, Network::MAX_BUFFER_SIZE);
  std::memcpy(&buffer, &p, PacketSize[p.type]);
  p.checksum = CalculateCheckSum(buffer);
  std::memset(&buffer, 0, Network::MAX_BUFFER_SIZE);
  std::memcpy(&buffer, &p, PacketSize[p.type]);
  sended[receiver][p.id] = buffer;
  std::cout << "--------------------- SEND ---------------------" << std::endl;
  std::cout << "Endpoint: " << receiver.address().to_string() << ":"
            << receiver.port() << std::endl;
  std::cout << "Packet: (" << p.id << ", " << p.checksum << ", " << p.type
            << ", ";
  std::cout << "[";
  for (auto r : p.receptions)
    std::cout << r << ", ";
  std::cout << "])" << std::endl;
  std::cout << "Buffer: ";
  for (auto c : buffer)
    std::cout << std::hex << (int)c;
  std::cout << std::dec << std::endl;
  try {
    _socket.send_to(boost::asio::buffer(&p, PacketSize[p.type]), receiver);
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }
}

void Network::Engine::Resend(const boost::asio::ip::udp::endpoint &receiver,
                             int id) {
  _socket.send_to(boost::asio::buffer(&sended[receiver][id], MAX_BUFFER_SIZE),
                  receiver);
}

boost::asio::ip::udp::endpoint
Network::Engine::Resolve(const std::string &ip, const std::string &port) {
  boost::asio::ip::udp::resolver resolver(_context);
  boost::asio::ip::udp::resolver::results_type endpoints =
      resolver.resolve(boost::asio::ip::udp::v4(), ip, port);
  return *endpoints.begin();
}

int Network::Engine::CalculateCheckSum(const Buffer &b) {
  auto buffer = b;
  Network::Packet packet;
  std::memcpy(&packet, buffer.data(), sizeof(Packet));
  packet.checksum = 0;
  std::memcpy(&buffer, &packet, sizeof(Packet));
  int checksum = 0;
  for (auto c : buffer)
    checksum += c;
  return checksum;
}

bool Network::Engine::IsValidCheckSum(const Buffer &b) {
  auto buffer = b;
  Network::Packet packet;
  std::memcpy(&packet, buffer.data(), sizeof(Packet));
  return packet.checksum == CalculateCheckSum(b);
}

std::array<int, Network::RECEPTION_AMOUNT>
Network::Engine::GetReceptions(const Network::Packet &packet) {
  std::array<int, Network::RECEPTION_AMOUNT> receptions;
  for (int i = 0; i < Network::RECEPTION_AMOUNT; i++) {
    receptions[i] = packet.receptions[i];
  }
  return receptions;
}

void Network::Engine::SetReceptions(
    Network::Packet &packet,
    const std::array<int, RECEPTION_AMOUNT> &receptions) {
  for (int i = 0; i < Network::RECEPTION_AMOUNT; i++) {
    packet.receptions[i] = receptions[i];
  }
}

std::array<int, Network::RECEPTION_AMOUNT>
Network::Engine::_ReceptionsOf(const boost::asio::ip::udp::endpoint &receiver) {
  std::array<int, Network::RECEPTION_AMOUNT> receptions = {};
  auto lastIdReceived = received[receiver].rbegin();
  if (lastIdReceived == received[receiver].rend())
    return receptions;
  int lastId = lastIdReceived->first;
  for (int i = 0; i < Network::RECEPTION_AMOUNT; i++) {
    if (lastId <= 0) {
      break;
    }
    receptions[i] = received[receiver][lastId].has_value() ? lastId : -1;
    lastId--;
  }
  return receptions;
}
