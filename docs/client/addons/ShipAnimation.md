# ShipAnimation
Le composant "ShipAnimation" est utilisé pour gérer l'animation des mouvements d'un vaisseau spatial dans le jeu. Il permet de contrôler les animations en fonction des actions du vaisseau, telles que monter (up), descendre (down), ou s'arrêter (none). Ce composant stocke les informations suivantes :

- `lastAction`: La dernière action effectuée par le vaisseau spatial, qui peut prendre les valeurs None, Up ou Down pour représenter les mouvements.


- Le système associé "ShipAnimationSystem" gère les animations du vaisseau en fonction de ces actions, en modifiant les animations du sprite du vaisseau.


## Exemple d'utilisation
Le composant "ShipAnimation" est utilisé pour contrôler les animations du vaisseau spatial en fonction de ses mouvements :

```cpp
// Création d'un composant ShipAnimation
Client::Addons::ShipAnimation shipAnimation;
shipAnimation.lastAction = Client::Addons::ShipAnimation::None; // Le vaisseau ne bouge pas au départ

// Utilisation du composant ShipAnimation pour contrôler les animations du vaisseau spatial
```