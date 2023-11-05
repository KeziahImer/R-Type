
**Collider.md**

# Addon Collider

L'addon "Collider" est utilisé pour gérer la détection de collisions entre les entités du jeu. Il maintient une liste des entités en collision et fournit des données sur les collisions, telles que les entités impliquées, les hitbox et les transformations associées.

## Exemple d'utilisation

```cpp
RNGine::Addons::Collider collider;

// Définir la boîte de collision (hitbox) de l'entité
RNGine::Components::Hitbox hitbox;
hitbox.width = 32;
hitbox.height = 32;

// Ajouter la boîte de collision à l'entité
entity.addComponent(hitbox);

// Appliquer l'addon "Collider" à l'entité
entity.addAddon(collider);
```