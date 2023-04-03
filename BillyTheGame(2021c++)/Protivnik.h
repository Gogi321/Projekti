#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Protivnik //zombie
{
private:
    Texture Tzombie;
    Sprite Szombie;
public:
    Sprite protivnik;
    Vector2f TrenutnaBrzina;
    float maxBrzina;
    Protivnik(std::string a);

};