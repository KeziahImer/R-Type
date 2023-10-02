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
#include <functional>

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

        reference_type operator[](size_t idx)
        {
            return _data[idx];
        }

        const_reference_type operator[](size_t idx) const
        {
            return _data[idx];
        }

        iterator begin()
        {
            return _data.begin();
        }

        const_iterator begin() const
        {
            return _data.begin();
        }

        const_iterator cbegin() const
        {
            return _data.cbegin();
        }

        iterator end()
        {
            return _data.end();
        }

        const_iterator end() const
        {
            return _data.end();
        }

        const_iterator cend() const
        {
            return _data.cend();
        }

        size_type size() const
        {
            return _data.size();
        }

        reference_type insert_at(size_type pos, Component const &value)
        {
            if (pos >= _data.size())
            {
                _data.resize(pos + 1);
            }
            _data[pos] = value;
            return _data[pos];
        }

        void erase(size_type pos)
        {
            if (pos < _data.size())
            {
                _data.erase(_data.begin() + pos);
            }
        }

        size_type get_index(value_type const &value) const
        {
            auto it = std::find(_data.begin(), _data.end(), value);
            if (it != _data.end())
            {
                return std::distance(_data.begin(), it);
            }
            throw std::runtime_error("Value not found in SparseArray");
        }

    private:
        container_t _data;
    };

    class Registry
    {
    public:
        using FunctionType = std::function<void(Registry &)>;
        EntityID createEntity(std::string const &name);

        EntityID getEntityID(std::string const &name);

        template <typename Component>
        Registry &registerComponent()
        {
            auto type_id = std::type_index(typeid(Component));
            if (components_.find(type_id) == components_.end())
            {
                components_[type_id] = std::make_any<SparseArray<Component>>();
            }
            return *this;
        }

        Registry &registerFunction(FunctionType const &function)
        {
            _functions.push_back(function);
            return *this;
        }

        Registry &run(void)
        {
            for (auto const &function : _functions)
            {
                function(*this);
            }
            return *this;
        }

        template <typename Component>
        SparseArray<Component> &getComponents()
        {
            auto type_id = std::type_index(typeid(Component));
            return std::any_cast<SparseArray<Component> &>(components_[type_id]);
        }

        template <typename Component>
        Registry &addComponent(EntityID entity, Component const &component)
        {
            Registry &registry = registerComponent<Component>();
            SparseArray<Component> &components = registry.getComponents<Component>();
            components.insert_at(entity, component);
            std::cout << "CREATION DU COMPOSANT POUR L'ENTITY " << entity << std::endl;
            return *this;
        }

        template <typename Component>
        Registry &removeComponent(EntityID entity)
        {
            SparseArray<Component> &components = getComponents<Component>();
            components.erase(entity);
            return *this;
        }

    private:
        std::unordered_map<std::type_index, std::any> components_;
        std::map<std::string, EntityID> _entities;
        size_t nextEntityID_ = 0;
        std::vector<FunctionType> _functions;
    };
};
