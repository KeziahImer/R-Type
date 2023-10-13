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

enum Command {
    LOGIN,
    MOVE
};

enum Code {
    SUCCESS,
    ERROR
};

typedef struct Data_t {
    enum Command command;
    std::string content;
    enum Code code;
} Data;

typedef struct Player_t {
    boost::asio::ip::udp::endpoint endpoint;
    std::string address;
    std::string id;
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
    std::vector<Player> _players;
    Data _data;
};

#endif /* !NETWORK_HPP_ */
