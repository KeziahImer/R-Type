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

class Packet {
public:
  using PacketId = size_t;

public:
  Packet() = default;

  void SetId(PacketId id);
  PacketId GetId() const;
  int GetChecksum() const;
  void SetType(std::string type);
  std::string GetType() const;
  void SetFailed(const std::vector<PacketId> &failed);
  std::vector<PacketId> GetFailed() const;
  void SetData(const std::string &data);
  std::string GetData() const;

  static std::vector<std::string> Split(const std::string &str,
                                        const std::string &delim);
  static Packet FromString(const std::string &buffer);
  static std::string ToString(const Packet &packet);

  std::string ToString() const;

private:
  PacketId _id = 0;
  std::string _type = "";
  std::vector<PacketId> _failed = {};
  std::string _data = "";
};

} // namespace Network

#endif