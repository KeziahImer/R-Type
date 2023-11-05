# Class Core
## Constructor

The `Core` class has a constructor that initializes the engine's basic attributes:

```cpp
Core();

```

- `currentTime`: The current time of the engine.


- `nextUpdate`: The expected time for the next game update.


- `lastUpdate`: The time of the last game update.

- `deltaTime`: The time elapsed since the last update.


- `targetFPS`: The game's target frame rate (default is 60 frames per second).

##  "Update" Method
The Update method is responsible for updating the engine. It calculates the time elapsed since the last update and determines if the engine should be updated at the next step:
```cpp
void update();
```
- `currentTime`: Updates the current time.


- `nextUpdate`: CCalculates when the next update should occur.

- `deltaTime`: Calculates the time elapsed since the last update.


- `RunSystems`: Calls the RunSystems function to execute registered systems.

The `update` method allows you to obtain the current time as a Time data type:

## Méthode "GetNow"

The `GetNow` method returns true if the engine should be updated at the next step; otherwise, it returns "false."

```cpp
Time getNow();
```

- It uses the `<chrono>` library to obtain the current time in seconds.

## Systems Management
The `Core` class enables you to add, remove, and run systems. A system is a function that

- AddSystem :  Allows you to add a system to the engine by providing a unique name and an associated function.
- RemoveSystem: Allows you to remove a system from the engine using its name.
- RunSystems: Executes all registered systems in the engine.

## Scenes Management

The R-type engine manages multiple game scenes. The Core class allows you to add, remove, and set the current scene.

- `AddScene`: Enables you to add a scene to the engine by providing a unique name and an instance of the Scene class.


- `RemoveScene`: Allows you to remove a scene from the engine using its name.


- `SetActualScene`: Sets the current scene to be displayed and updated.

## Accessing Scenes

The Core class allows you to access scenes by their name:

- GetScene:  Allows you to obtain a reference to a scene by its name.
- GetActualScene: Allows you to obtain a reference to the currently active scene.

## Accessing the Name of the Current Scene

The `GetActualSceneName`  method allows you to obtain the name of the current scene.

The `Core` class is an essential component of the R-type engine, ensuring the management of time, systems, and scenes, making it a central element of the game.
