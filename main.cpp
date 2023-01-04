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
  // Vérifie si le joueur a été capturé par un fauve
  for (const auto& fauve : fauves) {
    if (joueur.x == fauve.x && joueur.y == fauve.y) {
      return true;
    }
  }

  return false;
}

bool isTrapped(const Joueur& joueur, const std::vector<Piege>& pieges) {
    //Vérifie si le joueur est tombé dans un piège
    for (const auto& piege : pieges) {
      if (joueur.x == piege.x && joueur.y == piege.y) {
        return true;
      }
    }

    return false;
}

int main()
{

    bool rejouer = true;
    while(rejouer) {

        std::string fichierPartie;
        std::cout << "Entrez le nom du fichier du niveau (exemple Niveau1, Niveau2, Niveau3) : ";
        std::cin >> fichierPartie;

        Jeu partie(fichierPartie + ".txt");
        std::cout << partie.mapHeight << " " << partie.mapWidth << std::endl;
        std::cout << partie.joueur.x << " " << partie.joueur.y << std::endl;
        partie.printMap(partie.map, partie.joueur, partie.fauves, partie.pieges);

        while(true) {
            char input;
            std::cout << "Entrez une direction :                                                         Score :    " << partie.score << std::endl;
            std::cout << "                              ^" << std::endl;
            std::cout << "                              Z" << std::endl;
            std::cout << "                         < Q  S  D >" << std::endl;
            input = getch();

            // Déplace le joueur
            partie.joueur.deplace(input, partie.mapHeight, partie.mapWidth);

            for( auto& fauve : partie.fauves) {
                fauve.deplace(partie.joueur, partie.pieges);
            }

            // Vérifie si le joueur a été capturé par un fauve
            if (isCaptured(partie.joueur, partie.fauves)) {
                std::cout << "Vous avez ete mange par un fauve !                         Score finale :  " << partie.score << std::endl;
                break;
            }

            if (isTrapped(partie.joueur, partie.pieges)) {
                std::cout << "Vous etes tombe dans un piege et avez perdu !              Score finale :  " << partie.score << std::endl;
                break;
            }

            partie.ajouterScore(10);

            //Verifie si le joueur a gagné
            if (!partie.fauvesRestants()) {
                std::cout << "Bravo vous avez gagne !                                     Score final :  " << partie.score << std::endl;
                break;
            }

            // Rafraîchit et affiche la carte
            partie.printMap(partie.map, partie.joueur, partie.fauves, partie.pieges);

        }

        std::cout << "Voulez-vous rejouer ? (o/n)";
        char input;
        std::cin >> input;
        if (input == 'n') {
            rejouer = false;
        }

    }

    return 0;
}
