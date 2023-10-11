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
    receiveRequest();
}

void Network::receiveRequest()
{
    _socket.async_receive_from(boost::asio::buffer(_buffer, _maxLength), _senderEndpoint,
                               [&](const boost::system::error_code &error, std::size_t bytes_received)
                               {
                                   if (!error)
                                       checkEndpoint();
                                   memset(_buffer, 0, _maxLength);
                                   receiveRequest();
                               });
}

void Network::sendRequest(boost::asio::ip::udp::endpoint endpoint)
{
    _socket.async_send_to(boost::asio::buffer(_buffer, _maxLength), endpoint,
                          [&](const boost::system::error_code &error, std::size_t bytes_sent)
                          {
                              if (!error)
                                  std::cout << "Sent: " << _buffer << std::endl;
                          });
}

void Network::checkEndpoint()
{
    int verif = 0;
    for (auto player : _players)
    {
        if (player.address == _senderEndpoint.address().to_string() && player.port == _senderEndpoint.port())
        {
            verif = 1;
            break;
        }
    }
    if (verif == 0)
    {
        Player_t newPlayer;
        newPlayer.address = _senderEndpoint.address().to_string();
        newPlayer.port = _senderEndpoint.port();
        _players.push_back(newPlayer);
    }
    else
    {
        for (auto player : _players)
        {
            if (player.address != _senderEndpoint.address().to_string() && player.port != _senderEndpoint.port())
                sendRequest(player.endpoint);
        }
    }
}
