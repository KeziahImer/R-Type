
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

int main()
{
    GameEngine::Registry registry;
    Parsing parser;
    std::unique_ptr<SceneManager> sceneManager;
    parser.parseJsonFiles();
    std::cout << parser.getAllData() << std::endl;

    if (parser.getAllData().size() != 0)
        sceneManager = std::make_unique<SceneManager>(parser.getAllData(), registry);
    else
    {
        std::cerr << "Pas de json disponible" << std::endl;
        return 0;
    }

    sceneManager.get()->loadScene(sceneManager.get()->getAllScenes().front());
    Renderer renderer(1920, 1080, "SuperJeu");
    Inputer inputs(renderer.getWindow());
    Systems systems;

    // ComponentFactory factory(registry);
    // PrefabGenerator prefabGenerator(factory, registry, parser);

    // prefabGenerator.loadPrefab("player", "player01");

    std::map<enum sf::Keyboard::Key, bool> inputsMap;
    bool playing = true;
    while (playing)
    {
        if (!registry.clock.checkFrame())
            continue;
        inputsMap = inputs.getInputs();
        registry.setInputs(inputsMap);
        registry.run();
        renderer.render(registry);
    }
    return 0;
}
