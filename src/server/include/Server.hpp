/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** Rtype game
*/

#ifndef _RTYPE_SERVER_CORE_HPP_
#define _RTYPE_SERVER_CORE_HPP_

#include "Network/Engine.hpp"
#include "RNGine/Core.hpp"
#include "Rtype/addons/SendPacket.hpp"

namespace Server {
class Core : public Network::Engine {
public:
  Core(int port) : Engine(port) {}

  void Update(RNGine::Core &core);

  void SendPackets(RNGine::Core &core);

  void Auth(RNGine::Core &core);

  void PurgeReceptions();

  std::map<boost::asio::ip::udp::endpoint, int> _clients;

private:
  std::map<boost::asio::ip::udp::endpoint, std::map<int, bool>> _reads;
  RNGine::Core::Time _lastSend = 0.0f;
};
} // namespace Server

#endif