#include "Networker.hpp"
#include "Network/Packet.hpp"
#include "RNGine/Scene.hpp"
#include "RNGine/addons/Acceleration.hpp"
#include "RNGine/addons/Velocity.hpp"
#include "RNGine/addons/destroyLimit.hpp"
#include "RNGine/components/Damages.hpp"
#include "Rtype/addons/CollisionFactory.hpp"
#include "Rtype/addons/EnemyFactory.hpp"
#include "Rtype/addons/IsNetwork.hpp"
#include "Rtype/addons/MakeDamage.hpp"
#include "Rtype/addons/NetworkId.hpp"
#include "Rtype/addons/SendPacket.hpp"
#include "Rtype/addons/ShipController.hpp"
#include "Rtype/addons/ShipFactory.hpp"
#include "scenes/Game.hpp"
#include <string>

Client::Networker::Networker() : Engine(0) {
  _server = Resolve("localhost", "4242");
}

void Client::Networker::Update(RNGine::Core &core) {
  Poll();
  ReceivePackets(core);
  SendPackets(core);
  router(core);
}

void Client::Networker::ReceivePackets(RNGine::Core &core) {
  auto name = core.GetActualSceneName();
  if (name == "lobby") {
    WaitAuthResponse(core);
    return;
  }
}

void Client::Networker::SendPackets(RNGine::Core &core) {
  auto &scene = core.GetActualScene();
  auto &components = scene.GetComponents<Client::Components::SendPacket>();
  for (auto &component : components) {
    if (component.has_value()) {
      auto &packets = component->packets;
      for (auto packet : packets) {
        Send(_server, packet.first, packet.second);
      }
      packets.clear();
    }
  }
  if (lastSend != 0.0f && core.currentTime - lastSend > 1.0) {
    lastSend = core.currentTime;
    Send(_server, "PING", "");
  }
}

void Client::Networker::WaitAuthResponse(RNGine::Core &core) {
  auto &scene = core.GetActualScene();
  for (auto &reception : received) {
    auto packets = reception.second;
    auto endpoint = reception.first;

    for (auto packet : packets) {
      auto id = packet.first;
      auto content = packet.second;

      if (_reads[endpoint][id] || !content.has_value())
        continue;

      _reads[endpoint][id] = true;

      if (content->GetType() != "AUTH_RESPONSE")
        continue;
      auto idClient = std::stoi(content->GetData());
      std::cout << "ID: " << idClient << std::endl;
      scene.AddComponent<Rtype::Components::networkId>(
          scene.CreateEntity("networkId"), {idClient});
    }
  }
}

void Client::Networker::router(RNGine::Core &core) {
  auto &scene = core.GetActualScene();
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
        auto &networkId =
            scene.GetComponents<Rtype::Components::networkId>()[scene.GetEntity(
                "networkId")];
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
        if (networkId.has_value() && id == networkId->id)
          continue;
        controller->movingUp = move;
        transform->x = x;
        transform->y = y;
        continue;
      }
      if (content->GetType() == "MOVE_LEFT") {
        auto &networkId =
            scene.GetComponents<Rtype::Components::networkId>()[scene.GetEntity(
                "networkId")];
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
        if (networkId.has_value() && id == networkId->id)
          continue;
        controller->movingLeft = move;
        transform->x = x;
        transform->y = y;
        continue;
      }
      if (content->GetType() == "MOVE_RIGHT") {
        auto &networkId =
            scene.GetComponents<Rtype::Components::networkId>()[scene.GetEntity(
                "networkId")];
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
        if (networkId.has_value() && id == networkId->id)
          continue;
        controller->movingRight = move;
        transform->x = x;
        transform->y = y;
        continue;
      }
      if (content->GetType() == "MOVE_DOWN") {
        auto &networkId =
            scene.GetComponents<Rtype::Components::networkId>()[scene.GetEntity(
                "networkId")];
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
        if (networkId.has_value() && id == networkId->id)
          continue;
        controller->movingDown = move;
        transform->x = x;
        transform->y = y;
        std::cout << "change value " << std::endl;
        continue;
      }
      if (content->GetType() == "CREATE_COLLIDER") {
        auto &colliderFactory =
            scene.GetComponents<Rtype::Addons::CollisionFactory>()
                [scene.GetEntity("collision-factory")];
        if (!colliderFactory.has_value())
          continue;
        auto args = Network::Packet::Split(content->GetData(), ":");
        auto collisionType =
            Rtype::Addons::getCollisionTypeByString(args.back());
        args.pop_back();
        float y = std::stof(args.back());
        args.pop_back();
        float x = std::stof(args.back());
        args.pop_back();
        int i = std::stoi(args.back());
        args.pop_back();
        colliderFactory->creationRequests.push_back(
            Rtype::Addons::CollisionCreationRequest::
                createCollisionCreationRequest(
                    i, x, y, collisionType,
                    [&core](
                        RNGine::Core &c, RNGine::Scene::Entity &collision,
                        std::map<std::string, ValueCollision> &collisionInfo) {
                    }));
        continue;
      }
      if (content->GetType() == "CREATE_ENEMY") {
        auto &enemyFactory =
            scene.GetComponents<Rtype::Addons::EnemyFactory>()[scene.GetEntity(
                "enemy-factory")];
        if (!enemyFactory.has_value())
          continue;
        auto args = Network::Packet::Split(content->GetData(), ":");
        auto enemyType = Rtype::Addons::getEntityTypeByString(args.back());
        args.pop_back();
        float y = std::stof(args.back());
        args.pop_back();
        float x = std::stof(args.back());
        args.pop_back();
        std::string name = args.back();
        args.pop_back();
        enemyFactory->creationRequests.push_back(
            Rtype::Addons::EnemyCreationRequest::createShipCreationRequest(
                0, x, y, enemyType, name));
        continue;
      }
      if (content->GetType() == "DEATH") {
        if (content->GetData() == "")
          continue;
        core.GetActualScene().RemoveEntity(
            core.GetActualScene().GetEntity(content->GetData()));
        continue;
      }
      if (content->GetType() == "CREATE_SHIP") {
        auto args = Network::Packet::Split(content->GetData(), ":");
        std::string sceneName = args.back();
        args.pop_back();
        float y = std::stof(args.back());
        args.pop_back();
        float x = std::stof(args.back());
        args.pop_back();
        int i = std::stoi(args.back());
        args.pop_back();
        std::cout << "get fact" << std::endl;
        auto &shipFactory =
            core.GetScene(sceneName).GetComponents<Rtype::Addons::ShipFactory>()
                [core.GetScene(sceneName).GetEntity("ship-factory")];
        if (!shipFactory.has_value())
          continue;
        shipFactory->creationRequests.push_back(
            Rtype::Addons::ShipCreationRequest::createShipCreationRequest(i, x,
                                                                          y));
        continue;
      }
      if (content->GetType() == "SWITCH_SCENE") {
        core.SetActualScene(content->GetData());
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
        auto &networkId =
            scene.GetComponents<Rtype::Components::networkId>()[scene.GetEntity(
                "networkId")];
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
        std::cout << "before check" << std::endl;
        if (!networkId.has_value())
          continue;
        if (networkId->id == id)
          continue;
        RNGine::Scene::Entity entity =
            scene.GetEntity("ship-" + std::to_string(id));
        auto &transform = transforms[entity];
        if (type == "BASIC" && transform.has_value() &&
            hitboxs[entity].has_value() && damages[entity].has_value()) {
          std::cout << "after check" << std::endl;
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