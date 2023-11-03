#include <iostream>

#include "addons/IsClicked.hpp"
#include "addons/IsHover.hpp"
#include "addons/OnHoverSprite.hpp"
#include "components/MousePosition.hpp"
#include "components/Parallax.hpp"
#include "components/RenderTexture.hpp"
#include "scenes/Home.hpp"

#include "components/SendPacket.hpp"

Client::Scenes::Home::Home(RNGine::Core &core) {
  CreateEntity("background1");
  CreateEntity("background2");
  CreateEntity("redmoon");
  CreateEntity("greenmoon");
  core.AddSystem("track-mouse-position",
                 Client::Scenes::Home::TrackMousePositionSystem);
  core.AddSystem("on-click-button-solo",
                 Client::Scenes::Home::OnClickButtonSolo);
  core.AddSystem("on-click-button-multi",
                 Client::Scenes::Home::OnClickButtonMulti);
  /*core.AddSystem("set-background-texture-menu",
                 Client::Scenes::Home::SetBackgroundTextureMenu);*/
  CreateMouse();
  CreateTitle();
  CreateButton("solo", "./assets/menu/btn-solo", 0);
  CreateButton("multiplayer", "./assets/menu/btn-multiplayer", 100);
  CreateButton("settings", "./assets/menu/btn-settings", 200);
}

void Client::Scenes::Home::CreateTitle() {
  CreateEntity("title");
  float x = r::GetScreenWidth() / 2;
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
  float x = r::GetScreenWidth() / 2;
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
  if (core.GetActualSceneName() != "home" &&
      core.GetActualSceneName() != "lobby" &&
      core.GetActualSceneName() != "gameOver" &&
      core.GetActualSceneName() != "victory" &&
      core.GetActualSceneName() != "LevelSelect")
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
    core.SetActualScene("LevelSelect");
    click->IsClickedLeft = false;
  }
}

void Client::Scenes::Home::OnClickButtonMulti(RNGine::Core &core) {
  if (core.GetActualSceneName() != "home")
    return;
  auto &scene = core.GetActualScene();
  auto &clicks = scene.GetComponents<Client::Components::IsClicked>();
  auto &click = clicks[scene.GetEntity("button-multiplayer")];

  if (click->IsClickedLeft) {
    core.SetActualScene("lobby");
    auto &scene = core.GetActualScene();
    auto entity = scene.CreateEntity();
    scene.AddComponent<Client::Components::SendPacket>(entity, {});
    auto &packets =
        scene.GetComponents<Client::Components::SendPacket>()[entity];
    Network::AuthClientRequest request;
    request.type = Network::PacketType::AuthClientRequestType;
    packets->packets.push_back(request);
    click->IsClickedLeft = false;
  }
}

void Client::Scenes::Home::SetBackgroundTextureMenu(RNGine::Core &core) {
  auto name = core.GetActualSceneName();
  if (name != "lobby" && name != "victory" && name != "gameOver")
    return;
  auto &scene = core.GetActualScene();

  auto &textures = scene.GetComponents<Client::Components::RenderTexture>();

  auto background1 = scene.GetEntity("background1");
  auto background2 = scene.GetEntity("background2");
  auto redmoon = scene.GetEntity("redmoon");
  auto greenmoon = scene.GetEntity("greenmoon");

  auto alreadyExist1 =
      scene.GetComponents<Client::Components::RenderTexture>()[background1];
  auto alreadyExist2 =
      scene.GetComponents<Client::Components::RenderTexture>()[background2];
  auto alreadyExist5 =
      scene.GetComponents<Client::Components::RenderTexture>()[redmoon];
  auto alreadyExist6 =
      scene.GetComponents<Client::Components::RenderTexture>()[greenmoon];

  if (!alreadyExist1.has_value()) {
    scene.AddComponent<Client::Components::RenderTexture>(
        background1,
        {"./assets/levels/space/space_background.png", -3, {0, 0, 514, 360}});
    scene.AddComponent<RNGine::Components::Transform>(background1,
                                                      {0, 0, 0, 3.73, 3});
    scene.AddComponent<Client::Components::Parallax>(background1,
                                                     {{-1920, 1920}});
    scene.AddComponent(background1, RNGine::Addons::Velocity({-100, 0}));
  }
  if (!alreadyExist2.has_value()) {
    scene.AddComponent<Client::Components::RenderTexture>(
        background2,
        {"./assets/levels/space/space_background.png", -3, {0, 0, 514, 360}});
    scene.AddComponent<RNGine::Components::Transform>(background2,
                                                      {1920, 0, 0, 3.73, 3});
    scene.AddComponent<Client::Components::Parallax>(background2,
                                                     {{-1920, 1920}});
    scene.AddComponent(background2, RNGine::Addons::Velocity({-100, 0}));
  }

  if (!alreadyExist5.has_value()) {
    scene.AddComponent<Client::Components::RenderTexture>(
        redmoon,
        {"./assets/levels/space/moon/moon_blue.png", -1, {0, 0, 200, 200}});
    scene.AddComponent<RNGine::Components::Transform>(redmoon,
                                                      {1920, 920, 0, 1, 1});
    scene.AddComponent<Client::Components::Parallax>(redmoon, {{-1920, 1920}});
    scene.AddComponent(redmoon, RNGine::Addons::Velocity({-200, 0}));
  }
  if (!alreadyExist6.has_value()) {
    scene.AddComponent<Client::Components::RenderTexture>(
        greenmoon,
        {"./assets/levels/space/moon/moon_green.png", -1, {0, 0, 200, 200}});
    scene.AddComponent<RNGine::Components::Transform>(greenmoon,
                                                      {3920, 50, 0, 1, 1});
    scene.AddComponent<Client::Components::Parallax>(greenmoon,
                                                     {{-1920, 1920}});
    scene.AddComponent(greenmoon, RNGine::Addons::Velocity({-200, 0}));
  }
}
