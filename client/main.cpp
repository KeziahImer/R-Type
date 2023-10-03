#include <iostream>

#include "GameEngine/ECS.hpp"

int main()
{
    GameEngine::Registry registry;

    GameEngine::EntityID entity = registry.createEntity("player");

    auto components = registry.registerComponent<std::string>();
    registry.addComponent<std::string>(entity, "42");

    std::cout << "Components: " << std::endl;
    for (size_t i = 0; i < components.size(); i++)
    {
        std::cout << components[i] << std::endl;
    }

    return 0;
}