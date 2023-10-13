/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** Core definition
*/


#ifndef _RNGINE_CORE_HPP_
#define _RNGINE_CORE_HPP_
  #include "client/Network.hpp"
  #include <cstddef>
  #include <immintrin.h>
  #include "./SceneManager.hpp"

namespace RNGine {
class Core {
  public:
    Core(){};
    ~Core() = default;

    void loop() {
      while (_running) {
        _running = manager.update();
      }
    }

    SceneManager manager = SceneManager();
    bool _running = true;
};
}; // namespace RNGine

#endif