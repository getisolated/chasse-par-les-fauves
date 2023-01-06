#ifndef JEU_H
#define JEU_H
#include <vector>
#include "Joueur.h"
#include "Fauve.h"
#include "Piege.h"
#include <map>
#include "map.h"
#include <string>

class Jeu
{
    public:
        Jeu(const std::string& filename);
        Jeu(Joueur& j, const std::vector<std::pair<int, int>>& positions_fauves, const std::vector<std::pair<int, int>>& positions_pieges);
        int mapHeight() const;
        Joueur renvoieJoueur() const;
        int mapWidth() const;
        int score() const;
        Map renvoieMap() const;
        std::vector<Fauve> fauves() const;
        std::vector<Piege> pieges() const;
        void initialiseMap(Map& map);
        void printMap(const Map& map, const Joueur& joueur, const std::vector<Fauve>& fauves, const std::vector<Piege>& pieges);
        bool fauvesRestants() const;
        void ajouterScore(int points);
        void deplaceJoueur(char direction, int height, int width);
        void deplaceFauves(const Joueur& joueur, const std::vector<Piege>& pieges);

    private:
        int d_mapHeight;
        int d_mapWidth;
        Map map;
        Joueur d_joueur;
        std::vector<Fauve> d_fauves;
        std::vector<Piege> d_pieges;
        int d_score;

};


#endif // JEU_H
