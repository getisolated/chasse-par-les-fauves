#include "doctest.h"
#include "../Chasse/Jeu.h"
#include <iostream>
#include <vector>


TEST_CASE("test de la classe jeu ")
{
    std::string nomfichier = "Niveau1.txt";
    Jeu j{nomfichier};

    SUBCASE("test de la fonction score")
    {
        SUBCASE("début de la partie")
        {
            REQUIRE_EQ(j.score(),0);

        }
        SUBCASE("ajouter un score")
        {
            int points = 20;
            j.ajouterScore(points);
            REQUIRE_EQ(j.score(),points);
        }
    }

}
