#pragma once

#include <SFML/Graphics.hpp>
using namespace sf;
class Billy //igrac
{
private:
    sf::Texture billy;
    sf::Sprite player;

public:
    Billy();

    Billy(std::string Lokaciaja);

    void CrtajBilly(RenderWindow& window);
    void hodanje(char gumb, float Brzina);

    
    Vector2f Pozicija();
    void PozicijaP(Vector2f b);
    FloatRect p();
};