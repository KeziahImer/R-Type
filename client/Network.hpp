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
#include <rngine/Registry.hpp>
#include <exception>
#include "rngine/Core.hpp"

enum Command {
    LOGIN,
    MOVE
};

enum Code {
    SUCCESS,
    ERROR,
    NONE
};

typedef struct Data_t {
    enum Command command;
    std::string content;
    enum Code code;
} Data;

namespace Rtype {
    class Network
    {
    public:
        Network(boost::asio::io_context &ioContext, RNGine::Core &core);
        ~Network() = default;
        void receiveRequest();
        void sendRequest(enum Command command, enum Code code, std::string content);
        void treatRequest();

    private:
        boost::asio::ip::udp::socket _socket;
        boost::asio::ip::udp::endpoint _endpoint;
        boost::asio::io_context &_ioContext;
        bool _isConnected = false;
        Data _data;
        RNGine::Core &_core;
    };
}

#endif /* !NETWORK_HPP_ */
