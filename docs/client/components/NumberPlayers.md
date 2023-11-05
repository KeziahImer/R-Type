# NumberPlayers Component

The "NumberPlayers" component is used to store the number of players currently involved in a game session. It allows tracking the number of active players at a given moment. This component stores the following information:

- `numberPlayers`: An integer representing the number of active players in the game.

This component is useful for managing multiplayer games where the number of players can dynamically change or for displaying information about the number of active players in a game session.

## Example Usage

The "NumberPlayers" component is used to track the number of active players in a game session:

```cpp
// Creating a NumberPlayers component
Client::Components::NumberPlayers players;
players.numberPlayers = 2; // There are currently 2 players in the game session

// Using the NumberPlayers component to manage the number of active players
```