#include "doctest.h"
#include "../Chasse/Piege.h"
#include <iostream>
#include <vector>


TEST_CASE("test de la classe jeu ")
{


    int x=10; int y=20;
    Piege p{x,y};

    SUBCASE("test constructeur")
    {
         REQUIRE_EQ(p.y(),y);
         REQUIRE_EQ(p.x(),x);
    }
    SUBCASE("test constructeur par défaut")
    {
        Piege pdefaut{};
        REQUIRE_EQ(pdefaut.y(),-1);
        REQUIRE_EQ(pdefaut.x(),-1);

    }
    SUBCASE("modifie coordonnées")
    {
        int newX=15;
        int newY=25;
        p.modifieX(newX);
        p.modifieY(newY);
        REQUIRE_EQ(p.y(),newY);
        REQUIRE_EQ(p.x(),newX);
    }

}
