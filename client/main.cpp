/*
** EPITECH PROJECT, 2023
** R-Type [WSL: Ubuntu]
** File description:
** Network
*/

#include <iostream>
#include <boost/asio.hpp>
#include <boost/array.hpp>

int main(int argc, char *argv[])
{
    try
    {

        boost::asio::io_context io_context;
        boost::asio::ip::udp::endpoint receiverEndpoint(boost::asio::ip::udp::v4(), 13);
        boost::asio::ip::udp::socket socket(io_context, receiverEndpoint);
        socket.open(boost::asio::ip::udp::v4());
        socket.send_to(boost::asio::buffer("TEST"), receiverEndpoint);
        boost::array<char, 128> recv_buf;
        boost::asio::ip::udp::endpoint sender_endpoint;
        size_t len = socket.receive_from(
            boost::asio::buffer(recv_buf), sender_endpoint);

        std::cout.write(recv_buf.data(), len);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}