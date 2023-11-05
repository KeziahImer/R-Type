# Lobby
## Boutons
Similar to the "Home" scene, the "Lobby" scene also features interactive buttons. These buttons are created using the CreateButton method, and each button has components such as Client::Components::IsHover and Client::Components::IsClicked to handle mouse interactions.

Example code for creating a button in the "Lobby" scene:
```cpp
CreateButton("multiplayer", "./assets/menu/btn-start", r::GetScreenHeight() / 2);
```

## Mouse Position Tracking
Mouse position tracking is managed by the `TrackMousePositionSystem`.  It updates the mouse entity's position based on the actual mouse position.

Example code for mouse position tracking:
```cpp
core.AddSystem("track-mouse-position", Client::Scenes::Home::TrackMousePositionSystem);
```

## Displaying the Number of Players

Here's your description translated into Markdown:

Lobby Operation
Introduction
The "Lobby" scene is an important part of the game and contains several essential game elements. This documentation will explain how these elements work in the code.

Buttons
Similar to the "Home" scene, the "Lobby" scene also features interactive buttons. These buttons are created using the CreateButton method, and each button has components such as Client::Components::IsHover and Client::Components::IsClicked to handle mouse interactions.

Example code for creating a button in the "Lobby" scene:

cpp
Copy code
CreateButton("multiplayer", "./assets/menu/btn-start", r::GetScreenHeight() / 2);
Mouse Position Tracking
Mouse position tracking is managed by the TrackMousePositionSystem. It updates the mouse entity's position based on the actual mouse position.

Example code for mouse position tracking:

cpp
Copy code
core.AddSystem("track-mouse-position", Client::Scenes::Home::TrackMousePositionSystem);
Displaying the Number of Players
The "Lobby" scene displays the number of connected players. This is managed using the `renderPlayers`. system. The number of players is stored in a  `Client::Components::NumberPlayers`component.

Example code for displaying the number of players:

```cpp
void Client::Scenes::Lobby::renderPlayers(RNGine::Core &core) {
  if (core.GetActualSceneName() != "lobby")
    return;
  auto &scene = core.GetActualScene();
  auto &numberPlayers =
      scene.GetComponents<Client::Components::NumberPlayers>()[scene.GetEntity(
          "numberPLayers")];
  if (!numberPlayers.has_value())
    return;
  std::string toPrint;
  if (numberPlayers->numberPlayers == 0) {
    toPrint = "Connecting...";
  } else {
    toPrint = "Players: " + std::to_string(numberPlayers->numberPlayers);
  }
  r::DrawText(toPrint.c_str(), r::GetScreenWidth() - 250, r::GetScreenHeight() - 50, 40,
           r::LIGHTGRAY);
}
```