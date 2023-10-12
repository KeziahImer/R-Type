/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** Core definition
*/

#include <cstddef>

#ifndef _RNGINE_CORE_HPP_
#define _RNGINE_CORE_HPP_

#include "./SceneManager.hpp"

namespace RNGine {
class Core {
public:
  void loop() {
    while (true) {
      manager.update();
    }
  }

  SceneManager manager;
};
}; // namespace RNGine

#endif