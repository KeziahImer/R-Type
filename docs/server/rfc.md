# RFC DOCUMENTATION :

**Version Number:** 1

**Publication Date:** October 2023

**Authors:** Alexandre Frede, Léandre Sentenac, Kéziah Imer, Adil Nouiri, Thomas Papaix

## Introduction :

This document establishes a binary communication protocol for the R-Type game using the User Datagram Protocol (UDP). The protocol facilitates the exchange of commands and data between clients and the proxy server. Each message is encapsulated in a defined structure, including elements such as the command to be executed, a status code, and associated content.

## Message Structure :

The messages exchanged between clients and the server follow the defined binary structure below:

```c++
enum Command {
    LOGIN,
    START,
    MOVE,
    SHOOT
};

enum Code {
    SUCCESS,
    ERROR,
    NONE
};

typedef struct Data_t {
    enum Command command;
    enum Code code;
    char content[1024];
} Data;
```

- `command`: Indicates the action to be performed (LOGIN, START, MOVE, SHOOT, or NOTHING).
- `code`: Represents the status of the operation (SUCCESS, ERROR, or NONE).
- `content`: Contains data associated with the command, such as movement coordinates, shoot details, etc.

## Exchange Procedure

### Client to Server

When a client wants to send a command to the server, it encapsulates the `Data` structure into a binary stream and sends it via the appropriate transport protocol.

### Server to Client

The proxy server receives messages from clients, processes them based on the command, and redistributes them to other connected clients, except for the LOGIN message. Clients receive the data, decode the Data structure from the binary stream, and act accordingly.

## Error Handling

Communication errors are managed using the `code` field of the `Data` structure. In case of an error, the `ERROR` code is sent back to inform the client of the operation failure, otherwise, the `SUCCESS` code is sent back. The `NONE` code is used for the request like a neutral code.

## Commands

1. **LOGIN**
   - **Arguments:** N/A
   - **Description:** Identifies the new client, typically used for creating a new spaceship and establishing its presence in the game environment and transitions the game from the menu to a lobby where players gather.

2. **START**
   - **Arguments:** N/A
   - **Description:** Starts the game for all players in the lobby.

3. **MOVE**
   - **Arguments:** `vx,vy,px,py,id` (comma-separated values)
   - **Description:** Moves the spaceship corresponding to the given `id`. The arguments represent velocity (`vx`, `vy`) and position (`px`, `py`) coordinates, along with the unique identifier (`id`) of the spaceship.

4. **SHOOT**
   - **Arguments:** `id`
   - **Description:** Triggers the spaceship corresponding to the given `id` to shoot in the game.
