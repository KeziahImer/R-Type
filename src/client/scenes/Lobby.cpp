#include <iostream>

#include "Rtype/addons/NetworkId.hpp"
#include "addons/IsClicked.hpp"
#include "addons/IsHover.hpp"
#include "addons/OnHoverSprite.hpp"
#include "components/MousePosition.hpp"
#include "components/NumberPlayers.hpp"
#include "components/RenderTexture.hpp"
namespace r {
#include "raylib.h"
}
#include "scenes/Home.hpp"
#include "scenes/Lobby.hpp"

Client::Scenes::Lobby::Lobby(RNGine::Core &core) {
  CreateEntity("background1");
  CreateEntity("background2");
  CreateEntity("redmoon");
  CreateEntity("greenmoon");
  core.AddSystem("on-click-button-start",
                 Client::Scenes::Lobby::OnClickButtonStart);
  core.AddSystem("on-click-button-back",
                 Client::Scenes::Lobby::OnClickButtonback);
  core.AddSystem("render-players-number", Client::Scenes::Lobby::renderPlayers);
  CreateMouse();
  CreateButton("multiplayer", "./assets/menu/btn-start",
               r::GetScreenHeight() / 2);
  CreateButton("back", "./assets/menu/btn-backtohome",
               r::GetScreenHeight() / 2 + 100);
  AddComponent(CreateEntity("numberPLayers"),
               Client::Components::NumberPlayers());
}

void Client::Scenes::Lobby::CreateMouse() {
  CreateEntity("user-mouse");
  AddComponent("user-mouse", Client::Components::MousePosition());
  AddComponent("user-mouse",
               RNGine::Components::Transform({0, 0, 0, 0.1, 0.1}));
  AddComponent("user-mouse",
               Client::Components::RenderTexture(
                   {"./assets/cursor.png", 100, {0, 0, 317, 345}}));
}

void Client::Scenes::Lobby::CreateButton(const std::string &id,
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

void Client::Scenes::Lobby::OnClickButtonStart(RNGine::Core &core) {
  if (core.GetActualSceneName() != "lobby")
    return;
  auto &scene = core.GetActualScene();
  auto &clicks = scene.GetComponents<Client::Components::IsClicked>();
  auto &click = clicks[scene.GetEntity("button-multiplayer")];

  if (click->IsClickedLeft) {
    core.SetActualScene("LevelSelect");
    click->IsClickedLeft = false;
  }
}

void Client::Scenes::Lobby::OnClickButtonback(RNGine::Core &core) {
  if (core.GetActualSceneName() != "lobby")
    return;
  auto &scene = core.GetActualScene();
  auto &clicks = scene.GetComponents<Client::Components::IsClicked>();
  auto &click = clicks[scene.GetEntity("button-back")];

  if (click->IsClickedLeft) {
    core.SetActualScene("home");
    click->IsClickedLeft = false;
  }
}

void Client::Scenes::Lobby::renderPlayers(RNGine::Core &core) {
  if (core.GetActualSceneName() != "lobby")
    return;
  auto &scene = core.GetActualScene();
  auto &numberPlayers =
      scene.GetComponents<Client::Components::NumberPlayers>()[scene.GetEntity(
          "numberPLayers")];
  if (!numberPlayers.has_value())
    return;
  auto &networkId = scene.GetComponents<Rtype::Components::networkId>();
  for (int i = 0; i < networkId.size(); i++) {
    if (!networkId[i].has_value())
      continue;
    numberPlayers->numberPlayers = networkId[i]->id;
    auto &checkNetwork =
        core.GetScene("LevelSelect")
            .GetComponents<Rtype::Components::networkId>()
                [core.GetScene("LevelSelect").GetEntity("networkId")];
    if (checkNetwork.has_value())
      continue;
    core.GetScene("LevelSelect")
        .AddComponent<Rtype::Components::networkId>(
            core.GetScene("LevelSelect").CreateEntity("networkId"),
            {networkId[i]->id});
    core.GetScene("game").AddComponent<Rtype::Components::networkId>(
        core.GetScene("game").CreateEntity("networkId"), {networkId[i]->id});
    core.GetScene("Level1").AddComponent<Rtype::Components::networkId>(
        core.GetScene("Level1").CreateEntity("networkId"), {networkId[i]->id});
    core.GetScene("Level2").AddComponent<Rtype::Components::networkId>(
        core.GetScene("Level2").CreateEntity("networkId"), {networkId[i]->id});
    core.GetScene("Level3").AddComponent<Rtype::Components::networkId>(
        core.GetScene("Level3").CreateEntity("networkId"), {networkId[i]->id});
    core.GetScene("Level8").AddComponent<Rtype::Components::networkId>(
        core.GetScene("Level8").CreateEntity("networkId"), {networkId[i]->id});
    core.GetScene("Level4").AddComponent<Rtype::Components::networkId>(
        core.GetScene("Level4").CreateEntity("networkId"), {networkId[i]->id});
    core.GetScene("Level5").AddComponent<Rtype::Components::networkId>(
        core.GetScene("Level5").CreateEntity("networkId"), {networkId[i]->id});
    core.GetScene("Level6").AddComponent<Rtype::Components::networkId>(
        core.GetScene("Level6").CreateEntity("networkId"), {networkId[i]->id});
    core.GetScene("Level7").AddComponent<Rtype::Components::networkId>(
        core.GetScene("Level7").CreateEntity("networkId"), {networkId[i]->id});
  }
  std::string toPrint;
  if (numberPlayers->numberPlayers == 0) {
    toPrint = "Connecting...";
  } else {
    toPrint = "PlayerID: " + std::to_string(numberPlayers->numberPlayers);
  }
  r::DrawText(toPrint.c_str(), r::GetScreenWidth() - 250,
              r::GetScreenHeight() - 50, 40, r::LIGHTGRAY);
}