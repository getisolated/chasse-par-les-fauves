#include "doctest.h"
#include "../Chasse/Joueur.h"
#include "../Chasse/Fauve.h"

TEST_CASE("Les deplacements du joueur fonctionnent correctement")
{
    int height = 50, width = 50;
    int jx=10, jy=10;
    Joueur j{jx,jy};

    SUBCASE("test constructeur")
    {
        REQUIRE_EQ(j.x(),jx);
        REQUIRE_EQ(j.y(),jy);
    }
    SUBCASE(" Déplacer un joueur vers le haut fonctionne ")
    {
        j.deplace('z',height,width);
        REQUIRE_EQ(j.x(), jx );
    }
    SUBCASE(" Déplacer un joueur vers le bas fonctionne ")
    {
        j.deplace('s',height,width);
        REQUIRE_EQ(j.y(), jy+1 );
    }
     SUBCASE(" Déplacer un joueur vers la gauche fonctionne ")
    {

        j.deplace('q',height,width);
        REQUIRE_EQ(j.x(), jx-1 );
    }
    SUBCASE(" Déplacer un joueur vers la droite fonctionne ")
    {
        j.deplace('d',height,width);
        REQUIRE_EQ(j.x(), jx+1 );
    }
    SUBCASE(" Déplacer un joueur vers piège le tue")
    {
        std::vector<Piege>pieges(1);
        int px=11, py=10;
        pieges[0] = Piege{px,py};
        j.deplace('d',height,width);
        REQUIRE_EQ(j.x(), jx+1);

    }
    SUBCASE(" Déplacer un joueur vers un mur ne le fait pas bouger")
    {
        Joueur j{49,49};
        j.deplace('d',height,width);
        REQUIRE_FALSE(j.x() == 50);
    }


}
