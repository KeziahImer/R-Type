#include <iostream>
#include <string>

#include "addons/IsClicked.hpp"
#include "addons/IsHover.hpp"
#include "addons/OnHoverSprite.hpp"
#include "components/MousePosition.hpp"
#include "components/NumberLevels.hpp"
#include "components/NumberPlayers.hpp"
#include "components/RenderTexture.hpp"
namespace r {
#include "raylib.h"
}
#include "Rtype/addons/NetworkId.hpp"
#include "Rtype/addons/SendPacket.hpp"
#include "scenes/Home.hpp"
#include "scenes/LevelSelect.hpp"

Client::Scenes::LevelSelect::LevelSelect(RNGine::Core &core) {
  CreateEntity("background1");
  CreateEntity("background2");
  CreateEntity("redmoon");
  CreateEntity("greenmoon");
  core.AddSystem("on-click-button-start-level",
                 Client::Scenes::LevelSelect::OnClickButtonStart);
  core.AddSystem("on-click-button--level",
                 Client::Scenes::LevelSelect::OnClickButtonLevel);
  core.AddSystem("on-click-button-back-level",
                 Client::Scenes::LevelSelect::OnClickButtonback);
  CreateMouse();
  CreateButtonLevel(8);
  CreateButton("multiplayer", "./assets/menu/btn-infiniteGame", 100);
  CreateButton("back", "./assets/menu/btn-backtohome",
               r::GetScreenHeight() - 100);
  AddComponent(CreateEntity("numberLevels"),
               Client::Components::NumberLevel({8}));
}

void Client::Scenes::LevelSelect::CreateMouse() {
  CreateEntity("user-mouse");
  AddComponent("user-mouse", Client::Components::MousePosition());
  AddComponent("user-mouse",
               RNGine::Components::Transform({0, 0, 0, 0.1, 0.1}));
  AddComponent("user-mouse",
               Client::Components::RenderTexture(
                   {"./assets/cursor.png", 100, {0, 0, 317, 345}}));
}

void Client::Scenes::LevelSelect::CreateButton(const std::string &id,
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

void Client::Scenes::LevelSelect::CreateButtonLevel(int levelNumber) {
  for (int i = 0; i < levelNumber; i++) {
    auto entity = CreateEntity("button-" + std::to_string(i + 1));
    AddComponent(entity, Client::Components::MousePosition());
    AddComponent(entity, RNGine::Components::Transform(
                             {650.0f + 200.0f * i - ((i / 4) * 200.0f * 4),
                              (i / 4) * 200.0f + 400.0f, 0, 2, 2}));
    AddComponent(entity, RNGine::Components::Hitbox({88 * 2, 88 * 2, 88, 88}));
    AddComponent(entity, Client::Components::IsHover());
    AddComponent(entity, Client::Components::IsClicked());
    AddComponent(entity,
                 Client::Components::RenderTexture(
                     {"./assets/squareNumber.png", 10, {0, 0, 88, 88}}));
    AddComponent(
        entity,
        Client::Components::OnHoverSprite({Client::Components::RenderTexture(
            {"./assets/squareNumber.png", 10, {0, 0, 88, 88}})}));
  }
}

void Client::Scenes::LevelSelect::OnClickButtonLevel(RNGine::Core &core) {
  if (core.GetActualSceneName() != "LevelSelect")
    return;
  auto &scene = core.GetActualScene();
  auto &clicks = scene.GetComponents<Client::Components::IsClicked>();
  auto &transforms = scene.GetComponents<RNGine::Components::Transform>();
  auto &numberLevel =
      scene.GetComponents<Client::Components::NumberLevel>()[scene.GetEntity(
          "numberLevels")];
  auto &networkId =
      scene.GetComponents<Rtype::Components::networkId>()[scene.GetEntity(
          "networkId")];
  if (!numberLevel.has_value())
    return;
  for (int i = 0; i < numberLevel->numberLevel; i++) {
    auto entity = scene.GetEntity("button-" + std::to_string(i + 1));
    auto &click = clicks[entity];
    if (!click.has_value())
      continue;
    if (click->IsClickedLeft) {
      if (networkId.has_value()) {
        auto &sceneChange = core.GetScene("Level" + std::to_string(i + 1));
        auto entity = sceneChange.CreateEntity("sender");
        sceneChange.AddComponent<Client::Components::SendPacket>(entity, {});
        auto &packets =
            sceneChange.GetComponents<Client::Components::SendPacket>()[entity];
        packets->packets.push_back(
            {"CHANGE_SCENE", "Level" + std::to_string(i + 1)});
      }
      core.SetActualScene("Level" + std::to_string(i + 1));
      click->IsClickedLeft = false;
    }
  }
}

void Client::Scenes::LevelSelect::OnClickButtonStart(RNGine::Core &core) {
  if (core.GetActualSceneName() != "LevelSelect")
    return;
  auto &scene = core.GetActualScene();
  auto &clicks = scene.GetComponents<Client::Components::IsClicked>();
  auto &click = clicks[scene.GetEntity("button-multiplayer")];
  auto &networkId =
      scene.GetComponents<Rtype::Components::networkId>()[scene.GetEntity(
          "networkId")];

  if (click->IsClickedLeft) {
    if (networkId.has_value()) {
      auto &sceneChange = core.GetScene("game");
      auto entity = sceneChange.CreateEntity();
      sceneChange.AddComponent<Client::Components::SendPacket>(entity, {});
      auto &packets =
          sceneChange.GetComponents<Client::Components::SendPacket>()[entity];
      packets->packets.push_back({"CHANGE_SCENE", "game"});
    }
    core.SetActualScene("game");
    click->IsClickedLeft = false;
  }
}

void Client::Scenes::LevelSelect::OnClickButtonback(RNGine::Core &core) {
  if (core.GetActualSceneName() != "LevelSelect")
    return;
  auto &scene = core.GetActualScene();
  auto &clicks = scene.GetComponents<Client::Components::IsClicked>();
  auto &click = clicks[scene.GetEntity("button-back")];

  if (click->IsClickedLeft) {
    core.SetActualScene("home");
    click->IsClickedLeft = false;
  }
}