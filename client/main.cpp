#include <iostream>

#include "GameEngine/ECS.hpp"

int main()
{
    // Renderer renderer;
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
        // renderer.render();
    }
    GameEngine::Registry registry;

    GameEngine::EntityID entity = registry.createEntity("player");

    GameEngine::SparseArray<int> &components = registry.registerComponent<int>();
    registry.addComponent<int>(17, 42);

    std::cout << "Components: " << std::endl;
    for (size_t i = 0; i < components.size(); i++)
    {
        std::cout << components[i] << std::endl;
    }

    return 0;
}