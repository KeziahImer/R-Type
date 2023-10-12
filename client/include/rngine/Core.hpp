/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** Core definition
*/

#include <cstddef>
#include <immintrin.h>

#ifndef _RNGINE_CORE_HPP_
#define _RNGINE_CORE_HPP_

#include "./SceneManager.hpp"

namespace RNGine {
class Core {
public:
  void loop() {
    while (_running) {
      if (!manager.update())
        _running = false;
    }
  }
  void setRunning(bool running) { _running = running; };

  SceneManager manager = SceneManager();
  bool _running = true;
};
}; // namespace RNGine

#endif