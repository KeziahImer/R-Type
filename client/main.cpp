
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
        sceneManager = std::make_unique<SceneManager>(parser.getAllData());
    else {
        std::cerr << "Pas de json disponible" << std::endl;
        return 0;
    }

    sceneManager.get()->loadScene(sceneManager.get()->getAllScenes().front());
    Renderer renderer(1920, 1080, "SuperJeu");
    Inputer inputs(renderer.getWindow());
    Systems systems;
    std::map<enum sf::Keyboard::Key, bool> inputsMap;
    GameEngine::EntityID background = registry.createEntity("background");
    GameEngine::EntityID entity = registry.createEntity("player");
    GameEngine::EntityID enemy = registry.createEntity("enemy");

    registry.addComponent<Position>(entity, Position(40, 50));
    registry.addComponent<Position>(enemy, Position(1950, 500));
    registry.addComponent<Position>(background, Position(0, 0));
    registry.addComponent<Size>(entity, Size(2, 2));
    registry.addComponent<Size>(enemy, Size(2, 2));
    registry.addComponent<Size>(background, Size((double)1920 / 514, (double)1080 / 360));
    std::map<sf::Keyboard::Key, std::pair<int, int>> keybinds{{sf::Keyboard::Z, std::make_pair<int, int>(0, -5)}, {sf::Keyboard::Q, std::make_pair<int, int>(-5, 0)}, {sf::Keyboard::S, std::make_pair<int, int>(0, 5)}, {sf::Keyboard::D, std::make_pair<int, int>(5, 0)}};
    registry.addComponent<Movable>(entity, Movable(keybinds));
    registry.addComponent<Velocity>(entity, Velocity(0, 0));
    registry.addComponent<Velocity>(background, Velocity(0, 0));
    registry.addComponent<Velocity>(enemy, Velocity(-5, 0));
    registry.addComponent<Sprite>(entity, Sprite("./client/assets/Player.gif", false, 33, 17, 2, 2));
    registry.addComponent<Sprite>(enemy, Sprite("./client/assets/Player.gif", true, 33, 17, 2, 3));
    registry.addComponent<Sprite>(background, Sprite("./client/assets/backgroundSpace.jpg", false, 514, 360, 0, 0));
    registry.addComponent<Shoot>(entity, Shoot(sf::Keyboard::Space, 15, true, 250, std::chrono::system_clock::now().time_since_epoch()));


    std::function<void(GameEngine::Registry&)> checkMovable = std::bind(&Systems::checkMovable, &systems, std::placeholders::_1);
    std::function<void(GameEngine::Registry&)> checkVelocity = std::bind(&Systems::checkVelocity, &systems, std::placeholders::_1);
    std::function<void(GameEngine::Registry&)> checkShoot = std::bind(&Systems::checkShoot, &systems, std::placeholders::_1);
    std::function<void(GameEngine::Registry&)> destroyOutScreenEntity = std::bind(&Systems::destroyOutScreenEntity, &systems, std::placeholders::_1);
    registry.registerFunction(checkMovable);
    registry.registerFunction(checkVelocity);
    registry.registerFunction(checkShoot);
    registry.registerFunction(destroyOutScreenEntity);
    // GameEngine engine;
    // Registry registry;
    // SceneManager sceneManager;
    // get scenes

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
