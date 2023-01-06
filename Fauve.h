#ifndef FAUVE_H
#define FAUVE_H
#include "Joueur.h"
#include "Piege.h"
#include <vector>

class Fauve {
    public:
        Fauve();
        Fauve(int x, int y);
        void deplace(const Joueur& joueur, const std::vector<Piege>& pieges);
        int x() const;
        int y() const;


    private:
        int d_x;
        int d_y;
};

#endif // FAUVE_H
