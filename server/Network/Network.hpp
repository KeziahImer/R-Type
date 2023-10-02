/*
** EPITECH PROJECT, 2023
** R-Type [WSL: Ubuntu]
** File description:
** Network
*/

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/array.hpp>
#include <iostream>

class Network
{
public:
    Network(boost::asio::io_context &io_context);
    ~Network() = default;

private:
    void start_receive();
    void handle_receive(const boost::system::error_code &error, std::size_t);
    void handle_send(boost::shared_ptr<std::string>, const boost::system::error_code &, std::size_t);

    boost::asio::ip::udp::socket _socket;
    boost::asio::ip::udp::endpoint _remoteEndpoint;
    boost::array<char, 1> _recvBuffer;
};
