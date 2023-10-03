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

void Systems::checkShoot(GameEngine::Registry &registry)
{
    GameEngine::SparseArray<Shoot> &Shoots = registry.getComponents<Shoot>();
    GameEngine::SparseArray<Position> &Positions = registry.getComponents<Position>();
    std::map<enum sf::Keyboard::Key, bool> inputs = registry.getInputs();

    for (size_t i = 0; i < Shoots.size(); i++)
    {
        try
        {
            for (auto inputPress : inputs) {
                    if ((inputPress.first == Shoots[i].Input) && inputPress.second) {
                        if (!Shoots[i].canShoot) continue;
                        std::cout << std::time(0) - Shoots[i].lastShoot << std::endl;
                        if (std::time(0) - Shoots[i].lastShoot > Shoots[i].timeMillisecond) {
                            Shoots[i].lastShoot = std::time(0);
                            GameEngine::EntityID shoot = registry.createEntity("shoot");
                            registry.addComponent<Position>(shoot, Position(Positions[i].x, Positions[i].y));
                            registry.addComponent<Velocity>(shoot, Velocity(Shoots[i].speedX, 0));
                            registry.addComponent<Sprite>(shoot, Sprite("./client/assets/ShootsAndPlayer.gif", false, 33, 22, 6, 1));
                            registry.addComponent<Size>(shoot, Size(1, 1));
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

void Systems::destroyOutScreenEntity(GameEngine::Registry &registry)
{
    GameEngine::SparseArray<Position> &Positions = registry.getComponents<Position>();
    for (size_t i = 0; i < Positions.size(); i++)
    {
        try
        {
            if (Positions[i].x < -150)
                registry.removeComponent<Sprite>(i);
            if (Positions[i].x > 1920 + 150)
                registry.removeComponent<Sprite>(i);
        }
        catch (const std::exception &e)
        {
            continue;
        }
    }
}