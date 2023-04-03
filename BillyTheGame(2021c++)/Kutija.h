#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class kutija { //limiti
private:
    Sprite kSprite;
    Texture kText;

public:
    kutija();
    kutija(std::string Lokaciaja, int a, int b, int c, int d);


    void CrtajKutiju(RenderWindow& window);

        FloatRect k();
 




};