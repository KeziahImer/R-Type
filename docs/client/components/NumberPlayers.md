# NumberPlayers
Le composant "NumberPlayers" est utilisé pour stocker le nombre de joueurs actuellement impliqués dans une partie du jeu. Il permet de suivre le nombre de joueurs actifs à un moment donné. Ce composant stocke l'information suivante :

- `numberPlayers`: Un entier représentant le nombre de joueurs actifs dans la partie.

Ce composant est utile pour gérer des jeux multijoueurs où le nombre de joueurs peut varier dynamiquement ou pour afficher des informations sur le nombre de joueurs actifs dans une partie.

## Exemple d'utilisation
Le composant "NumberPlayers" est utilisé pour suivre le nombre de joueurs actifs dans une partie:

```cpp 
// Création d'un composant NumberPlayers
Client::Components::NumberPlayers players;
players.numberPlayers = 2; // Il y a actuellement 2 joueurs dans la partie

// Utilisation du composant NumberPlayers pour gérer le nombre de joueurs actifs

```