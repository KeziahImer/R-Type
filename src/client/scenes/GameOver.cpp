#include <iostream>

#include "addons/IsClicked.hpp"
#include "addons/IsHover.hpp"
#include "addons/OnHoverSprite.hpp"
#include "components/MousePosition.hpp"
#include "components/NumberPlayers.hpp"
#include "components/RenderTexture.hpp"
namespace r
{
#include "raylib.h"
}
#include "scenes/Game.hpp"
#include "scenes/GameOver.hpp"
#include "scenes/Level1.hpp"
#include "scenes/Level2.hpp"
#include "scenes/Level3.hpp"
#include "scenes/Level4.hpp"
#include "scenes/Level5.hpp"
#include "scenes/Level6.hpp"
#include "scenes/Level7.hpp"
#include "scenes/Level8.hpp"

Client::Scenes::GameOver::GameOver(RNGine::Core &core) {
  CreateEntity("background1");
  CreateEntity("background2");
  CreateEntity("redmoon");
  CreateEntity("greenmoon");
  core.AddSystem("on-click-button-retry",
                 Client::Scenes::GameOver::OnClickButtonRetry);
  core.AddSystem("on-click-button-backHome",
                 Client::Scenes::GameOver::OnClickButtonBackHome);
  core.AddSystem("render-gameover", Client::Scenes::GameOver::renderGameOver);
  CreateMouse();
  CreateButton("retry", "./assets/menu/loose/btn-retry", r::GetScreenHeight() / 2);
  CreateButton("back", "./assets/menu/loose/btn-backtohome",
               r::GetScreenHeight() / 2 + 100);
  AddComponent(CreateEntity("numberPLayers"),
               Client::Components::NumberPlayers());
}

void Client::Scenes::GameOver::CreateMouse() {
  CreateEntity("user-mouse");
  AddComponent("user-mouse", Client::Components::MousePosition());
  AddComponent("user-mouse",
               RNGine::Components::Transform({0, 0, 0, 0.1, 0.1}));
  AddComponent("user-mouse",
               Client::Components::RenderTexture(
                   {"./assets/cursor.png", 100, {0, 0, 317, 345}}));
}

void Client::Scenes::GameOver::CreateButton(const std::string &id,
                                            const std::string &sprite,
                                            float marginTop) {
  auto entity = CreateEntity("button-" + id);
  AddComponent(entity, Client::Components::MousePosition());
  float x = r::GetScreenWidth() / 2;
  float y = marginTop;
  AddComponent(entity, RNGine::Components::Transform({x, y, 0, 1, 1}));
  AddComponent(entity, RNGine::Components::Hitbox({674, 88, 674 / 2, 88 / 2}));
  AddComponent(entity, Client::Components::IsHover());
  AddComponent(entity, Client::Components::IsClicked());
  AddComponent(entity, Client::Components::RenderTexture(
                           {sprite + ".png", 10, {0, 0, 674, 88}}));
  AddComponent(entity, Client::Components::OnHoverSprite(
                           {Client::Components::RenderTexture(
                               {sprite + "-hover.png", 10, {0, 0, 674, 88}})}));
}

void Client::Scenes::GameOver::OnClickButtonRetry(RNGine::Core &core) {
  if (core.GetActualSceneName() != "gameOver")
    return;
  auto &scene = core.GetActualScene();
  auto &clicks = scene.GetComponents<Client::Components::IsClicked>();
  auto &click = clicks[scene.GetEntity("button-retry")];

  if (click->IsClickedLeft) {
    core.RemoveScene("Level1");
    core.RemoveScene("Level2");
    core.RemoveScene("Level3");
    core.RemoveScene("Level4");
    core.RemoveScene("Level5");
    core.RemoveScene("Level6");
    core.RemoveScene("Level7");
    core.RemoveScene("Level8");
    core.RemoveScene("game");
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
    core.SetActualScene("LevelSelect");
    click->IsClickedLeft = false;
  }
}

void Client::Scenes::GameOver::OnClickButtonBackHome(RNGine::Core &core) {
  if (core.GetActualSceneName() != "gameOver")
    return;
  auto &scene = core.GetActualScene();
  auto &clicks = scene.GetComponents<Client::Components::IsClicked>();
  auto &click = clicks[scene.GetEntity("button-back")];

  if (click->IsClickedLeft) {
    core.RemoveScene("Level1");
    core.RemoveScene("Level2");
    core.RemoveScene("Level3");
    core.RemoveScene("Level4");
    core.RemoveScene("Level5");
    core.RemoveScene("Level6");
    core.RemoveScene("Level7");
    core.RemoveScene("Level8");
    core.RemoveScene("game");
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
    core.SetActualScene("home");
    click->IsClickedLeft = false;
  }
}

void Client::Scenes::GameOver::renderGameOver(RNGine::Core &core) {
  if (core.GetActualSceneName() != "gameOver")
    return;
  auto &scene = core.GetActualScene();
  std::string toPrint = "GAMEOVER";
  r::DrawText(toPrint.c_str(), r::GetScreenWidth() / 2 - 400, 50, 150, r::RED);
}