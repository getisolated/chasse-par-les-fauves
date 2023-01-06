#ifndef JOUEUR_H
#define JOUEUR_H

class Joueur {
    public:
        Joueur();
        Joueur(int x, int y);
        int x() const;
        int y() const;
        int modifieX(int x);
        int modifieY(int y);
        void deplace(char direction, int height, int width);
    private:
        int d_x;
        int d_y;
};

#endif // JOUEUR_H
