#ifndef JOUEUR_H
#define JOUEUR_H

class Joueur {
    public:
        Joueur();
        Joueur(int x, int y);
        int x;
        int y;
        void deplace(char direction, int height, int width);
};

#endif // JOUEUR_H
