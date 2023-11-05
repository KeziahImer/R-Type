#include "Server.hpp"
#include "Network/Packet.hpp"
#include "RNGine/Scene.hpp"
#include "RNGine/addons/Acceleration.hpp"
#include "RNGine/addons/Velocity.hpp"
#include "RNGine/addons/destroyLimit.hpp"
#include "RNGine/components/Damages.hpp"
#include "RNGine/components/Transform.hpp"
#include "Rtype/addons/CreateShips.hpp"
#include "Rtype/addons/EnemyWaveSpawn.hpp"
#include "Rtype/addons/IsNetwork.hpp"
#include "Rtype/addons/MakeDamage.hpp"
#include "Rtype/addons/NetworkId.hpp"
#include "Rtype/addons/SendPacket.hpp"
#include "Rtype/addons/ShipController.hpp"
#include <cstddef>
#include <cstring>

void Server::Core::Update(RNGine::Core &core) {
  // PurgeReceptions();
  Poll();
  SendPackets(core);
  Auth(core);

  if (lastSend != 0.0f && core.currentTime - lastSend > 1.0) {
    lastSend = core.currentTime;
    for (auto &client : _clients) {
      Send(client.first, "PING", "");
    }
  }
}

void Server::Core::SendPackets(RNGine::Core &core) {
  auto &scene = core.GetActualScene();
  auto &components = scene.GetComponents<Client::Components::SendPacket>();
  for (auto &component : components) {
    if (component.has_value()) {
      auto &packets = component->packets;
      for (auto packet : packets) {
        _lastSend = core.currentTime;
        for (auto endpoint : _clients) {
          Send(endpoint.first, packet.first, packet.second);
        }
      }
      packets.clear();
    }
  }
}

void Server::Core::PurgeReceptions() {
  for (auto &reception : received) {
    auto &packets = reception.second;
    if (packets.empty())
      continue;
    auto lastId = packets.rbegin()->first;
    auto lastIdSurvived = lastId - 64;
    if (lastIdSurvived <= 0)
      continue;
    for (int i = 1; i <= lastIdSurvived; i++) {
      packets.erase(i);
    }
  }
}

