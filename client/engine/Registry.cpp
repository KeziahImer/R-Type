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

    template <typename Component>
    SparseArray<Component> &Registry::registerComponent()
    {
        auto type_id = std::type_index(typeid(Component));
        if (components_.find(type_id) == components_.end())
        {
            auto any = std::make_any<SparseArray<Component>>();
            components_[type_id] = any; // Store std::any directly, no need to wrap it with std::unique_ptr
        }

        // Extract and return the SparseArray<Component> from std::any
        return std::any_cast<SparseArray<Component> &>(components_[type_id]);
    }

    template <typename Component>
    SparseArray<Component> &Registry::getComponents()
    {
        auto type_id = std::type_index(typeid(Component));

        // Extract and return the SparseArray<Component> from std::any
        return std::any_cast<SparseArray<Component> &>(components_[type_id]);
    }

    template <typename Component>
    Registry &Registry::addComponent(EntityID entity, Component const &component)
    {
        SparseArray<Component> &components = registerComponent<Component>();
        components.insert_at(entity, component);
        return *this; // Return *this to match the return type.
    }

}
