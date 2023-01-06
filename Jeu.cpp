#include "Jeu.h"
#include <iostream>
#include <fstream>
#include <string>

Jeu::Jeu(Joueur& j, const std::vector<std::pair<int, int>>& positions_fauves, const std::vector<std::pair<int, int>>& positions_pieges) {

    d_score = 0;

    // Initialise la carte avec une grille vide
        initialiseMap(map);

    // Initialise la position du joueur
    d_joueur.modifieX(j.x());
    d_joueur.modifieY(j.y());

    // Initialise la position des fauves
    for (const auto& position : positions_fauves) {
        d_fauves.emplace_back(position.first, position.second);
    }

    // Initialise la position des pièges
    for (const auto& position : positions_pieges) {
        d_pieges.emplace_back(position.first, position.second);
    }
}

void Jeu::initialiseMap(Map& map) {
    for (int y = 0; y < d_mapHeight; y++) {
           for (int x = 0; x < d_mapWidth; x++) {
               map[std::make_pair(x, y)] = ' ';
           }
    }
}
int Jeu::mapHeight() const
{
    return d_mapHeight;
}
int Jeu::mapWidth() const
{
    return d_mapWidth;
}
int Jeu::score() const
{
    return d_score;
}
Joueur Jeu::renvoieJoueur() const
{
    return d_joueur;
}

void Jeu::deplaceJoueur(char direction, int height, int width)
{
    d_joueur.deplace(direction, height, width);
}

void Jeu::deplaceFauves(const Joueur& joueur, const std::vector<Piege>& pieges)
{
    for( auto& fauve : d_fauves) {
                fauve.deplace(joueur, pieges);
            }
}

Map Jeu::renvoieMap() const
{
    return map;
}
std::vector<Fauve> Jeu::fauves() const
{
    return d_fauves;
}
std::vector<Piege> Jeu::pieges() const
{
    return d_pieges;
}

void Jeu::printMap(const Map& map, const Joueur& joueur, const std::vector<Fauve>& fauves, const std::vector<Piege>& pieges) {
    // Affiche chaque ligne de la carte
    for (int y = 0; y < d_mapHeight; y++) {
        // Affiche chaque case de la ligne
        for (int x = 0; x < d_mapWidth; x++) {

            // Affiche un bord infranchissable si le joueur est sur les bords de la carte
            if (x == 0 || y == 0 || x == d_mapWidth - 1 || y == d_mapHeight - 1) {
                std::cout << '#';
                continue;
            }

            // Affiche le joueur
            if (x == joueur.x() && y == joueur.y()) {
                std::cout << 'J';
                continue;
            }

            // Affiche un fauve
            for (const auto& fauve : fauves) {
                if (x == fauve.x() && y == fauve.y()) {
                    std::cout << 'F';
                    goto end_loop;
                }
            }

            // Affiche un piège
            for (const auto& piege : pieges) {
                if (x == piege.x() && y == piege.y()) {
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
    for(auto& fauve : d_fauves)
        if(fauve.x() != -1 && fauve.y() != -1)
            return true;
    return false;
}

void Jeu::ajouterScore(int points) {
    d_score += points;
}

Jeu::Jeu(const std::string& fichierNiveau) {

    d_score = 0;

    std::ifstream file(fichierNiveau);

    // Fichier introuvable
    if (!file) throw std::runtime_error("Impossible d'ouvrir le fichier");

    // Initialisation des constantes height et width à partir du fichier texte
    d_mapHeight = 0;
    d_mapWidth = 0;

    std::string line;
    while (std::getline(file, line)) {
        d_mapHeight++;
        d_mapWidth = std::max(d_mapWidth, (int)line.length());
    }

    file.clear();
    file.seekg(0, std::ios::beg);

    // Creation de la partie à partir du fichier
    int y = 0;
    while (std::getline(file, line)) {
        for (int x = 0; x < line.length(); x++) {
            char c = line[x];
            switch (c) {
                case 'O':
                    map[{x, y}] = ' ';
                    break;
                case 'F':
                    map[{x, y}] = ' ';
                    d_fauves.push_back(Fauve(x, y));
                    break;
                case 'P':
                    map[{x, y}] = ' ';
                    d_pieges.push_back(Piege(x, y));
                    break;
                case 'J':
                    std::cout << x << " " << y << std::endl;
                    map[{x, y}] = ' ';
                    d_joueur = Joueur(x, y);
                    break;
            }
        }
        y++;
    }
}








