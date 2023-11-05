#include "Network/Packet.hpp"

void Network::Packet::SetId(PacketId id) { _id = id; }

Network::Packet::PacketId Network::Packet::GetId() const { return _id; }

int Network::Packet::GetChecksum() const {
  int _checksum = 0;
  std::string receptions;
  for (auto fail : _failed) {
    receptions += std::to_string(fail) + ",";
  }
  if (!receptions.empty())
    receptions.pop_back();
  std::string packet =
      std::to_string(_id) + "|" + _type + "|" + receptions + "|" + _data;
  for (auto c : packet)
    _checksum += c;
  return _checksum;
}

void Network::Packet::SetType(std::string type) { _type = type; }

std::string Network::Packet::GetType() const { return _type; }

void Network::Packet::SetFailed(const std::vector<PacketId> &failed) {
  _failed = failed;
}

std::vector<Network::Packet::PacketId> Network::Packet::GetFailed() const {
  return _failed;
}

void Network::Packet::SetData(const std::string &data) { _data = data; }

std::string Network::Packet::GetData() const { return _data; }

std::vector<std::string> Network::Packet::Split(const std::string &str,
                                                const std::string &delim) {
  std::vector<std::string> tokens;
  size_t prev = 0, pos = 0;
  while (pos < str.length() && prev < str.length()) {
    pos = str.find(delim, prev);
    if (pos == std::string::npos)
      pos = str.length();
    std::string token = str.substr(prev, pos - prev);
    tokens.push_back(token);
    prev = pos + delim.length();
  }
  return tokens;
}

Network::Packet Network::Packet::FromString(const std::string &buffer) {
  Packet packet;
  auto tokens = Split(buffer, "|");
  if (tokens.size() < 4)
    throw std::runtime_error("Invalid packet: only " +
                             std::to_string(tokens.size()) + " tokens");
  try {
    packet.SetId(std::stoi(tokens[0]));
  } catch (const std::exception &) {
    throw std::runtime_error("Invalid packet: id is not a number");
  }
  if (tokens[1].empty())
    throw std::runtime_error("Invalid packet: type is empty");
  packet.SetType(tokens[1]);
  auto receptions = Split(tokens[2], ",");
  std::vector<PacketId> failed;
  for (auto reception : receptions) {
    try {
      std::stringstream sstream(reception);
      size_t result;
      sstream >> result;
      failed.push_back(result);
    } catch (const std::exception &) {
      throw std::runtime_error(
          "Invalid packet: some reception are not valid number");
    }
  }
  packet.SetFailed(failed);
  if (tokens.size() > 4 && !tokens[4].empty())
    packet.SetData(tokens[4]);
  auto calculated = packet.GetChecksum();
  int checksum = 0;
  try {
    checksum = std::stoi(tokens[3]);
  } catch (const std::exception &) {
    throw std::runtime_error("Invalid packet: checksum is not a number");
  }

  if (checksum != calculated)
    throw std::runtime_error("Invalid packet: checksum is not valid");
  return packet;
}

std::string Network::Packet::ToString(const Packet &packet) {
  std::string receptions;
  for (auto reception : packet.GetFailed()) {
    receptions += std::to_string(reception) + ",";
  }
  if (!receptions.empty())
    receptions.pop_back();
  return std::to_string(packet.GetId()) + "|" + packet.GetType() + "|" +
         receptions + "|" + std::to_string(packet.GetChecksum()) + "|" +
         packet.GetData();
}

std::string Network::Packet::ToString() const { return ToString(*this); }
