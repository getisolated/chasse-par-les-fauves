#ifndef FAUVE_H
#define FAUVE_H
#include "Joueur.h"
#include "Piege.h"
#include <vector>

class Fauve {
    public:
        Fauve();
        Fauve(int x, int y);
        int x;
        int y;
        void deplace(const Joueur& joueur, const std::vector<Piege>& pieges);
};

#endif // FAUVE_H
