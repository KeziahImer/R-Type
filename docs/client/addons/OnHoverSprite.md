# OnHoverSprite
Le composant "OnHoverSprite" est utilisé pour gérer le changement d'image ou de sprite d'une entité lorsqu'elle est survolée par le curseur de la souris. Il stocke les informations suivantes :

- `hoverSprite`: L'image ou le sprite qui sera affiché lorsque l'entité est survolée.


- `isChanged`: Un booléen indiquant si l'image affichée a été modifiée en raison du survol.


- `hitbox`: Une zone de collision associée à l'entité (définie par un vecteur 4D).


- `tmpSprite`: L'image ou le sprite original avant le survol.


Ce composant permet de modifier l'apparence visuelle d'une entité lorsqu'elle est survolée par le curseur de la souris. Le système associé "OnHoverSpriteSystem" gère le changement d'image en fonction du survol de l'entité.

## Exemple d'utilisation
Le composant "OnHoverSprite" est mis à jour par le système "OnHoverSpriteSystem" pour gérer le changement d'image ou de sprite lors du survol de l'entité.

```cpp
// Création d'un composant OnHoverSprite
Client::Components::OnHoverSprite onHoverSprite;

// Utilisation du composant OnHoverSprite pour gérer le changement d'image lors du survol
if (onHoverSprite.isChanged) {
    // Afficher l'image ou le sprite associé au survol
} else {
    // Afficher l'image ou le sprite original
}
```
