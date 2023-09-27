/*
** EPITECH PROJECT, 2023
** r-type
** File description:
** ECS
*/

#pragma once

#include <iostream>

#include <vector>
#include <utility>
#include <algorithm>
#include <iterator>
#include <typeindex>
#include <unordered_map>
#include <map>
#include <any>
#include <memory>

namespace GameEngine
{
    using EntityID = size_t;

    template <typename Component>
    class SparseArray
    {
    public:
        using value_type = Component;
        using reference_type = value_type &;
        using const_reference_type = value_type const &;
        using container_t = std::vector<value_type>;
        using size_type = typename container_t::size_type;
        using iterator = typename container_t::iterator;
        using const_iterator = typename container_t::const_iterator;

    public:
        SparseArray() = default;
        SparseArray(SparseArray const &) = default;
        SparseArray(SparseArray &&) noexcept = default;
        ~SparseArray() = default;
        SparseArray &operator=(SparseArray const &) = default;
        SparseArray &operator=(SparseArray &&) noexcept = default;
        reference_type operator[](size_t idx);
        const_reference_type operator[](size_t idx) const;
        iterator begin();
        const_iterator begin() const;
        const_iterator cbegin() const;
        iterator end();
        const_iterator end() const;
        const_iterator cend() const;
        size_type size() const;
        reference_type insert_at(size_type pos, Component const &value);
        void erase(size_type pos);
        size_type get_index(value_type const &value) const;

    private:
        container_t _data;
    };

    class Registry
    {
    public:
        EntityID createEntity(std::string const &name);
        EntityID getEntityID(std::string const &name);
        template <typename Component>
        Registry &registerComponent();
        template <typename Component>
        SparseArray<Component> &getComponents();
        template <typename Component>
        Registry &addComponent(EntityID entity, Component const &component);
        template <typename Component>
        Registry &removeComponent(EntityID entity);

    private:
        std::unordered_map<std::type_index, std::any> components_;
        std::map<std::string, EntityID> _entities;
        size_t nextEntityID_ = 0;
        std::vector<FunctionType> _functions;
    };
};
