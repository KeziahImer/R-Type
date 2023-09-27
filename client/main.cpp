#include <iostream>

#include "GameEngine/ECS.hpp"
#include "components/Components.hpp"

int main()
{
    GameEngine::Registry registry;
    GameEngine::EntityID entity = registry.createEntity("player");

    registry.addComponent<Position>(entity, Position(40, 50));
    registry.addComponent<Size>(entity, Size(100, 50));
    std::map<sf::Keyboard::Key, std::pair<int, int>> keybinds{{sf::Keyboard::Z, std::make_pair<int, int>(0, -5)}, {sf::Keyboard::Q, std::make_pair<int, int>(-5, 0)}, {sf::Keyboard::S, std::make_pair<int, int>(0, 5)}, {sf::Keyboard::D, std::make_pair<int, int>(5, 0)}};
    registry.addComponent<Movable>(entity, Movable(keybinds));
    registry.addComponent<Velocity>(entity, Velocity(0, 0));
    registry.addComponent<Sprite>(entity, Sprite("/assets/Player.gif", 33, 17, 0, 2));
    // Renderer renderer;
    // Inputer inputs;
    // GameEngine engine;
    // Registry registry;
    // SceneManager sceneManager;
    // get scenes

    bool playing = false;
    while (playing)
    {
        // inputs.getInputs();
        // change scene ?
        // registry.applySystems();
        // renderer.render();
    }
    return 0;
}