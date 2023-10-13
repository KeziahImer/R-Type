/*
** EPITECH PROJECT, 2023
** R-Type [WSL: Ubuntu]
** File description:
** Network
*/

#include "Network.hpp"

Network::Network(boost::asio::io_context &io_context)
    : _socket(io_context, boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), 8080))
{
    receiveRequest();
}

void Network::receiveRequest()
{
    _socket.async_receive_from(boost::asio::buffer(&_data, sizeof(Data)), _senderEndpoint,
                               [&](const boost::system::error_code &error, std::size_t bytes_received)
                               {
                                   if (!error)
                                       checkEndpoint();
                                   memset(&_data, 0, sizeof(Data));
                                   receiveRequest();
                               });
}

void Network::sendRequest(boost::asio::ip::udp::endpoint endpoint)
{
    _socket.send_to(boost::asio::buffer(&_data, sizeof(Data)), endpoint);
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
        if (_players.size() == 4)
        {
            _data.code = ERROR;
            strcpy(_data.content, "Server is full");
            sendRequest(_senderEndpoint);
            return;
        }
        _data.code = SUCCESS;
        Player_t newPlayer;
        newPlayer.address = _senderEndpoint.address().to_string();
        newPlayer.port = _senderEndpoint.port();
        newPlayer.id = std::to_string(_players.size() + 1);
        std::cout << _data.content << std::endl;
        strcpy(_data.content, std::to_string(_players.size() + 1).c_str());
        _players.push_back(newPlayer);
        std::cout << "New Player created: " << newPlayer.address << ":" << newPlayer.port << std::endl;
        sendRequest(_senderEndpoint);
    } else {
        for (auto player : _players)
        {
            if (player.address != _senderEndpoint.address().to_string() && player.port != _senderEndpoint.port())
                sendRequest(player.endpoint);
        }
    }
}
