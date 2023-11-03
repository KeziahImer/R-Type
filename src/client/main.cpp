#include <algorithm>
#include <iostream>
#include <map>

#include "Networker.hpp"
#include "Rtype/Core.hpp"
namespace r {
#include "raylib.h"
}
#include "Renderer.hpp"
#include "SetMousePosition.hpp"
#include "SoundRenderer.hpp"
#include "TextRenderer.hpp"
#include "addons/IsClicked.hpp"
#include "addons/IsHover.hpp"
#include "addons/OnHoverSprite.hpp"
#include "addons/SpriteAnimation.hpp"
#include "components/Parallax.hpp"
#include "components/RenderTexture.hpp"

#include "scenes/Game.hpp"
#include "scenes/GameOver.hpp"
#include "scenes/Home.hpp"
#include "scenes/Level1.hpp"
#include "scenes/Level2.hpp"
#include "scenes/Level3.hpp"
#include "scenes/Level4.hpp"
#include "scenes/Level5.hpp"
#include "scenes/Level6.hpp"
#include "scenes/Level7.hpp"
#include "scenes/Level8.hpp"
#include "scenes/LevelSelect.hpp"
#include "scenes/Lobby.hpp"
#include "scenes/Victory.hpp"

int main() {
  r::InitWindow(1920, 1080, "Super Mega Rtype");
  r::InitAudioDevice();
  r::SetMasterVolume(100);
  r::ToggleFullscreen();
  r::DisableCursor();

  Client::Renderer renderer;
  Client::SoundRenderer soundRenderer;
  Client::TextRenderer textRenderer;
  Client::Networker networker;

  RNGine::Core core;
  Client::Scenes::Home home(core);
  core.AddScene("home", home);
  Client::Scenes::Game game(core);
  core.AddScene("game", game);
  Client::Scenes::Level1 level1(core);
  core.AddScene("Level1", level1);
  Client::Scenes::Level2 level2(core);
  core.AddScene("Level2", level2);
  Client::Scenes::Level3 level3(core);
  core.AddScene("Level3", level3);
  Client::Scenes::Level4 level4(core);
  core.AddScene("Level4", level4);
  Client::Scenes::Level5 level5(core);
  core.AddScene("Level5", level5);
  Client::Scenes::Level6 level6(core);
  core.AddScene("Level6", level6);
  Client::Scenes::Level7 level7(core);
  core.AddScene("Level7", level7);
  Client::Scenes::Level8 level8(core);
  core.AddScene("Level8", level8);
  Client::Scenes::Lobby lobby(core);
  core.AddScene("lobby", lobby);
  Client::Scenes::LevelSelect levelSelect(core);
  core.AddScene("LevelSelect", levelSelect);
  Client::Scenes::GameOver gameOver(core);
  core.AddScene("gameOver", gameOver);
  Client::Scenes::Victory victory(core);
  core.AddScene("victory", victory);
  core.SetActualScene("home");

  core.AddSystem("OnHoverSpriteSystem",
                 Client::Components::OnHoverSpriteSystem);
  core.AddSystem("IsHoverSystem", Client::Components::IsHoverSystem);
  core.AddSystem("IsClickedSystem", Client::Components::IsClickedSystem);
  core.AddSystem("SpriteAnimationSystem",
                 Client::Components::SpriteAnimationSystem);
  core.AddSystem("ParallaxSystem", Client::Components::ParallaxSystem);

  while (!r::WindowShouldClose()) {
    if (!core.Update())
      continue;
    r::BeginDrawing();
    renderer.RenderSprites(core.GetActualScene());
    soundRenderer.UpdateSounds(core.GetActualScene());
    textRenderer.UpdateTexts(core.GetActualScene());
    Client::SetMousePosition(core.GetActualScene());
    r::EndDrawing();
    networker.Update(core);
  }

  r::CloseAudioDevice();
  r::CloseWindow();

  return 0;
}
