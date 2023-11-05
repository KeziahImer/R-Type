# Addon Velocity

L'addon "Velocity" est utilisé pour gérer la vitesse des entités en x et y. Il permet de définir la vitesse de déplacement des entités, ce qui est essentiel pour la simulation de mouvements dans le jeu.

## Exemple d'utilisation

```cpp
RNGine::Addons::Velocity velocity;

velocity.x = 2.0f;  // Vitesse horizontale
velocity.y = 1.5f;  // Vitesse verticale

// Appliquer la vitesse à une entité
entity.addAddon(velocity);
```