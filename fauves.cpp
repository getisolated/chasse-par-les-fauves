
#include <iostream>
#include <cstdlib>
#include <ctime>

const int MAP_WIDTH = 30;
const int MAP_HEIGHT = 20;

// Structure pour repr�senter un joueur
struct Player {
  int x;
  int y;
};

// Structure pour repr�senter un fauve
struct Fauve {
  int x;
  int y;
};

int main() {
  // Initialisation du g�n�rateur de nombres al�atoires
  srand(time(nullptr));

  // Cr�ation de la map et placement du joueur et des fauves
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
}
