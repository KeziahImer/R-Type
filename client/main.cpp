#include <iostream>

#include "GameEngine/ECS.hpp"

int main()
{
    GameEngine::Registry registry;

    GameEngine::EntityID entity = registry.createEntity("player");

    registry.registerComponent<int>();

    GameEngine::SparseArray<int> &components = registry.getComponents<int>();
    registry.addComponent<int>(17, 42);

    std::cout << "Components: " << std::endl;
    for (size_t i = 0; i < components.size(); i++)
    {
        std::cout << components[i] << std::endl;
    }

    return 0;
}