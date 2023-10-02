
#include <iostream>
#include "GameEngine/ECS.hpp"
#include "components/Components.hpp"
#include "Renderer.hpp"

int main()
{
    GameEngine::Registry registry;
    Renderer renderer(1920, 1080, "SuperJeu");

    GameEngine::EntityID background = registry.createEntity("background");
    GameEngine::EntityID entity = registry.createEntity("player");

    registry.addComponent<Position>(entity, Position(40, 50));
    registry.addComponent<Position>(background, Position(0, 0));
    registry.addComponent<Size>(entity, Size(100, 50));
    registry.addComponent<Size>(background, Size(1920, 1080));
    std::map<sf::Keyboard::Key, std::pair<int, int>> keybinds{{sf::Keyboard::Z, std::make_pair<int, int>(0, -5)}, {sf::Keyboard::Q, std::make_pair<int, int>(-5, 0)}, {sf::Keyboard::S, std::make_pair<int, int>(0, 5)}, {sf::Keyboard::D, std::make_pair<int, int>(5, 0)}};
    registry.addComponent<Movable>(entity, Movable(keybinds));
    registry.addComponent<Velocity>(entity, Velocity(0, 0));
    registry.addComponent<Sprite>(entity, Sprite("../../client/assets/Player.gif", 33, 17, 0, 2));
    registry.addComponent<Sprite>(background, Sprite("../../client/assets/backgroundSpace.jpg", 514, 360, 0, 0));
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

    // Adil
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
    sf::RenderWindow _window(sf::VideoMode(1920, 1080), "R-Type");
    while (_window.isOpen()) {
        sf::Event event;
        if (_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                _window.close();
        }
        _window.clear();
        _window.display();
    }
}
