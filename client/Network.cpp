/*
** EPITECH PROJECT, 2023
** R-Type [WSL: Ubuntu]
** File description:
** Network
*/

#include "Network.hpp"

Rtype::Network::Network(boost::asio::io_context &ioContext)
    : _socket(ioContext, boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), 13))
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

void Rtype::Network::sendRequest()
{
    // _socket.async_send_to(boost::asio::buffer(&_buffer, _maxLength), endpoint,
    //                       [&](const boost::system::error_code &error, std::size_t bytes_sent)
    //                       {
    //                           if (!error)
    //                               std::cout << "Sent: " << _buffer << std::endl;
    //                       });

    try
    {
        io_service io_service;

        udp::socket socket(io_service, udp::endpoint(udp::v4(), 0));
        udp::endpoint server_endpoint(ip::address::from_string("172.22.178.144"), 13);
        std::string message = "login";
        socket.send_to(boost::asio::buffer(message), server_endpoint);
        char buffer[128];
        udp::endpoint sender_endpoint;
        size_t bytes_received = socket.receive_from(boost::asio::buffer(buffer, sizeof(buffer)), sender_endpoint);
    }
    catch (std::exception &e)
    {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }

}

void Rtype::Network::treatRequest()
{
    
}
