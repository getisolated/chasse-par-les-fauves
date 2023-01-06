#include "Fauve.h"

Fauve::Fauve() : d_x(-1), d_y(-1) {}

Fauve::Fauve(int x, int y) : d_x(x), d_y(y) {}

int Fauve::x() const
{
    return d_x;
}

int Fauve::y() const
{
    return d_y;
}


void Fauve::deplace(const Joueur& joueur, const std::vector<Piege>& pieges) {
      if (d_x < 0 || d_y < 0) return; // Ignore les fauves morts

      // Ne d�place les fauves que tous les deux d�placements du joueur

      if (d_x < joueur.x()) d_x++;
      if (d_x > joueur.x()) d_x--;
      if (d_y < joueur.y()) d_y++;
      if (d_y > joueur.y()) d_y--;

      // V�rifie si le fauve tombe sur un pi�ge
      for (const auto& piege : pieges) {
        if (d_x == piege.x() && d_y == piege.y()) {
          d_x = -1;
          d_y = -1;
          break;
        }
      }
    }
