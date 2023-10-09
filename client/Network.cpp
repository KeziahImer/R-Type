/*
** EPITECH PROJECT, 2023
** R-Type [WSL: Ubuntu]
** File description:
** Network
*/

#include "Network.hpp"

Network::Network(boost::asio::io_context &io_context, const std::chrono::time_point<std::chrono::_V2::system_clock, std::chrono::_V2::system_clock::duration> &tStart)
    : _socket(io_context, boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), 13)), _tStart(tStart)
{
    receiveRequest();
}

void Network::receiveRequest()
{
    _socket.async_receive_from(boost::asio::buffer(_buffer, _maxLength), _senderEndpoint,
                               [&](const boost::system::error_code &error, std::size_t bytes_received)
                               {
                                   if (!error)
                                   {
                                       _recvBuffer = std::string(_buffer, bytes_received);
                                       const auto tEnd = std::chrono::high_resolution_clock::now();
                                       const auto time = std::chrono::duration<double, std::milli>(tEnd - _tStart).count();
                                       std::cout << "Received: " << _recvBuffer << std::endl;
                                       treatRequest();
                                       sendRequest();
                                   }
                                   memset(_buffer, 0, _maxLength);
                                   receiveRequest();
                               });
}

void Network::sendRequest()
{
    _socket.async_send_to(boost::asio::buffer(_sendBuffer.c_str(), _sendBuffer.length()), _senderEndpoint,
                          [&](const boost::system::error_code &error, std::size_t bytes_sent)
                          {
                              if (!error)
                                  std::cout << "Sent: " << _sendBuffer << std::endl;
                              _recvBuffer = "";
                              _sendBuffer = "";
                          });
}

void Network::treatRequest()
{
}
