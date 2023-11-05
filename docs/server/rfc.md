# RFC DOCUMENTATION :

**Title:** Binary Communication Protocol for R-Type Network Game

**Version Number:** 2.0

**Authors:** Alexandre Frede, Léandre Sentenac, Kéziah Imer, Adil Nouiri, Thomas Papaix

## Abstract

This document specifies a binary communication protocol for the R-Type network game. The protocol is designed for use over UDP and aims to ensure reliable message exchange through packet ordering, integrity checks, and error handling mechanisms.

## 1. Introduction

This RFC outlines a communication protocol for the R-Type game played over a network, utilizing UDP for message transport. Given the unreliability of UDP, the protocol includes mechanisms for packet ordering and integrity verification to manage packet loss and ensure message consistency.

## 2. Protocol Overview

The protocol operates on a binary message format, with each packet beginning with a unique integer identifier (ID). This ID allows for reordering of received packets and detection of any lost during transmission. Each packet contains a checksum for integrity validation, excluding the checksum field itself during calculation. The protocol also allows for acknowledging lost packets by sending back their IDs, and defines message types for packet decoding.

## 3. Packet Structure

### 3.1 Packet Header

```c++
typedef struct {
    int packet_id;
    unsigned char checksum;
    char type[10];
} PacketHeader;
```

- `packet_id`: Sequence identifier for ordering and loss detection.
- `checksum`: Sum of all bytes in the packet, with the checksum byte set to 0 during calculation.
- `type`: String representing the packet type, dictating how the rest of the packet is to be interpreted.

### 3.2 Acknowledgment Mechanism

```c++
typedef struct {
    int missing_packet_ids[16];
} Acknowledgment;
```

- `missing_packet_ids`: Array of packet IDs that have not been received, signaling the sender to resend them.

### 3.3 Packet Types

The protocol defines various packet types with specific decoding instructions. These types are expandable as development progresses.

## 4. Communication Flow

### 4.1 From Client to Server

Clients send structured packets to the server containing commands and data, which the server processes and optionally forwards to other clients.

### 4.2 From Server to Client

The server sends packets to clients, which must reorder them using the packet ID and verify integrity using the checksum.

# 5. Error Handling

The protocol incorporates a simple yet effective mechanism for ensuring message integrity and handling packet loss. The steps involved in this process are:

- **Checksum Calculation**: Before sending a packet, the sender must calculate the checksum by summing all bytes in the packet with the checksum byte initially set to zero. This checksum is then included in the packet header.

- **Checksum Verification**: Upon receipt, the receiver recalculates the checksum by summing all bytes, including the checksum byte received (which was originally set to zero during calculation by the sender). If the calculated sum is not zero, it indicates that the packet has been corrupted in transit.

- **Packet Loss Detection**: The receiver uses the packet ID to detect missing packets. If it detects a non-sequential packet ID, it can assume that packets have been lost.

- **Handling Lost Packets**: The receiver maintains a buffer of the last 16 packet IDs received. If it detects a gap in the sequence, it sends back a list of missing packet IDs to the sender. The sender is then responsible for resending these packets.

- **Resending Mechanism**: Upon receiving the list of missing packet IDs, the sender must resend the specific packets. The resending should be prioritized over new packets to ensure the receiver can reconstruct the correct sequence of game events.
