/*
** EPITECH PROJECT, 2023
** R-Type [WSL: Ubuntu]
** File description:
** Network
*/

#ifndef NETWORK_HPP_
#define NETWORK_HPP_

#include <vector>
#include <boost/asio.hpp>
#include <iostream>
#include <iomanip>

typedef struct Player_t
{
    boost::asio::ip::udp::endpoint endpoint;
    std::string address;
    int port;
} Player;

class Network
{
public:
    Network(boost::asio::io_context &io_context);
    ~Network() = default;

private:
    void receiveRequest();
    void sendRequest(boost::asio::ip::udp::endpoint endpoint);
    void checkEndpoint();

    boost::asio::ip::udp::socket _socket;
    boost::asio::ip::udp::endpoint _senderEndpoint;
    char _buffer[1024];
    std::size_t _maxLength = 1024;
    std::vector<Player_t> _players;
};

#endif /* !NETWORK_HPP_ */
