/*
** EPITECH PROJECT, 2023
** R-Type [WSL: Ubuntu]
** File description:
** Network
*/

#include "Clock.hpp"
#include "GameEngine/ECS.hpp"
#include "Inputer.hpp"
#include "Parsing.hpp"
#include "Renderer.hpp"
#include "SceneManager.hpp"
#include "Systems.hpp"
#include "components/Components.hpp"
#include "PrefabsEngine/PrefabGenerator.hpp"
#include <iostream>

#include <iostream>
#include <boost/asio.hpp>
#include <boost/array.hpp>
using namespace boost::asio;
using ip::udp;

int main(int argc, char *argv[])
{
    // boost lock free queue
    try
    {
        io_service io_service;

        udp::socket socket(io_service, udp::endpoint(udp::v4(), 0));
        udp::endpoint server_endpoint(ip::address::from_string("192.168.48.233"), 13);
        std::string message = "login";
        std::cout << "Connecté au serveur!" << std::endl;
        socket.send_to(boost::asio::buffer(message), server_endpoint);
        char buffer[128];
        udp::endpoint sender_endpoint;
        size_t bytes_received = socket.receive_from(boost::asio::buffer(buffer, sizeof(buffer)), sender_endpoint);
        std::cout << "Réponse du serveur : " << std::string(buffer, bytes_received) << std::endl;

        // GameEngine::Registry registry;
        // Parsing parser;
        // std::unique_ptr<SceneManager> sceneManager;
        // parser.parseJsonFiles();
        // std::cout << parser.getAllData() << std::endl;

        // if (parser.getAllData().size() != 0)
        //     sceneManager = std::make_unique<SceneManager>(parser.getAllData(), registry);
        // else
        // {
        //     std::cerr << "Pas de json disponible" << std::endl;
        //     return 0;
        // }

        // sceneManager.get()->loadScene(sceneManager.get()->getAllScenes().front());
        // Renderer renderer(1920, 1080, "SuperJeu");
        // Inputer inputs(renderer.getWindow());
        // Systems systems;

        // // ComponentFactory factory(registry);
        // // PrefabGenerator prefabGenerator(factory, registry, parser);

        // // prefabGenerator.loadPrefab("player", "player01");

        // std::map<enum sf::Keyboard::Key, bool> inputsMap;
        // bool playing = true;
        // while (playing)
        // {
        //     if (!registry.clock.checkFrame())
        //         continue;
        //     inputsMap = inputs.getInputs();
        //     registry.setInputs(inputsMap);
        //     registry.run();
        //     renderer.render(registry);
        // }
    }
    catch (std::exception &e)
    {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }

    return 0;
    // GameEngine::Registry registry;
    // Parsing parser;
    // std::unique_ptr<SceneManager> sceneManager;
    // parser.parseJsonFiles();
    // std::cout << parser.getAllData() << std::endl;

    // if (parser.getAllData().size() != 0)
    //     sceneManager = std::make_unique<SceneManager>(parser.getAllData(), registry);
    // else
    // {
    //     std::cerr << "Pas de json disponible" << std::endl;
    //     return 0;
    // }

    // sceneManager.get()->loadScene(sceneManager.get()->getAllScenes().front());
    // Renderer renderer(1920, 1080, "SuperJeu");
    // Inputer inputs(renderer.getWindow());
    // Systems systems;

    // // ComponentFactory factory(registry);
    // // PrefabGenerator prefabGenerator(factory, registry, parser);

    // // prefabGenerator.loadPrefab("player", "player01");

    // std::map<enum sf::Keyboard::Key, bool> inputsMap;
    // bool playing = true;
    // while (playing)
    // {
    //     if (!registry.clock.checkFrame())
    //         continue;
    //     inputsMap = inputs.getInputs();
    //     registry.setInputs(inputsMap);
    //     registry.run();
    //     renderer.render(registry);
    // }
    // return 0;
}
