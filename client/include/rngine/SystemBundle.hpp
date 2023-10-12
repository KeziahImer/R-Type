/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** SystemBundle definition
*/

#ifndef _RNGINE_TYPES_SYSTEMBUNDLE_HPP_
#define _RNGINE_TYPES_SYSTEMBUNDLE_HPP_

#include <algorithm>
#include <vector>

namespace RNGine {
using System = std::function<void(void)>;

/**
 * @brief SystemBundle is used for register systems from where you want and will
 * be usable by the Registry to run them
 */
class SystemBundle {

public:
  using value_type = System;
  using reference_type = value_type &;
  using const_reference_type = value_type const &;
  using container_t = std::vector<value_type>;
  using size_type = typename container_t::size_type;
  using iterator = typename container_t::iterator;
  using const_iterator = typename container_t::const_iterator;

public:
  SystemBundle() = default;
  SystemBundle(SystemBundle const &) = default;
  SystemBundle(SystemBundle &&) noexcept = default;
  ~SystemBundle() = default;
  SystemBundle &operator=(SystemBundle const &) = default;
  SystemBundle &operator=(SystemBundle &&) noexcept = default;

  reference_type operator[](size_t idx) { return _data[idx]; }

  const_reference_type operator[](size_t idx) const { return _data[idx]; }

  iterator begin() { return _data.begin(); }

  const_iterator begin() const { return _data.begin(); }

  const_iterator cbegin() const { return _data.cbegin(); }

  iterator end() { return _data.end(); }

  const_iterator end() const { return _data.end(); }

  const_iterator cend() const { return _data.cend(); }

  size_type size() const { return _data.size(); }

  void push_back(value_type const &value) { _data.push_back(value); }

  void push_back(value_type &&value) { _data.push_back(value); }

  void erase(iterator const &it) { _data.erase(it); }

  void erase(iterator const &begin, iterator const &end) {
    _data.erase(begin, end);
  }

  void clear() { _data.clear(); }

  void run() {
    for (auto const &system : _data) {
      system();
    }
  }

private:
  std::vector<System> _data;
};
}; // namespace RNGine

#endif