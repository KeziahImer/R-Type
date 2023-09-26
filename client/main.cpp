#include <iostream>
#include <boost/asio.hpp>

int main()
{
    boost::asio::io_context io_context;
    boost::asio::ip::udp::socket socket(io_context, boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), 0));
    boost::asio::ip::udp::endpoint remote_endpoint(boost::asio::ip::address::from_string("127.0.0.1"), 8080);
    std::string message;
    while (getline(std::cin, message))
    {
        if (std::cin.eof())
            break;
        socket.async_send_to(boost::asio::buffer(message), remote_endpoint, [](const boost::system::error_code &ec, std::size_t bytes_sent)
                             {
            if (!ec) {
                std::cout << "Message envoyé avec succès." << std::endl;
            } else {
                std::cerr << "Erreur lors de l'envoi du message : " << ec.message() << std::endl;
            } });
        char receive_buffer[1024];
        boost::asio::ip::udp::endpoint sender_endpoint;
        socket.async_receive_from(boost::asio::buffer(receive_buffer), sender_endpoint, [&receive_buffer](const boost::system::error_code &ec, std::size_t bytes_received)
                                  {
            if (!ec) {
                std::cout << "Message du serveur \"" << std::string(receive_buffer, bytes_received) << "\"" << std::endl;
            } else {
                std::cerr << "Erreur lors de la réception du message : " << ec.message() << std::endl;
            } });
        io_context.run();
    }
    return 0;
}
