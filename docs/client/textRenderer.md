# TextRenderer

The "TextRenderer" module is responsible for displaying text on the screen in the game. It allows updating and displaying various text elements, such as scores, levels, character or object lives, etc. This contributes to the game's user interface by providing essential information to players.

Text display is important for conveying information to players and for creating an informative and intuitive user interface.

## Features
The "TextRenderer" module performs the following actions:

- Displays the player's score.

- Displays the lives of characters or objects.

- Displays the current level.

- Manages the update and display of various text elements.

## Example Usage
The "TextRenderer" module is used to display text in the game:

```cpp
// Creating an instance of TextRenderer
Client::TextRenderer textRenderer;

// In the main game loop
while (!r::WindowShouldClose()) {
    // ...
    textRenderer.UpdateTexts(core.GetActualScene()); // Updates and displays text
    // ...
}
```