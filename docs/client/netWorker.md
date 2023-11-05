# Networker

The "Networker" module is responsible for managing network communications within the game. It enables the sending and receiving of network packets to synchronize information between the client and the server.

This module is essential for allowing the game to interact with a remote server, send data, and receive responses, particularly for player authentication.

## Features
The "Networker" module performs the following actions:

- Initializes the connection with the server by resolving the address and port.

- Updates network communication by sending and receiving packets.

- Awaits an authentication response from the server when the current scene is "lobby."

## Example Usage
The "Networker" module is used to handle network communications within the game:

```cpp
// Create an instance of Networker
Client::Networker networker;

// Inside the game's main loop
while (!r::WindowShouldClose()) {
    // ...
    networker.Update(core); // Update network communication
    // ...
}
```