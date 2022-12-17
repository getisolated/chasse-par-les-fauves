
#include <iostream>
#include <cstdlib>
#include <ctime>

const int MAP_WIDTH = 30;
const int MAP_HEIGHT = 20;

// Structure pour représenter un joueur
struct Player {
  int x;
  int y;
};

// Structure pour représenter un fauve
struct Fauve {
  int x;
  int y;
};

int main() {
  // Initialisation du générateur de nombres aléatoires
  srand(time(nullptr));

  // Création de la map et placement du joueur et des fauves
  char map[MAP_WIDTH][MAP_HEIGHT];
  Player player;
  player.x = rand() % MAP_WIDTH;
  player.y = rand() % MAP_HEIGHT;
  map[player.x][player.y] = 'P';

  const int NUM_FAUVES = 5;
  Fauve fauves[NUM_FAUVES];
  for (int i = 0; i < NUM_FAUVES; i++) {
    fauves[i].x = rand() % MAP_WIDTH;
    fauves[i].y = rand() % MAP_HEIGHT;
    map[fauves[i].x][fauves[i].y] = 'F';
  }

  //Boucle de jeu
  while(true){
    // Afficher la map
    for (int y = 0; y < MAP_HEIGHT; y++) {
      for (int x = 0; x < MAP_WIDTH; x++) {
        if (x == player.x && y == player.y) {
          std::cout << 'P';
        } else {
          bool fauve_found = false;
          for (int i = 0; i < NUM_FAUVES; i++) {
            if (x == fauves[i].x && y == fauves[i].y) {
              std::cout << 'F';
              fauve_found = true;
              break;
            }
          }
          if (!fauve_found) {
            std::cout << '.';
          }
        }
      }
      std::cout << std::endl;
    }
// Récupération du mouvement du joueur
    std::cout << "Entrez votre prochain mouvement (haut [z], bas [s], gauche [q], droite [d]): ";
    char move;
    std::cin >> move;

    // Mise à jour de la position du joueur
    switch (move) {
      case 'z':
        player.y--;
        break;
      case 's':
        player.y++;
        break;
      case 'q':
        player.x--;
        break;
      case 'd':
        player.x++;
        break;
    }
  }
}

