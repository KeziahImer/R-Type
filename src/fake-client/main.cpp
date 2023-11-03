#include <iostream>

#include "Network/Engine.hpp"

int main() {
  std::cout << "FakeClient !" << std::endl;
  Network::Engine engine(4243);
  auto server = engine.Resolve("127.0.0.1", "4242");
  Network::Packet packet;
  packet.type = Network::PacketType::None;
  try {
    for (int i = 0; i < 32; i++) {
      engine.Send(server, packet);
    }
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }

  while (true) {
    engine.Poll();
  }

  return 0;
}