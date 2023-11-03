#include "Server.hpp"
#include "Network/Packet.hpp"
#include <cstddef>
#include <cstring>

void Server::Core::Update(RNGine::Core &core) {
  PurgeReceptions();
  Poll();

  if (core.GetActualSceneName() == "") {
    Auth();
  } else {
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

void Server::Core::Auth() {
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

      if (base.type != Network::PacketType::AuthClientRequestType)
        continue;
      if (_clients.size() >= 4) {
        Network::ErrorServerResponse response;
        response.type = Network::PacketType::ErrorServerResponseType;
        strcpy(response.message, "Server is full");
        Send(endpoint, response);
        continue;
      }
      Network::AuthServerResponse response;
      response.type = Network::PacketType::AuthServerResponseType;
      int client_id = _clients.size() + 1;
      std::cout << "Sended controlled id: " << client_id << std::endl;
      response.client_id = client_id;
      _clients[endpoint] = client_id;
      Send(endpoint, response);
    }
  }
}
