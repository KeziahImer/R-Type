# IsClicked
Le composant "IsClicked" est utilisé pour enregistrer si une entité a été cliquée avec le bouton gauche ou droit de la souris. Il stocke les informations suivantes :

- `IsClickedRight`: Un booléen indiquant si l'entité a été cliquée avec le bouton droit de la souris.


- `IsClickedLeft`: Un booléen indiquant si l'entité a été cliquée avec le bouton gauche de la souris. 


Ce composant est utilisé pour gérer les interactions de clic de souris avec les entités du jeu. Le système associé "IsClickedSystem" met à jour ces valeurs en fonction des informations provenant du système "IsHover" et du système "MousePosition".

## Exemple d'utilisation
Le composant "IsClicked" est mis à jour par le système "IsClickedSystem", qui vérifie si une entité est en cours de survol ("IsHover") et la position du curseur de la souris ("MousePosition"). Si l'entité est en cours de survol et qu'un clic de souris est détecté, le composant "IsClicked" est mis à jour en conséquence.

```cpp
// Création d'un composant IsClicked
Client::Components::IsClicked isClicked;

// Utilisation du composant IsClicked pour vérifier si l'entité a été cliquée
if (isClicked.IsClickedLeft) {
    // Réaliser une action pour un clic gauche
}

if (isClicked.IsClickedRight) {
    // Réaliser une action pour un clic droit
}
```