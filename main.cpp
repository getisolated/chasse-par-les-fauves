#include <iostream>
#include <map>
#include "Joueur.h"
#include "Fauve.h"
#include "Piege.h"
#include "Jeu.h"
#include "map.h"
#include <conio.h>


using namespace std;

bool isCaptured(const Joueur& joueur, const std::vector<Fauve>& fauves) {
  // V�rifie si le joueur a �t� captur� par un fauve
  for (const auto& fauve : fauves) {
    if (joueur.x == fauve.x && joueur.y == fauve.y) {
      return true;
    }
  }

  return false;
}

bool isTrapped(const Joueur& joueur, const std::vector<Piege>& pieges) {
    //V�rifie si le joueur est tomb� dans un pi�ge
    for (const auto& piege : pieges) {
      if (joueur.x == piege.x && joueur.y == piege.y) {
        return true;
      }
    }

    return false;
}

int main()
{
    Joueur bouffon(MAP_WIDTH/2,MAP_HEIGHT/2);

    std::vector<std::pair<int, int>> fauves;
    fauves.push_back({2,2});
    fauves.push_back({MAP_WIDTH-3,2});
    fauves.push_back({2,MAP_HEIGHT-3});
    fauves.push_back({MAP_WIDTH-3,MAP_HEIGHT-3});

    std::vector<std::pair<int, int>> pieges;
    pieges.push_back({MAP_WIDTH/4,MAP_HEIGHT/4});
    pieges.push_back({3*MAP_WIDTH/4,MAP_HEIGHT/4});
    pieges.push_back({MAP_WIDTH/4,3*MAP_HEIGHT/4});
    pieges.push_back({3*MAP_WIDTH/4,3*MAP_HEIGHT/4});

    Jeu partie(bouffon, fauves, pieges);

    partie.initMap(partie.map);
    partie.printMap(partie.map, partie.joueur, partie.fauves, partie.pieges);

    while(true) {
        char input;
        std::cout << "Entrez une direction :" << std::endl;
        std::cout << "                              ^" << std::endl;
        std::cout << "                              Z" << std::endl;
        std::cout << "                         < Q  S  D >" << std::endl;
        input = getch();

        // D�place le joueur
        partie.joueur.deplace(input);

        for( auto& fauve : partie.fauves) {
            fauve.deplace(partie.joueur, partie.pieges);
        }

        // V�rifie si le joueur a �t� captur� par un fauve
        if (isCaptured(partie.joueur, partie.fauves)) {
            std::cout << "Vous avez ete capture par un fauve !" << std::endl;
            break;
        }

        if (isTrapped(partie.joueur, partie.pieges)) {
            std::cout << "Vous etes tombe dans un piege et avez perdu !" << std::endl;
            break;
        }

        // Rafra�chit et affiche la carte
        partie.printMap(partie.map, partie.joueur, partie.fauves, partie.pieges);

    }

    return 0;
}
