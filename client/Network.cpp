/*
** EPITECH PROJECT, 2023
** R-Type [WSL: Ubuntu]
** File description:
** Network
*/

#include "Network.hpp"

Rtype::Network::Network(boost::asio::io_context &ioContext, RNGine::Core &core)
    : _socket(ioContext, boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), 80)), _ioContext(ioContext), _endpoint(boost::asio::ip::address::from_string("10.15.190.100"), 8080), _core(core)
{
    receiveRequest();
}

void Rtype::Network::receiveRequest()
{
    _socket.async_receive_from(boost::asio::buffer(&_data, sizeof(Data)), _endpoint,
                               [&](const boost::system::error_code &error, std::size_t bytes_received)
                               {
                                   if (!error)
                                       treatRequest();                             
                                   memset(&_data, 0, sizeof(Data));
                                   receiveRequest();
                               });
}

void Rtype::Network::sendRequest(enum Command command, enum Code code, std::string content)
{
    _data.command = command;
    _data.code = code;
    _data.content = content;
    _socket.send_to(boost::asio::buffer(&_data, sizeof(Data)), _endpoint);
}

void Rtype::Network::treatRequest()
{
    if (_data.command == LOGIN) {
        if (_data.code == ERROR)
            throw(std::exception("Already four players connected"));
        if (!_isConnected) {
            _core.manager.getActualScene().setIDPlayer(std::to_integer(_data.content));
            _core.manager.getActualScene().setNumberPlayers(std::to_integer(_data.content));
            _isConnected = true;
        } else {
            _core.manager.getActualScene().setNumberPlayers(std::to_integer(_data.content));
        }
    } else if (_data.command == MOVE) {
        
    }
}
