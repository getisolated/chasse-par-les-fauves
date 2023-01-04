#include "Joueur.h"
#include "map.h"

Joueur::Joueur (): x(-1), y(-1) {}

Joueur::Joueur (int x, int y) : x(x), y(y) {}

void Joueur::deplace(char direction) {
      // Déplace le joueur dans la direction souhaitée
      if (direction == 'z' && y > 1) {
        y--;
      } else if (direction == 's' && y < MAP_HEIGHT - 2) {
        y++;
      } else if (direction == 'd' && x < MAP_WIDTH - 2) {
        x++;
      } else if (direction == 'q' && x > 1) {
        x--;
      }
}
