#include <iostream>

#include "components/IsClicked.hpp"
#include "components/IsHover.hpp"
#include "components/MousePosition.hpp"
#include "components/OnHoverSprite.hpp"
#include "components/RenderTexture.hpp"
#include "scenes/Home.hpp"

Client::Scenes::Home::Home(RNGine::Core &core) {
  core.AddSystem("track-mouse-position",
                 Client::Scenes::Home::TrackMousePositionSystem);
  core.AddSystem("on-click-button-solo",
                 Client::Scenes::Home::OnClickButtonSolo);
  CreateMouse();
  CreateTitle();
  CreateButton("solo", "./assets/menu/btn-solo", 0);
  CreateButton("multiplayer", "./assets/menu/btn-multiplayer", 100);
  CreateButton("settings", "./assets/menu/btn-settings", 200);
}

void Client::Scenes::Home::CreateTitle() {
  CreateEntity("title");
  float x = GetScreenWidth() / 2;
  float y = 300;
  AddComponent("title", RNGine::Components::Transform({x, y, 0, 1, 1}));
  AddComponent("title",
               RNGine::Components::Hitbox({500, 146, 500 / 2, 146 / 2}));
  AddComponent("title", Client::Components::RenderTexture(
                            {"./assets/menu/title.png", 10, {0, 0, 500, 146}}));
}

void Client::Scenes::Home::CreateMouse() {
  CreateEntity("user-mouse");
  AddComponent("user-mouse", Client::Components::MousePosition());
  AddComponent("user-mouse",
               RNGine::Components::Transform({0, 0, 0, 0.1, 0.1}));
  AddComponent("user-mouse",
               Client::Components::RenderTexture(
                   {"./assets/cursor.png", 100, {0, 0, 317, 345}}));
}

void Client::Scenes::Home::CreateButton(const std::string &id,
                                        const std::string &sprite,
                                        float marginTop) {
  auto entity = CreateEntity("button-" + id);
  AddComponent(entity, Client::Components::MousePosition());
  float x = GetScreenWidth() / 2;
  float y = 500 + marginTop;
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

void Client::Scenes::Home::TrackMousePositionSystem(RNGine::Core &core) {
  if (core.GetActualSceneName() != "home")
    return;
  auto &scene = core.GetActualScene();
  auto &mouses = scene.GetComponents<Client::Components::MousePosition>();
  auto &transforms = scene.GetComponents<RNGine::Components::Transform>();
  auto &mouse = mouses[scene.GetEntity("user-mouse")];
  auto &transform = transforms[scene.GetEntity("user-mouse")];

  transform->x = mouse->position.x;
  transform->y = mouse->position.y;
}

void Client::Scenes::Home::OnClickButtonSolo(RNGine::Core &core) {
  if (core.GetActualSceneName() != "home")
    return;
  auto &scene = core.GetActualScene();
  auto &clicks = scene.GetComponents<Client::Components::IsClicked>();
  auto &click = clicks[scene.GetEntity("button-solo")];

  if (click->IsClickedLeft) {
    core.SetActualScene("game");
    click->IsClickedLeft = false;
  }
}
