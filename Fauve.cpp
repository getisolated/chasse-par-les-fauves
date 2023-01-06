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

      // Ne déplace les fauves que tous les deux déplacements du joueur

      if (d_x < joueur.x()) d_x++;
      if (d_x > joueur.x()) d_x--;
      if (d_y < joueur.y()) d_y++;
      if (d_y > joueur.y()) d_y--;

      // Vérifie si le fauve tombe sur un piège
      for (const auto& piege : pieges) {
        if (d_x == piege.x() && d_y == piege.y()) {
          d_x = -1;
          d_y = -1;
          break;
        }
      }
    }
