#include "Fauve.h"

Fauve::Fauve() : x(-1), y(-1) {}

Fauve::Fauve(int x, int y) : x(x), y(y) {}

void Fauve::deplace(const Joueur& joueur, const std::vector<Piege>& pieges) {
      if (x < 0 || y < 0) return; // Ignore les fauves morts

      // Ne d�place les fauves que tous les deux d�placements du joueur

      if (x < joueur.x) x++;
      if (x > joueur.x) x--;
      if (y < joueur.y) y++;
      if (y > joueur.y) y--;

      // V�rifie si le fauve tombe sur un pi�ge
      for (const auto& piege : pieges) {
        if (x == piege.x && y == piege.y) {
          x = -1;
          y = -1;
          break;
        }
      }
    }
