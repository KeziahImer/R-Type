/*
** EPITECH PROJECT, 2023
** r-type
** File description:
** Registry
*/

#include "GameEngine/ECS.hpp"

namespace GameEngine
{
    EntityID Registry::createEntity(std::string const &name)
    {
        EntityID id = nextEntityID_++;
        _entities[name] = id;
        return id;
    }

    EntityID Registry::getEntityID(std::string const &name)
    {
        auto it = _entities.find(name);
        if (it != _entities.end())
        {
            return it->second;
        }
        throw std::runtime_error("Entity not found in registry.");
    }

}
