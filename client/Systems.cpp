/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** Systems
*/

#include "Systems.hpp"

Systems::Systems() {}

Systems::~Systems() {}

void Systems::checkMovable(GameEngine::Registry &registry)
{
    GameEngine::SparseArray<Movable> &Movables =
        registry.getComponents<Movable>();
    GameEngine::SparseArray<Velocity> &Velocities =
        registry.getComponents<Velocity>();
    GameEngine::SparseArray<Parallax> &parallaxs =
        registry.getComponents<Parallax>();
    std::map<enum sf::Keyboard::Key, bool> inputs = registry.getInputs();
    for (size_t i = 0; i < Movables.size(); i++)
    {
        try
        {
            if (parallaxs[i].parallax)
                continue;
            Velocities[i].x = 0;
            Velocities[i].y = 0;
            for (auto inputPress : inputs)
            {
                for (auto inputRequire : Movables[i].keybinds)
                {
                    if ((inputPress.first == inputRequire.first) && inputPress.second)
                    {
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

void Systems::checkVelocity(GameEngine::Registry &registry)
{
    GameEngine::SparseArray<Velocity> &Velocities =
        registry.getComponents<Velocity>();
    GameEngine::SparseArray<Position> &Positions =
        registry.getComponents<Position>();

    float deltaTime = registry.clock.getDeltaTimeMilliseconds();
    for (size_t i = 0; i < Velocities.size(); i++)
    {
        try
        {
            //   std::cout << "resukta :" << (Velocities[i].x * deltaTime)
            //             << ", velocity :" << Velocities[i].x << ", delta: " << deltaTime
            //             << ", entity: " << i << std::endl;
            Positions[i].x = Positions[i].x + (Velocities[i].x * deltaTime);
            Positions[i].y = Positions[i].y + (Velocities[i].y * deltaTime);
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
    GameEngine::SparseArray<Position> &Positions =
        registry.getComponents<Position>();
    std::map<enum sf::Keyboard::Key, bool> inputs = registry.getInputs();

    for (size_t i = 0; i < Shoots.size(); i++)
    {
        try
        {
            for (auto inputPress : inputs)
            {
                if ((inputPress.first == Shoots[i].Input) && inputPress.second)
                {
                    if (!Shoots[i].canShoot)
                        continue;
                    auto time = std::chrono::system_clock::now().time_since_epoch();
                    if (std::chrono::duration_cast<std::chrono::milliseconds>(time)
                                .count() -
                            std::chrono::duration_cast<std::chrono::milliseconds>(
                                Shoots[i].lastShoot)
                                .count() >
                        Shoots[i].timeMillisecond)
                    {
                        Shoots[i].lastShoot = time;
                        GameEngine::EntityID shoot = registry.createEntity("shoot");
                        registry.addComponent<Position>(
                            shoot, Position(Positions[i].x, Positions[i].y));
                        registry.addComponent<Velocity>(shoot,
                                                        Velocity(Shoots[i].speedX, 0));
                        registry.addComponent<Sprite>(
                            shoot, Sprite("./client/assets/ShootsAndPlayer.gif", false, 33,
                                          22, 6, 1));
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
    GameEngine::SparseArray<Position> &Positions =
        registry.getComponents<Position>();
    GameEngine::SparseArray<Parallax> &parallaxs =
        registry.getComponents<Parallax>();
    for (size_t i = 0; i < Positions.size(); i++)
    {
        try
        {
            if (Positions[i].x < -150 && !parallaxs[i].parallax)
                registry.removeEntity(i);
            if (Positions[i].x > 1920 + 150 && !parallaxs[i].parallax)
                registry.removeEntity(i);
        }
        catch (const std::exception &e)
        {
            continue;
        }
    }
}

void Systems::updateParallax(GameEngine::Registry &registry)
{
    GameEngine::SparseArray<Position> &Positions =
        registry.getComponents<Position>();

    for (size_t i = 0; i < Positions.size(); i++)
    {
        try
        {
            if (Positions[i].x <= -1920)
                Positions[i].x = 1920;
        }
        catch (const std::exception &e)
        {
            continue;
        }
    }
}
