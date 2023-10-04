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
        auto tStart = std::chrono::high_resolution_clock::now();
        boost::asio::io_context ioContext;
        Network server(ioContext, tStart);
        ioContext.run();
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
