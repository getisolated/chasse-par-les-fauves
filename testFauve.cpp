#include "doctest.h"
#include "../Chasse/Fauve.h"
#include <iostream>
#include <vector>

TEST_CASE("Test de la classe fauve")
{
     int height=50, width=50;
     int x=10;
     int y=10;
     Fauve f{x,y};
    SUBCASE("test constructeur")
     {
         REQUIRE_EQ(f.y(),y);
         REQUIRE_EQ(f.x(),x);
     }
    SUBCASE("test constructeur par défaut")
    {
        Fauve fdefaut{};
        REQUIRE_EQ(fdefaut.y(),-1);
        REQUIRE_EQ(fdefaut.x(),-1);

    }

    SUBCASE("Les fauves tombent bien dans le piège")
    {

        int jx=12, jy=10;
        int px=11; int py=10;
        Joueur j{jx,jy};

        std::vector<Piege>pieges(1);
        pieges[0] = Piege{px,py};

        f.deplace(j,pieges);
        REQUIRE_EQ(f.x(),-1);

    }

}

//
//f.deplace(j,pieges);
