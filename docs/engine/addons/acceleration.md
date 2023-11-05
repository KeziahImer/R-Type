# Addon Acceleration

L'addon "Acceleration" est utilisé pour définir la vitesse d'accélération en x et y pour les entités du jeu. Cet addon est utile pour simuler des mouvements fluides en modifiant la vitesse des entités au fil du temps.

## Exemple d'utilisation

```cpp
RNGine::Addons::Acceleration acceleration;

acceleration.x = 0.5f;  // Accélération horizontale
acceleration.y = 0.2f;  // Accélération verticale

// Appliquer l'accélération à une entité
entity.addAddon(acceleration);
```
