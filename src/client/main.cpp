#include <algorithm>
#include <iostream>
#include <map>

#include "Rtype/Core.hpp"
#include "raylib.h"

#include "Renderer.hpp"
#include "SetMousePosition.hpp"
#include "components/IsClicked.hpp"
#include "components/IsHover.hpp"
#include "components/OnHoverSprite.hpp"
#include "components/RenderTexture.hpp"

#include "scenes/Game.hpp"
#include "scenes/Home.hpp"

int main() {
  InitWindow(1920, 1080, "Super Mega Rtype");
  ToggleFullscreen();
  DisableCursor();

  Client::Renderer renderer;

  RNGine::Core core;
  Client::Scenes::Home home(core);
  Client::Scenes::Game game(core);
  core.AddScene("home", home);
  core.AddScene("game", game);
  core.SetActualScene("home");

  core.AddSystem("OnHoverSpriteSystem",
                 Client::Components::OnHoverSpriteSystem);
  core.AddSystem("IsHoverSystem", Client::Components::IsHoverSystem);
  core.AddSystem("IsClickedSystem", Client::Components::IsClickedSystem);

  while (!WindowShouldClose()) {
    if (!core.Update())
      continue;
    renderer.RenderSprites(core.GetActualScene());
    Client::SetMousePosition(core.GetActualScene());
  }

  CloseWindow();

  return 0;
}
