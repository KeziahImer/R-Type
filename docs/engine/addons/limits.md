# Addon Limits

L'addon "Limits" est utilisé pour définir des limites de déplacement pour les entités. Il spécifie les valeurs minimales et maximales pour la position, la vitesse et l'accélération en x et y. Cela permet de restreindre le mouvement des entités dans des zones spécifiques du jeu.

## Exemple d'utilisation

```cpp
RNGine::Addons::Limits limits;

limits.minX = 0.0f;    // Position minimale en x
limits.maxX = 800.0f;  // Position maximale en x
limits.minY = 0.0f;    // Position minimale en y
limits.maxY = 600.0f;  // Position maximale en y

// Appliquer les limites à une entité
entity.addAddon(limits);
```