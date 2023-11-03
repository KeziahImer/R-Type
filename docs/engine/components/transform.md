# Composant "Transform"
Le composant "Transform" est utilisé pour définir la transformation spatiale d'une entité du jeu. Il stocke les informations suivantes :

- `x`: La position en x de l'entité.


- `y`: La position en y de l'entité.


- `rotation`: La rotation de l'entité (en degrés).


- `scaleX`: L'échelle en x de l'entité.


- `scaleY`: L'échelle en y de l'entité.


Le composant "Transform" permet de positionner, orienter et redimensionner une entité dans le monde du jeu. Il est essentiel pour gérer la position des entités et leur aspect visuel.

## Exemple d'utilisation

```cpp
RNGine::Components::Transform transform;
transform.x = 100;
transform.y = 200;
transform.rotation = 45; // Rotation de 45 degrés
transform.scaleX = 1.5; // Échelle en x de 1.5
transform.scaleY = 1.5; // Échelle en y de 1.5

// Utilisation du composant Transform pour positionner, orienter et redimensionner une entité.
```