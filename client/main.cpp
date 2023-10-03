
#include <iostream>
#include "GameEngine/ECS.hpp"
#include "components/Components.hpp"
#include "Renderer.hpp"
#include "Parsing.hpp"
#include "SceneManager.hpp"

int main()
{
    GameEngine::Registry registry;
    Parsing parser;
    std::unique_ptr<SceneManager> sceneManager;
    parser.parseJsonFiles();
    std::cout << parser.getAllData() << std::endl;

    if (parser.getAllData().size() != 0)
        sceneManager = std::make_unique<SceneManager>(parser.getAllData(), registry);
    else {
        std::cerr << "Pas de json disponible" << std::endl;
        return 0;
    }

    sceneManager.get()->loadScene(sceneManager.get()->getAllScenes().front());
    Renderer renderer(1920, 1080, "SuperJeu");

    // Inputer inputs;
    // GameEngine engine;
    // Registry registry;
    // SceneManager sceneManager;
    // get scenes

    bool playing = true;
    while (playing)
    {
        // inputs.getInputs();
        // change scene ?
        // registry.applySystems();
        sf::Event event;
        while (renderer.getWindow().pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                playing = false;
            }
        }

        // registry.applySystems();
        renderer.render(registry);
    }
}