void Server::Core::Auth(RNGine::Core &core) {
  for (auto &reception : received) {
    auto packets = reception.second;
    auto endpoint = reception.first;

    for (auto packet : packets) {
      auto id = packet.first;
      auto content = packet.second;

      if (_reads[endpoint][id] || !content.has_value())
        continue;

      _reads[endpoint][id] = true;
      if (content->GetType() == "MOVE_UP") {
        auto args = Network::Packet::Split(content->GetData(), ":");
        float y = std::stof(args.back());
        args.pop_back();
        float x = std::stof(args.back());
        args.pop_back();
        std::string str = args.back();
        args.pop_back();
        bool move = false;
        if (str == "TRUE") {
          move = true;
        }
        auto entity = core.GetActualScene().GetEntity("ship-" + args.back());
        auto &controller =
            core.GetActualScene()
                .GetComponents<Rtype::Addons::ShipController>()[entity];
        auto &transform =
            core.GetActualScene()
                .GetComponents<RNGine::Components::Transform>()[entity];
        if (!controller.has_value()) {
          std::cout << "controller has no value" << std::endl;
          continue;
        }
        if (!transform.has_value()) {
          std::cout << "transform has no value" << std::endl;
          continue;
        }
        int id = std::stoi(args.back());
        args.pop_back();
        for (auto &client : _clients) {
          Send(client.first, "MOVE_UP", content->GetData());
        }
        controller->movingUp = move;
        transform->x = x;
        transform->y = y;
        continue;
      }
      if (content->GetType() == "MOVE_LEFT") {
        auto args = Network::Packet::Split(content->GetData(), ":");
        float y = std::stof(args.back());
        args.pop_back();
        float x = std::stof(args.back());
        args.pop_back();
        std::string str = args.back();
        args.pop_back();
        bool move = false;
        if (str == "TRUE") {
          move = true;
        }
        auto entity = core.GetActualScene().GetEntity("ship-" + args.back());
        auto &controller =
            core.GetActualScene()
                .GetComponents<Rtype::Addons::ShipController>()[entity];
        auto &transform =
            core.GetActualScene()
                .GetComponents<RNGine::Components::Transform>()[entity];
        if (!controller.has_value()) {
          std::cout << "controller has no value" << std::endl;
          continue;
        }
        if (!transform.has_value()) {
          std::cout << "transform has no value" << std::endl;
          continue;
        }
        int id = std::stoi(args.back());
        args.pop_back();
        for (auto &client : _clients) {
          Send(client.first, "MOVE_LEFT", content->GetData());
        }
        controller->movingLeft = move;
        transform->x = x;
        transform->y = y;
        continue;
      }
      if (content->GetType() == "MOVE_RIGHT") {
        auto args = Network::Packet::Split(content->GetData(), ":");
        float y = std::stof(args.back());
        args.pop_back();
        float x = std::stof(args.back());
        args.pop_back();
        std::string str = args.back();
        args.pop_back();
        bool move = false;
        if (str == "TRUE") {
          move = true;
        }
        std::cout << "MOVE RIGHT CHECK CONTROLLE: "
                  << "ship-" + args.back() << std::endl;
        auto entity = core.GetActualScene().GetEntity("ship-" + args.back());
        auto &controller =
            core.GetActualScene()
                .GetComponents<Rtype::Addons::ShipController>()[entity];
        auto &transform =
            core.GetActualScene()
                .GetComponents<RNGine::Components::Transform>()[entity];
        if (!controller.has_value()) {
          std::cout << "controller has no value" << std::endl;
          continue;
        }
        if (!transform.has_value()) {
          std::cout << "transform has no value" << std::endl;
          continue;
        }
        int id = std::stoi(args.back());
        args.pop_back();
        for (auto &client : _clients) {
          Send(client.first, "MOVE_RIGHT", content->GetData());
        }
        controller->movingRight = move;
        transform->x = x;
        transform->y = y;
        continue;
      }
      if (content->GetType() == "MOVE_DOWN") {
        auto args = Network::Packet::Split(content->GetData(), ":");
        float y = std::stof(args.back());
        args.pop_back();
        float x = std::stof(args.back());
        args.pop_back();
        std::string str = args.back();
        args.pop_back();
        bool move = false;
        if (str == "TRUE") {
          move = true;
        }
        auto entity = core.GetActualScene().GetEntity("ship-" + args.back());
        auto &controller =
            core.GetActualScene()
                .GetComponents<Rtype::Addons::ShipController>()[entity];
        auto &transform =
            core.GetActualScene()
                .GetComponents<RNGine::Components::Transform>()[entity];
        if (!controller.has_value()) {
          std::cout << "controller has no value" << std::endl;
          continue;
        }
        if (!transform.has_value()) {
          std::cout << "transform has no value" << std::endl;
          continue;
        }
        int id = std::stoi(args.back());
        args.pop_back();
        for (auto &client : _clients) {
          Send(client.first, "MOVE_DOWN", content->GetData());
        }
        controller->movingDown = move;
        transform->x = x;
        transform->y = y;
        continue;
      }
      if (content->GetType() == "AUTH_REQUEST") {
        if (_clients.size() >= 4) {
          Send(endpoint, "ERROR", "Maximum player reached !");
          continue;
        }
        int client_id = _clients.size() + 1;
        std::cout << "Sended controlled id: " << client_id << std::endl;
        _clients[endpoint] = client_id;
        Send(endpoint, "AUTH_RESPONSE", std::to_string(client_id));
        continue;
      }
      if (content->GetType() == "CHANGE_SCENE") {
        auto &components =
            core.GetScene(content->GetData())
                .GetComponents<Client::Components::SendPacket>()
                    [core.GetScene(content->GetData()).GetEntity("sender")];
        if (components.has_value()) {
          components->packets.push_back({"SWITCH_SCENE", content->GetData()});
        }
        auto &ships = core.GetScene(content->GetData())
                          .GetComponents<Rtype::Addons::CreateShips>()
                              [core.GetScene(content->GetData())
                                   .GetEntity("createShips")];
        if (ships.has_value()) {
          ships->nbrPlayers = _clients.size();
        }
        core.SetActualScene(content->GetData());
        std::cout << "SWITCH TO " << content->GetData() << std::endl;
        continue;
      }
      if (content->GetType() == "DEATH") {
        auto &components = core.GetActualScene()
                               .GetComponents<Client::Components::SendPacket>()
                                   [core.GetActualScene().GetEntity("sender")];
        auto &controllers =
            core.GetActualScene().GetComponents<Rtype::Addons::ShipFactory>();
        auto &waves = core.GetActualScene()
                          .GetComponents<Client::Components::EnemyWaveSpawn>();
        if (controllers[core.GetActualScene().GetEntity(content->GetData())]
                .has_value() ||
            waves[core.GetActualScene().GetEntity(content->GetData())]
                .has_value())
          continue;
        if (components.has_value()) {
          components->packets.push_back({"DEATH", content->GetData()});
        }
        if (content->GetData() == "")
          continue;
        core.GetActualScene().RemoveEntity(
            core.GetActualScene().GetEntity(content->GetData()));
        continue;
      }
      if (content->GetType() == "SHOOT") {
        auto &scene = core.GetActualScene();
        auto &transforms = scene.GetComponents<RNGine::Components::Transform>();
        auto &hitboxs = scene.GetComponents<RNGine::Components::Hitbox>();
        auto &damages = scene.GetComponents<RNGine::Components::Damages>();
        auto &isNetwork =
            scene.GetComponents<Rtype::Components::IsNetwork>()[scene.GetEntity(
                "network")];
        auto &networkId = scene.GetComponents<Rtype::Components::networkId>();
        auto &sender = scene.GetComponents<
            Client::Components::SendPacket>()[scene.GetEntity("sender")];
        auto args = Network::Packet::Split(content->GetData(), ":");
        std::string type = args.back();
        args.pop_back();
        int chargedValue = 0;
        if (type == "CHARGED") {
          chargedValue = std::stoi(args.back());
          args.pop_back();
        }
        int id = std::stoi(args.back());
        args.pop_back();
        RNGine::Scene::Entity entity = 0;
        std::cout << _clients.size() << std::endl;
        for (auto &client : _clients) {
          Send(client.first, "SHOOT", content->GetData());
        }
        for (int i = 0; i < networkId.size(); i++) {
          if (!networkId[i].has_value())
            continue;
          if (id == networkId[i]->id) {
            entity = i;
          }
        }
        auto &transform = transforms[entity];
        if (type == "BASIC" && transform.has_value() &&
            hitboxs[entity].has_value() && damages[entity].has_value()) {
          auto shoot = scene.CreateEntity();
          scene.AddComponent<RNGine::Components::Transform>(
              shoot,
              {transform->x + hitboxs[entity]->width, transform->y, 0, 2, 2});
          scene.AddComponent(
              shoot, RNGine::Components::Hitbox({32 * 2, 10 * 2, 0, 0}));
          scene.AddComponent(
              shoot, RNGine::Addons::Collider(
                         {false, RNGine::Addons::CollisionAction::Explosion}));
          scene.AddComponent(shoot, RNGine::Addons::Velocity({1200, 0}));
          scene.AddComponent<RNGine::Components::MakeDamage>(
              shoot, {damages[entity]->damages, true, entity});
          scene.AddComponent<RNGine::Addons::destroyLimit>(shoot, {-100, 2020});
        } else if (type == "LASER" && transform.has_value() &&
                   hitboxs[entity].has_value() && damages[entity].has_value()) {
          auto shoot = scene.CreateEntity();
          scene.AddComponent<RNGine::Components::Transform>(
              shoot, {transform->x + hitboxs[entity]->width, transform->y - 30,
                      0, 2, 2});
          scene.AddComponent(
              shoot, RNGine::Components::Hitbox({32 * 2, 10 * 2, 0, 0}));
          scene.AddComponent(
              shoot, RNGine::Addons::Collider(
                         {false, RNGine::Addons::CollisionAction::None}));
          scene.AddComponent(shoot, RNGine::Addons::Velocity({2000, 0}));
          scene.AddComponent<RNGine::Components::MakeDamage>(
              shoot, {damages[entity]->damages + 20,
                      true,
                      entity,
                      "./assets/beam.png",
                      {91.0f, 0.0f},
                      {91.0f, 48.0f},
                      "./assets/sounds/beam.wav"});
          scene.AddComponent<RNGine::Addons::destroyLimit>(shoot, {-100, 2020});
        } else if (type == "CHARGED" && transform.has_value() &&
                   hitboxs[entity].has_value() && damages[entity].has_value()) {
          auto shoot = scene.CreateEntity();
          float scale = 2;
          int damageMultiple = 1;
          if (chargedValue == 2) {
            scale = 3;
            damageMultiple = 2;
          }
          if (chargedValue == 3) {
            scale = 4.5;
            damageMultiple = 3;
          }
          if (chargedValue == 4) {
            scale = 6;
            damageMultiple = 4;
          }
          scene.AddComponent(
              shoot, RNGine::Addons::Collider(
                         {false, RNGine::Addons::CollisionAction::Explosion}));
          scene.AddComponent(shoot, RNGine::Addons::Velocity({1200, 0}));
          scene.AddComponent<RNGine::Addons::destroyLimit>(shoot, {-100, 2020});
          scene.AddComponent<RNGine::Components::Transform>(
              shoot, {transform->x + hitboxs[entity]->width, transform->y, 0,
                      scale, scale});
          scene.AddComponent(shoot, RNGine::Components::Hitbox(
                                        {33 * scale, 33 * scale, 0, 0}));
          scene.AddComponent<RNGine::Components::MakeDamage>(
              shoot, {damages[entity]->damages * damageMultiple, true, entity});
        }
        continue;
      }
    }
  }
}
