# IsHover
Le composant "IsHover" est utilisé pour enregistrer si une entité est en cours de survol par le curseur de la souris. Il stocke la valeur suivante :

- `isHover`: Un booléen indiquant si l'entité est actuellement survolée par le curseur de la souris.


Ce composant est utilisé pour gérer les interactions de survol de la souris avec les entités du jeu. Le système associé "IsHoverSystem" vérifie si le curseur de la souris se trouve à l'intérieur de la zone de collision de l'entité, en utilisant les composants "Hitbox" et "Transform". Il met à jour la valeur "isHover" en conséquence.

## Exemple d'utilisation
Le composant "IsHover" est mis à jour par le système "IsHoverSystem" pour refléter si une entité est actuellement survolée par le curseur de la souris.

```cpp
Copy code
// Création d'un composant IsHover
Client::Components::IsHover isHover;

// Utilisation du composant IsHover pour vérifier si l'entité est en cours de survol
if (isHover.isHover) {
// Réaliser une action lorsque l'entité est survolée
}
```


