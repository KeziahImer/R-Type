
#include <iostream>
#include "GameEngine/ECS.hpp"
#include "components/Components.hpp"
#include "Renderer.hpp"
#include "Parsing.hpp"
#include "SceneManager.hpp"
#include "Inputer.hpp"
#include "Systems.hpp"

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

    Inputer inputs(renderer.getWindow());
    Systems systems;
    std::map<enum sf::Keyboard::Key, bool> inputsMap;
    bool playing = true;

    while (playing)
    {
        inputsMap = inputs.getInputs();
        registry.setInputs(inputsMap);
        registry.run();
        renderer.render(registry);
    }
    return 0;
}
