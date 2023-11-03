/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** Rtype game
*/

#ifndef _RTYPE_CLIENT_COMPONENTS_SENDPACKET_HPP_
#define _RTYPE_CLIENT_COMPONENTS_SENDPACKET_HPP_

#include <vector>

#include "Network/Engine.hpp"

namespace Client {
namespace Components {
struct SendPacket {
  std::vector<Network::Packet> packets;
};
} // namespace Components
} // namespace Client

#endif