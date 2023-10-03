/*
** EPITECH PROJECT, 2023
** r-type
** File description:
** ECS
*/

#include "ECS.hpp"

template <typename Component>
typename SparseArray<Component>::reference_type SparseArray<Component>::operator[](size_t idx)
{
    return _data[idx];
}

template <typename Component>
typename SparseArray<Component>::const_reference_type SparseArray<Component>::operator[](size_t idx) const
{
    return _data[idx];
}

template <typename Component>
typename SparseArray<Component>::iterator SparseArray<Component>::begin()
{
    return _data.begin();
}

template <typename Component>
typename SparseArray<Component>::const_iterator SparseArray<Component>::begin() const
{
    return _data.begin();
}

template <typename Component>
typename SparseArray<Component>::const_iterator SparseArray<Component>::cbegin() const
{
    return _data.cbegin();
}

template <typename Component>
typename SparseArray<Component>::iterator SparseArray<Component>::end()
{
    return _data.end();
}

template <typename Component>
typename SparseArray<Component>::const_iterator SparseArray<Component>::end() const
{
    return _data.end();
}

template <typename Component>
typename SparseArray<Component>::const_iterator SparseArray<Component>::cend() const
{
    return _data.cend();
}

template <typename Component>
typename SparseArray<Component>::size_type SparseArray<Component>::size() const
{
    return _data.size();
}

template <typename Component>
reference_wrapper<Component> SparseArray<Component>::insert_at(size_type pos, Component const &value)
{
    if (pos >= _data.size())
        _data.resize(pos + 1);
    _data[pos] = value;
    return _data[pos];
}

template <typename Component>
void SparseArray<Component>::erase_at(size_type pos)
{
    if (pos >= _data.size())
        return;
    _data.erase(_data.begin() + pos);
}

template <typename Component>
size_type SparseArray<Component>::get_index_of(Component const &value) const
{
    for (size_type i = 0; i < _data.size(); i++)
        if (_data[i] == value)
            return i;
    return _data.size();
}

template <typename Component>
Entity SparseArray<Component>::createEntity(std::string const &name)
{
    EntityID id = nextEntityID_++;
    _entities[name] = id;
    return id;
}

template <typename Component>
Entity SparseArray<Component>::getEntityID(std::string const &name)
{
    auto it = _entities.find(name);
    if (it != _entities.end())
    {
        return it->second;
    }
    throw std::runtime_error("Entity not found in registry.");
}

template <typename Component>
SparceArray<Component> &SparseArray<Component>::&registerComponent()
{
    auto type_id = std::type_index(typeid(Component));
    if (components_.find(type_id) == components_.end())
    {
        auto any = std::make_any<SparseArray<Component>>();
        components_[type_id] = std::make_unique<std::any>(any);
    }
    return std::any_cast<SparseArray<Component> &>(*components_[type_id]);
}

template <typename Component>
SparseArray<Component> &SparseArray<Component>::getComponent()
{
    auto type_id = std::type_index(typeid(Component));
    if (components_.find(type_id) == components_.end())
    {
        throw std::runtime_error("Component not found in registry.");
    }
    return std::any_cast<SparseArray<Component> &>(*components_[type_id]);
}

template <typename Component>
void SparseArray<Component>::addComponent(Entity entity, Component const &component)
{
    auto type_id = std::type_index(typeid(Component));
    if (components_.find(type_id) == components_.end())
    {
        throw std::runtime_error("Component not found in registry.");
    }
    auto &component_array = std::any_cast<SparseArray<Component> &>(*components_[type_id]);
    component_array.insert_at(entity, component);
}
