#include "Piege.h"

Piege::Piege (): d_x(-1), d_y(-1) {}

Piege::Piege(int x, int y) : d_x(x), d_y(y) {}


int Piege::x() const
{
    return d_x;
}

int Piege::y() const
{
    return d_y;
}

int Piege::modifieX(int x)
{
    d_x=x;
}

int Piege::modifieY(int y)
{
    d_y=y;
}
