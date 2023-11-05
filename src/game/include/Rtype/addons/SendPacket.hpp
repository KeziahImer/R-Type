/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** Rtype game
*/

#ifndef _RTYPE_CLIENT_COMPONENTS_SENDPACKET_HPP_
#define _RTYPE_CLIENT_COMPONENTS_SENDPACKET_HPP_

#include <iostream>
#include <vector>

namespace Client {
namespace Components {
struct SendPacket {
  std::vector<std::pair<std::string, std::string>> packets;
};
} // namespace Components
} // namespace Client

#endif