#include <iostream>
#include <map>
#include "Joueur.h"
#include "Fauve.h"
#include "Piege.h"
#include "Jeu.h"
#include <conio.h>


using namespace std;



bool isCaptured(const Joueur& joueur, const std::vector<Fauve>& fauves) {
  // V�rifie si le joueur a �t� captur� par un fauve
  for (const auto& fauve : fauves) {
    if (joueur.x() == fauve.x() && joueur.y() == fauve.y()) {
      return true;
    }
  }

  return false;
}

bool isTrapped(const Joueur& joueur, const std::vector<Piege>& pieges) {
    //V�rifie si le joueur est tomb� dans un pi�ge
    for (const auto& piege : pieges) {
      if (joueur.x() == piege.x() && joueur.y() == piege.y()) {
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
        partie.printMap(partie.renvoieMap(), partie.renvoieJoueur(), partie.fauves(), partie.pieges());

        while(true) {
            char input;
            std::cout << "Entrez une direction :                                                         Score :    " << partie.score() << std::endl;
            std::cout << "                              ^" << std::endl;
            std::cout << "                              Z" << std::endl;
            std::cout << "                         < Q  S  D >" << std::endl;
            input = getch();

            // D�place le joueur
            partie.deplaceJoueur(input, partie.mapHeight(), partie.mapWidth());

            std::cout << partie.renvoieJoueur().x() << std::endl;
            std::cout << partie.renvoieJoueur().y() << std::endl;

            partie.deplaceFauves(partie.renvoieJoueur(), partie.pieges());

            // V�rifie si le joueur a �t� captur� par un fauve
            if (isCaptured(partie.renvoieJoueur(), partie.fauves())) {
                std::cout << "Vous avez ete mange par un fauve !                         Score finale :  " << partie.score() << std::endl;
                break;
            }

            if (isTrapped(partie.renvoieJoueur(), partie.pieges())) {
                std::cout << "Vous etes tombe dans un piege et avez perdu !              Score finale :  " << partie.score() << std::endl;
                break;
            }

            partie.ajouterScore(10);

            //Verifie si le joueur a gagn�
            if (!partie.fauvesRestants()) {
                std::cout << "Bravo vous avez gagne !                                     Score final :  " << partie.score() << std::endl;
                break;
            }

            // Rafra�chit et affiche la carte
            partie.printMap(partie.renvoieMap(), partie.renvoieJoueur(), partie.fauves(), partie.pieges());

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
