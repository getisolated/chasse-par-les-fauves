#include "Jeu.h"
#include <iostream>
#include "map.h"

Jeu::Jeu(Joueur& j, const std::vector<std::pair<int, int>>& positions_fauves, const std::vector<std::pair<int, int>>& positions_pieges) {
    // Initialise la carte avec une grille vide
        initMap(map);

    // Initialise la position du joueur
    joueur.x = j.x;
    joueur.y = j.y;

    // Initialise la position des fauves
    for (const auto& position : positions_fauves) {
        fauves.emplace_back(position.first, position.second);
    }

    // Initialise la position des pièges
    for (const auto& position : positions_pieges) {
        pieges.emplace_back(position.first, position.second);
    }
}

void Jeu::initMap(Map& map) {
    for (int y = 0; y < MAP_HEIGHT; y++) {
           for (int x = 0; x < MAP_WIDTH; x++) {
               map[std::make_pair(x, y)] = ' ';
           }
    }
}

void Jeu::printMap(const Map& map, const Joueur& joueur, const std::vector<Fauve>& fauves, const std::vector<Piege>& pieges) {
    // Affiche chaque ligne de la carte
    for (int y = 0; y < MAP_HEIGHT; y++) {
        // Affiche chaque case de la ligne
        for (int x = 0; x < MAP_WIDTH; x++) {

            // Affiche un bord infranchissable si le joueur est sur les bords de la carte
            if (x == 0 || y == 0 || x == MAP_WIDTH - 1 || y == MAP_HEIGHT - 1) {
                std::cout << '#';
                continue;
            }

            // Affiche le joueur
            if (x == joueur.x && y == joueur.y) {
                std::cout << 'J';
                continue;
            }

            // Affiche un fauve
            for (const auto& fauve : fauves) {
                if (x == fauve.x && y == fauve.y) {
                    std::cout << 'F';
                    goto end_loop;
                }
            }

            // Affiche un piège
            for (const auto& piege : pieges) {
                if (x == piege.x && y == piege.y) {
                    std::cout << 'P';
                    goto end_loop;
                }
            }

            // Affiche un espace vide
            std::cout << ' ';

            // Saut de ligne
            end_loop:;
        }
        std::cout << std::endl;
    }
}

bool Jeu::fauvesRestants() const {
    for(auto& fauve : fauves)
        if(fauve.x != -1 && fauve.y != -1)
            return true;
    return false;
}

void Jeu::ajouterScore(int points) {
    score += points;
}

