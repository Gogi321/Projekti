#include "Billy.h"

    Texture billy;
    Sprite player;
    Billy:: Billy()
    {}
    Billy::Billy(std::string Lokaciaja)
    {
        billy.loadFromFile(Lokaciaja);
        player.setTextureRect(IntRect(0, 0, 96, 96));
        player.setTexture(billy);
    }
    void  Billy::CrtajBilly(RenderWindow& window)
    {

        window.draw(player);

    }

    void  Billy::hodanje(char gumb, float Brzina)
    {

        if (gumb == 'u') {
            player.move(0, -Brzina);

        }
        if (gumb == 'd') {
            player.move(0, Brzina);
        }
        if (gumb == 'l') {
            player.move(-Brzina, 0);
        }
        if (gumb == 'r') {
            player.move(Brzina, 0);
        }
    }
    Vector2f  Billy::Pozicija()
    {
        Vector2f a;
        a = player.getPosition();
        a.x += 86;
        a.y += 54;
        return a;
    }
    void  Billy::PozicijaP(Vector2f b)
    {
        player.setPosition(b);

    }
    FloatRect  Billy::p()
    {
        FloatRect z = player.getGlobalBounds();
        return z;
    }
