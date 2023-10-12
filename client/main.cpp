
#include <iostream>

#include "rngine/Scene.hpp"

int main() {
  RNGine::Scene scene("menu");
  scene.createEntity("button-solo");
  scene.createEntity("button-multiplayer");
  scene.createEntity("button-settings");

  return 0;
}
