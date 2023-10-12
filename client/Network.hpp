/*
** EPITECH PROJECT, 2023
** R-Type [WSL: Ubuntu]
** File description:
** Network
*/

#ifndef NETWORK_HPP_
#define NETWORK_HPP_

#include <boost/asio.hpp>
#include <iostream>
#include <iomanip>
#include <chrono>
#include <ctime>

class Network
{
public:
    Network(boost::asio::io_context &io_context, const std::chrono::time_point<std::chrono::_V2::system_clock, std::chrono::_V2::system_clock::duration> &t_start);
    ~Network() = default;

private:
    void receiveRequest();
    void sendRequest();
    void treatRequest();

    boost::asio::ip::udp::socket _socket;
    boost::asio::ip::udp::endpoint _senderEndpoint;
    std::chrono::time_point<std::chrono::_V2::system_clock, std::chrono::_V2::system_clock::duration> _tStart;
    std::string _recvBuffer;
    std::string _sendBuffer;
    char _buffer[1024];
    std::size_t _maxLength = 1024;
};

#endif /* !NETWORK_HPP_ */