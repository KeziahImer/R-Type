# SendPacket Component

The "SendPacket" component is used to store data packets to be sent over the network in the game. It contains a list of packets to be sent. This component is primarily used to manage network communication in the game by storing data packets to transmit.

This component includes the following information:

- `packets`: A vector (dynamic array) of network packets (of type `Network::Packet`) to be sent. Each packet can contain specific data to be sent to other clients or servers.

This component is essential for network communication in the game, allowing the storage and management of data to be sent to other players or servers. It is used to send information, commands, or updates over the network.

## Example Usage

The "SendPacket" component is used to store data packets to be sent over the network:

```cpp
// Creating a SendPacket component
Client::Components::SendPacket sendPacket;

// Creating network packets and adding them to the packet list
Network::Packet packet1;
packet1 << "Data for packet 1";
sendPacket.packets.push_back(packet1);

Network::Packet packet2;
packet2 << 42; // Example data (integer)
sendPacket.packets.push_back(packet2);

// Sending packets over the network
// ...

// Using the SendPacket component to manage the packets to be sent
```