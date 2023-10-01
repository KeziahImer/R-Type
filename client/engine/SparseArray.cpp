/*
** EPITECH PROJECT, 2023
** r-type
** File description:
** SparseArray
*/

#include "GameEngine/ECS.hpp"

namespace GameEngine
{
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
    typename SparseArray<Component>::reference_type SparseArray<Component>::insert_at(size_type pos, Component const &value)
    {
        if (pos >= _data.size())
            _data.resize(pos + 1);
        _data[pos] = value;
        return _data[pos];
    }

    template <typename Component>
    void GameEngine::SparseArray<Component>::erase(size_type pos)
    {
        if (pos < _data.size())
            _data.erase(_data.begin() + pos);
    }

    template <typename Component>
    typename GameEngine::SparseArray<Component>::size_type SparseArray<Component>::get_index(Component const &value) const
    {
        for (size_type i = 0; i < _data.size(); i++)
            if (_data[i] == value)
                return i;
        return _data.size();
    }

}
