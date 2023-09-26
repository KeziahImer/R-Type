#include <iostream>
#include <boost/asio.hpp>

void handle_receive(const boost::system::error_code &error, std::size_t bytes_received, boost::asio::ip::udp::endpoint sender_endpoint, boost::asio::ip::udp::socket &socket, char *receive_buffer)
{
    if (!error && bytes_received > 0)
    {
        std::string message = "Bien reçu le message suivant: " + std::string(receive_buffer, bytes_received);
        std::cout << "Message reçu : " << std::string(receive_buffer, bytes_received) << std::endl;
        socket.async_send_to(
            boost::asio::buffer(message), sender_endpoint, [](const boost::system::error_code &ec, std::size_t bytes_sent)
            {
            if (!ec) {
                std::cout << "Message envoyé avec succès." << std::endl;
            } else {
                std::cerr << "Erreur lors de l'envoi du message : " << ec.message() << std::endl;
            } });
    }
}

int main()
{
    boost::asio::io_context io_context;
    boost::asio::ip::udp::socket socket(io_context, boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), 8080));

    char receive_buffer[1024]; // Déclaration du tampon de réception

    boost::asio::ip::udp::endpoint sender_endpoint;
    while (true)
    {
        socket.async_receive_from(boost::asio::buffer(receive_buffer, sizeof(receive_buffer)), sender_endpoint,
                                  [&socket, &sender_endpoint, &receive_buffer](const boost::system::error_code &error, std::size_t bytes_received)
                                  {
                                      handle_receive(error, bytes_received, sender_endpoint, socket, receive_buffer);
                                  });
        io_context.run();
    }

    return 0;
}
