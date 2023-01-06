#include "Joueur.h"

Joueur::Joueur (): d_x(-1), d_y(-1) {}

Joueur::Joueur (int x, int y) : d_x(x), d_y(y) {}

void Joueur::deplace(char direction, int height, int width) {
      // Déplace le joueur dans la direction souhaitée
      if (direction == 'z' && d_y > 1) {
        d_y--;
      } else if (direction == 's' && d_y < height - 2) {
        d_y++;
      } else if (direction == 'd' && d_x < width - 2) {
        d_x++;
      } else if (direction == 'q' && d_x > 1) {
        d_x--;
      }
}

int Joueur::x() const
{
    return d_x;
}

int Joueur::y() const
{
    return d_y;
}

int Joueur::modifieX(int x)
{
    d_x=x;
}

int Joueur::modifieY(int y)
{
    d_y=y;
}
