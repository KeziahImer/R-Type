#pragma once

#include <vector>
#include <utility>
#include <algorithm>
#include <iterator>
#include <memory>

namespace GameEngine
{

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
};
