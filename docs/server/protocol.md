# Commnuication Protocol

The communication protocol define how clients and server communicate together. It's based on a UDP connection.

## Packet

A packet is a structure of data that is sent over the network. It's composed of a header and a body.

### Header

The header is composed of 2 fields:

- `tick`: The tick of the packet. It's used to know the order of the packets.
- `checksum`: The checksum of the packet. It's used to check if the packet is corrupted.
- `type`: The type of the packet. It's used to expect some receiver behavior.

#### Types

| Type ID | Type Name | Description                                                                                                        |
| ------- | --------- | ------------------------------------------------------------------------------------------------------------------ |
| 0       | `DIRECT`  | The message is sent and the sender doesn't expect a response from the client                                       |
| 1       | `CHECK`   | The message is sent and the sender expect a response from the client with the same header and "OK" or "KO" in body |
| 2       | `ASK`     | The message is sent and the sender expect a response from the client with data in it                               |

### Body

#### Lobby creation and connections

The body is composed of 2 fields:

- `lobby_action`: A id of the action to perfom.
- `data`: The data of the action.

| Lobby Action ID | Header Type | Lobby Action Name | Request Data       | Response Data      | Description                                                                              |
| --------------- | ----------- | ----------------- | ------------------ | ------------------ | ---------------------------------------------------------------------------------------- |
| 0               | `ASK`       | `CREATE_LOBBY`    | None               | lobby_code: string | This action create on the server a lobby joinable by other members                       |
| 1               | `ASK`       | `JOIN_LOBBY`      | lobby_code: string | message: string    | This action join a lobby and return a message in success and error to display on client  |
| 2               | `ASK`       | `LEAVE_LOBBY`     | None               | message: string    | This action leave a lobby and return a message in success and error to display on client |
| 3               | `ASK`       | `START_GAME`      | None               | message: string    | This action start the game and return a message in error to display on client            |

#### In game

The body is composed of 2 fields:

- `game_event`: A id of the event occuring.
- `data`: The data of the event.

The event are sent by the client to the server which will validate or not them

_Event Client to Server_

| Event ID | Header Type | Event Name | Data | Description                                                                      |
| -------- | ----------- | ---------- | ---- | -------------------------------------------------------------------------------- |
| 0        | `CHECK`     | `MOVED`    | x, y | The relative coordinates where the player ship is from the last received packet. |
| 1        | `CHECK`     | `SHOOT`    | None | The player shoot.                                                                |

_Event Server to Clients_

| Event ID | Header Type | Event Name    | Data     | Description                                                       |
| -------- | ----------- | ------------- | -------- | ----------------------------------------------------------------- |
| 2        | `CHECK`     | `CREATE_SHIP` | id, x, y | Ask to generate ship in the game at x, y and with an id.          |
| 3        | `CHECK`     | `MOVE`        | id, x, y | The relative position x, y of ship id from last received position |
| 4        | `CHECK`     | `SHOOT`       | id, x, y | The ship shoot with x, y starting point of the shoot              |
| 5        | `CHECK`     | `EXPLODE`     | id       | The ship explode                                                  |
| 6        | `CHECK`     | `END_GAME`    | None     | The game is finished                                              |
