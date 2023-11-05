# Addon "Acceleration"

"The "Acceleration" addon is used to set the acceleration speed in the x and y directions for game entities. This addon is helpful for creating smooth movements by changing the entities' speed over time."

## Example of use

```cpp
RNGine::Addons::Acceleration acceleration;

acceleration.x = 0.5f;  // Accélération horizontale
acceleration.y = 0.2f;  // Accélération verticale

// Appliquer l'accélération à une entité
entity.addAddon(acceleration);
```
