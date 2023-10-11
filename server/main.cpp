/*
** EPITECH PROJECT, 2023
** R-Type [WSL: Ubuntu]
** File description:
** main
*/

#include "Network/Network.hpp"

int main()
{
    try
    {
        boost::asio::io_context ioContext;
        Network server(ioContext);
        ioContext.run();
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
