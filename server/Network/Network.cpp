/*
** EPITECH PROJECT, 2023
** R-Type [WSL: Ubuntu]
** File description:
** Network
*/

#include "Network.hpp"

Network::Network(boost::asio::io_context &io_context)
    : _socket(io_context, boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), 13))
{
    start_receive();
}

void Network::start_receive()
{
    _socket.async_receive_from(
        boost::asio::buffer(_recvBuffer), _remoteEndpoint,
        boost::bind(&Network::handle_receive, this,
                    boost::asio::placeholders::error,
                    boost::asio::placeholders::bytes_transferred));
}

void Network::handle_receive(const boost::system::error_code &error, std::size_t)
{
    if (!error)
    {
        boost::shared_ptr<std::string> message(
            new std::string("EH BONJOUREUH !"));
        _socket.async_send_to(boost::asio::buffer(*message), _remoteEndpoint,
                              boost::bind(&Network::handle_send, this, message,
                                          boost::asio::placeholders::error,
                                          boost::asio::placeholders::bytes_transferred));
        start_receive();
    }
}

void Network::handle_send(boost::shared_ptr<std::string>, const boost::system::error_code &, std::size_t)
{
}
