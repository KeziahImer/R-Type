# Composant Hitbox
Le composant "Hitbox" est utilisé pour définir une zone de collision rectangulaire associée à une entité du jeu. Il stocke les informations suivantes :

- `width`: La largeur de la boîte de collision.


- `height`: La hauteur de la boîte de collision.


- `originX`: La position en x du point d'origine de la boîte de collision.


- `originY`: La position en y du point d'origine de la boîte de collision.


Le composant "Hitbox" est essentiel pour détecter les collisions entre entités dans le jeu. En utilisant les dimensions et l'origine de la boîte de collision, il est possible de calculer les collisions de manière efficace.

## Exemple d'utilisation

```cpp
RNGine::Components::Hitbox hitbox;
hitbox.width = 32;
hitbox.height = 32;
hitbox.originX = 16;
hitbox.originY = 16;

// Utilisation du composant Hitbox pour définir la zone de collision d'une entité.
```