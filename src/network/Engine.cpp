/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** Rtype game implementation
*/

#include "Network/Engine.hpp"
#include "Network/Packet.hpp"
#include <array>
#include <chrono>
#include <cstring>
#include <iomanip>
#include <iostream>

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
    if (size > MAX_BUFFER_SIZE)
      size = MAX_BUFFER_SIZE;
    memset(_buffer.data() + size, 0, MAX_BUFFER_SIZE - size);
    std::string data(FromBinary(_buffer).data(), size);
    Packet packet;
    try {
      packet = Packet::FromString(data);
    } catch (const std::exception &e) {
      std::cerr << "Receiver: " << e.what() << '\n';
    }
    PrintTransfer("RECEIVE", _endpoint, _buffer, packet);
    received[_endpoint][packet.GetId()] = packet;
    for (auto reception : packet.GetFailed()) {
      Resend(_endpoint, reception);
    }
  }
  Start();
}

void Network::Engine::Poll() { _context.poll(); }

void Network::Engine::Send(const boost::asio::ip::udp::endpoint &receiver,
                           const Network::Packet &packet) {
  std::string data = packet.ToString();
  Buffer buffer;
  std::memset(buffer.data(), 0, MAX_BUFFER_SIZE);
  std::memcpy(buffer.data(), data.c_str(), data.size());
  buffer = ToBinary(buffer);
  PrintTransfer(" SEND  ", receiver, buffer, packet);
  try {
    _socket.send_to(boost::asio::buffer(buffer.data(), data.size()), receiver);
    sended[receiver][packet.GetId()] = data;
    auto now = std::chrono::steady_clock::now();
    std::chrono::duration<double> time_span =
        std::chrono::duration_cast<std::chrono::duration<double>>(
            now.time_since_epoch());
    lastSend = time_span.count();
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }
}

void Network::Engine::Send(const boost::asio::ip::udp::endpoint &receiver,
                           const std::string &type, const std::string &data) {
  Packet packet;
  packet.SetId(sended[receiver].size() + 1);

  if (!received[receiver].empty()) {
    size_t lastPackedReceivedId = 0;
    lastPackedReceivedId = received[receiver].rbegin()->first;
    std::vector<Packet::PacketId> failed;
    for (size_t i = 1; i <= lastPackedReceivedId; i++) {
      if (received[receiver].find(i) == received[receiver].end())
        failed.push_back(i);
    }
    packet.SetFailed(failed);
  }
  packet.SetType(type);
  packet.SetData(data);
  Send(receiver, packet);
}

void Network::Engine::PrintTransfer(
    const std::string &type, const boost::asio::ip::udp::endpoint &endpoint,
    const Buffer &buffer, const Packet &packet) {
  std::cout << "------------------- " << type << " -------------------"
            << std::endl;
  std::cout << "Endpoint: " << endpoint.address().to_string() << ":"
            << endpoint.port() << std::endl;
  std::cout << "Packet: " << packet.ToString() << std::endl;
}

void Network::Engine::Resend(const boost::asio::ip::udp::endpoint &receiver,
                             int id) {
  auto data = sended[receiver][id];
  Buffer buffer;
  std::memset(buffer.data(), 0, MAX_BUFFER_SIZE);
  std::memcpy(buffer.data(), data.c_str(), data.size());
  buffer = ToBinary(buffer);
  _socket.send_to(boost::asio::buffer(buffer.data(), data.size()), receiver);
}

boost::asio::ip::udp::endpoint
Network::Engine::Resolve(const std::string &ip, const std::string &port) {
  boost::asio::ip::udp::resolver resolver(_context);
  boost::asio::ip::udp::resolver::results_type endpoints =
      resolver.resolve(boost::asio::ip::udp::v4(), ip, port);
  return *endpoints.begin();
}

Network::Engine::Buffer Network::Engine::ToBinary(const Buffer &buffer) {
  Buffer binary;
  std::memset(binary.data(), 0, MAX_BUFFER_SIZE);
  std::memcpy(binary.data(), buffer.data(), MAX_BUFFER_SIZE);
  for (auto &c : binary) {
    c -= '9';
  }
  return binary;
}

Network::Engine::Buffer Network::Engine::FromBinary(const Buffer &buffer) {
  Buffer binary;
  std::memset(binary.data(), 0, MAX_BUFFER_SIZE);
  std::memcpy(binary.data(), buffer.data(), MAX_BUFFER_SIZE);
  for (auto &c : binary) {
    c += '9';
  }
  return binary;
}
