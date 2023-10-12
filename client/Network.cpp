/*
** EPITECH PROJECT, 2023
** R-Type [WSL: Ubuntu]
** File description:
** Network
*/

#include "Network.hpp"

Rtype::Network::Network(boost::asio::io_context &ioContext, RNGine::Registry &registry)
    : _socket(ioContext, boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), 13)), _registry(registry)
{
    receiveRequest();
    ioContext.run();
}

void Rtype::Network::receiveRequest()
{
    _socket.async_receive_from(boost::asio::buffer(&_data, sizeof(Data)), _senderEndpoint,
                               [&](const boost::system::error_code &error, std::size_t bytes_received)
                               {
                                   if (!error)
                                       treatRequest();                             
                                   memset(&_data, 0, sizeof(Data));
                                   receiveRequest();
                               });
}

// void Rtype::Network::sendRequest(boost::asio::ip::udp::endpoint endpoint)
// {
//     _socket.async_send_to(boost::asio::buffer(&_buffer, _maxLength), endpoint,
//                           [&](const boost::system::error_code &error, std::size_t bytes_sent)
//                           {
//                               if (!error)
//                                   std::cout << "Sent: " << _buffer << std::endl;
//                           });
// }

void Rtype::Network::treatRequest()
{
    
}
