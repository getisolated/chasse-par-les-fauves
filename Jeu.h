#ifndef JEU_H
#define JEU_H
#include <vector>
#include "Joueur.h"
#include "Fauve.h"
#include "Piege.h"
#include <map>
#include "map.h"

class Jeu
{
    public:
        Jeu(const std::string& filename);
        Jeu(Joueur& j, const std::vector<std::pair<int, int>>& positions_fauves, const std::vector<std::pair<int, int>>& positions_pieges);
        Map map;
        Joueur joueur;
        std::vector<Fauve> fauves;
        std::vector<Piege> pieges;
        int score;
        void initMap(Map& map);
        void printMap(const Map& map, const Joueur& joueur, const std::vector<Fauve>& fauves, const std::vector<Piege>& pieges);
        void chargerMap(const std::string& filename);
        bool fauvesRestants() const;
        void ajouterScore(int points);
        void initNiveau(const std::string& filename);
        int mapHeight;
        int mapWidth;
};

#endif // JEU_H
