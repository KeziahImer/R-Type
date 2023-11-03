/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** Rtype game
*/

#ifndef _RTYPE_NETWORK_PACKET_HPP_
#define _RTYPE_NETWORK_PACKET_HPP_

#include <boost/asio.hpp>
#include <cstddef>
#include <iostream>
#include <map>
#include <vector>

namespace Network {

const int MAX_BUFFER_SIZE = 1024;
const int RECEPTION_AMOUNT = 16;

enum PacketType {
  None,
  AuthClientRequestType,
  AuthServerResponseType,
  ErrorServerResponseType
};

struct Packet {
  int checksum;
  int id;
  int receptions[RECEPTION_AMOUNT];
  PacketType type;
};

struct AuthClientRequest : public Packet {};

struct AuthServerResponse : public Packet {
  int client_id;
};

struct ErrorServerResponse : public Packet {
  char message[32];
};

const std::vector<std::size_t> PacketSize = {
    sizeof(Packet), sizeof(AuthClientRequest), sizeof(AuthServerResponse),
    sizeof(ErrorServerResponse)};
} // namespace Network

#endif