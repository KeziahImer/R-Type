/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** Systems
*/

#include "Systems.hpp"

Systems::Systems()
{
}

Systems::~Systems()
{
}

void Systems::checkMovable(GameEngine::Registry& registry)
{
    GameEngine::SparseArray<Movable> &Movables = registry.getComponents<Movable>();
    GameEngine::SparseArray<Velocity> &Velocities = registry.getComponents<Velocity>();
    std::map<enum sf::Keyboard::Key, bool> inputs = registry.getInputs();
    for (size_t i = 0; i < Movables.size(); i++)
    {
        try
        {
            Velocities[i].x = 0;
            Velocities[i].y = 0;
            for (auto inputPress : inputs) {
                for (auto inputRequire : Movables[i].keybinds) {
                    if ((inputPress.first == inputRequire.first) && inputPress.second) {
                        Velocities[i].x += inputRequire.second.first;
                        Velocities[i].y += inputRequire.second.second;
                    }
                }
            }
        }
        catch (const std::exception &e)
        {
            continue;
        }
    }
}

void Systems::checkVelocity(GameEngine::Registry& registry)
{
    GameEngine::SparseArray<Velocity> &Velocities = registry.getComponents<Velocity>();
    GameEngine::SparseArray<Position> &Positions = registry.getComponents<Position>();

    for (size_t i = 0; i < Velocities.size(); i++)
    {
        try
        {
            Positions[i].x = Positions[i].x + Velocities[i].x;
            Positions[i].y = Positions[i].y + Velocities[i].y;
        }
        catch (const std::exception &e)
        {
            continue;
        }
    }
}