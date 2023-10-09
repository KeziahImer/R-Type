/*
** EPITECH PROJECT, 2023
** R-Type [WSL: Ubuntu]
** File description:
** Network
*/

#include <iostream>
#include <boost/asio.hpp>
#include <boost/array.hpp>
using namespace boost::asio;
using ip::udp;

int main(int argc, char *argv[])
{
    try
    {
        io_service io_service;

        udp::socket socket(io_service, udp::endpoint(udp::v4(), 0));
        udp::endpoint server_endpoint(ip::address::from_string("192.168.48.233"), 13);

        std::cout << "Connecté au serveur!" << std::endl;

        std::string message = "Bonjour, serveur!";
        io_service.run();
        socket.send_to(boost::asio::buffer(message), server_endpoint);
        std::cout << "Connecté !" << std::endl;
        char buffer[128];
        udp::endpoint sender_endpoint;
        size_t bytes_received = socket.receive_from(boost::asio::buffer(buffer, sizeof(buffer)), sender_endpoint);

        std::cout << "Réponse du serveur : " << std::string(buffer, bytes_received) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }

    return 0;
    // try
    // {

    //     boost::asio::io_context io_context;
    //     boost::asio::ip::udp::endpoint receiverEndpoint(boost::asio::ip::udp::v4(), 13);
    //     boost::asio::ip::udp::socket socket(io_context, receiverEndpoint);
    //     socket.open(boost::asio::ip::udp::v4());
    //     socket.send_to(boost::asio::buffer("TEST"), receiverEndpoint);
    //     boost::array<char, 128> recv_buf;
    //     boost::asio::ip::udp::endpoint sender_endpoint;
    //     size_t len = socket.receive_from(
    //         boost::asio::buffer(recv_buf), sender_endpoint);

    //     std::cout.write(recv_buf.data(), len);
    // }
    // catch (std::exception &e)
    // {
    //     std::cerr << e.what() << std::endl;
    // }

    // return 0;
}