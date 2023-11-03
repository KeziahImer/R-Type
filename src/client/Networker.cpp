#include "Networker.hpp"
#include "Network/Packet.hpp"

Client::Networker::Networker() : Engine(0) {
  _server = Resolve("localhost", "4242");
}

void Client::Networker::Update(RNGine::Core &core) {
  Poll();
  ReceivePackets(core);
  SendPackets(core);
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
        _lastSend = core.currentTime;
        Send(_server, packet);
      }
      packets.clear();
    }
  }
  if (_lastSend != 0.0f && core.currentTime - _lastSend > 1.0) {
    Network::Packet packet;
    packet.type = Network::PacketType::None;
    _lastSend = core.currentTime;
    Send(_server, packet);
  }
}

void Client::Networker::WaitAuthResponse(RNGine::Core &core) {
  for (auto &reception : received) {
    auto packets = reception.second;
    auto endpoint = reception.first;

    for (auto packet : packets) {
      auto id = packet.first;
      auto content = packet.second;

      if (_reads[endpoint][id] || !content.has_value())
        continue;

      _reads[endpoint][id] = true;

      std::cout << "Received packet " << id << " from "
                << endpoint.address().to_string() << ":" << endpoint.port()
                << std::endl;

      Network::Packet base;
      memcpy(&base, &content.value(), sizeof(Network::Packet));

      if (base.type != Network::PacketType::AuthServerResponseType)
        continue;
      Network::AuthServerResponse response;
      memcpy(&response, &content.value(), sizeof(Network::AuthServerResponse));
      _controlledId = response.client_id;
      std::cout << "Controlled id: " << _controlledId << std::endl;
    }
  }
}
