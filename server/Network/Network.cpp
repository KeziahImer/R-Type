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
    _socket.async_receive_from(boost::asio::buffer(_recvBuffer, _maxLength), _senderEndpoint,
                               [&](const boost::system::error_code &error, std::size_t bytes_received)
                               {
                                   if (!error)
                                   {
                                       const auto tEnd = std::chrono::high_resolution_clock::now();
                                       std::cout << "Clock: " << std::fixed << std::setprecision(0) << std::chrono::duration<double, std::milli>(tEnd - _tStart).count() << "ms" << std::endl;
                                       //    treatRequest(_recvBuffer);
                                       std::cout << "Received: " << _recvBuffer << std::endl;
                                       sendRequest(bytes_received);
                                   }
                                   receiveRequest();
                               });
}

void Network::sendRequest(std::size_t length)
{
    _socket.async_send_to(boost::asio::buffer(_recvBuffer, length), _senderEndpoint,
                          [&](const boost::system::error_code &error, std::size_t bytes_sent)
                          {
                              if (!error)
                                  std::cout << "Sent: " << _recvBuffer << std::endl;
                              memset(_recvBuffer, 0, _maxLength);
                          });
}
