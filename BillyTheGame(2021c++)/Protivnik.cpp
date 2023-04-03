#include "Protivnik.h"


    Texture Tzombie;
    Sprite Szombie;

    Sprite protivnik;
    Vector2f TrenutnaBrzina;
    float maxBrzina;
    Protivnik::Protivnik(std::string a) : TrenutnaBrzina(7.f, 7.f), maxBrzina(4)
    {


        Tzombie.loadFromFile(a);
        protivnik.setTextureRect(IntRect(0, 0, 96, 96));
        protivnik.setTexture(Tzombie);

    }
