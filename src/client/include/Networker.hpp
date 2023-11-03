/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** Rtype game
*/

#ifndef _RTYPE_CLIENT_NETWORKER_HPP_
#define _RTYPE_CLIENT_NETWORKER_HPP_

#include "Network/Engine.hpp"
#include "RNGine/Core.hpp"
#include "RNGine/RNGine.hpp"

#include "components/SendPacket.hpp"

#include <map>

namespace Client {
class Networker : public Network::Engine {
public:
  Networker();

  void Update(RNGine::Core &core);
  void ReceivePackets(RNGine::Core &core);
  void SendPackets(RNGine::Core &core);

  void WaitAuthResponse(RNGine::Core &core);

private:
  boost::asio::ip::udp::endpoint _server;
  RNGine::Core::Time _lastSend = 0.0f;

  int _controlledId;

  std::map<boost::asio::ip::udp::endpoint, std::map<int, bool>> _reads;
};
} // namespace Client

#endif