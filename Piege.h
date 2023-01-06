#ifndef PIEGE_H
#define PIEGE_H


class Piege
{
    public:
        Piege();
        Piege(int x, int y);
        int x() const;
        int y() const;
        int modifieX(int x);
        int modifieY(int y);
    private:
        int d_x;
        int d_y;
};

#endif // PIEGE_H
