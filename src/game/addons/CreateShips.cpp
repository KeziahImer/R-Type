#include "Rtype/addons/CreateShips.hpp"
#include "RNGine/Scene.hpp"
#include "Rtype/addons/IsNetwork.hpp"
#include "Rtype/addons/NetworkId.hpp"
#include "Rtype/addons/SendPacket.hpp"
#include "Rtype/addons/ShipFactory.hpp"
#include <iostream>
#include <random>

void Rtype::Addons::CreateShipsSystem(RNGine::Core &core) {
  auto name = core.GetActualSceneName();
  if (name == "home" || name == "lobby" || name == "victory" ||
      name == "gameOver" || name == "LevelSelect")
    return;
  auto &scene = core.GetActualScene();
  auto &isNetwork =
      scene.GetComponents<Rtype::Components::IsNetwork>()[scene.GetEntity(
          "network")];
  auto &sender =
      scene.GetComponents<Client::Components::SendPacket>()[scene.GetEntity(
          "sender")];
  auto &networkId =
      scene.GetComponents<Rtype::Components::networkId>()[scene.GetEntity(
          "networkId")];
  auto &factory =
      scene.GetComponents<Rtype::Addons::ShipFactory>()[scene.GetEntity(
          "ship-factory")];
  auto &createShips =
      scene.GetComponents<Rtype::Addons::CreateShips>()[scene.GetEntity(
          "createShips")];
  if (networkId.has_value() || !createShips.has_value() ||
      !factory.has_value() || createShips->nbrPlayers == 0)
    return;
  std::cout << "Nombre players: " << createShips->nbrPlayers << std::endl;
  for (size_t i = 0; i < createShips->nbrPlayers; i++) {
    if (isNetwork.has_value() && sender.has_value()) {
      std::cout << "CREATE_SHIP: " + std::to_string(i + 1) + ":" +
                       std::to_string(100) + ":" +
                       std::to_string(100 + (i + 1) * 100)
                << std::endl;
      sender->packets.push_back(
          {"CREATE_SHIP", std::to_string(i + 1) + ":" + std::to_string(100) +
                              ":" + std::to_string(100 + (i + 1) * 100) + ":" +
                              core.GetActualSceneName()});
    }
    factory->creationRequests.push_back(
        Rtype::Addons::ShipCreationRequest::createShipCreationRequest(
            i + 1, 100.0f, 100.0f));
  }
  scene.RemoveEntity("createShips");
}
