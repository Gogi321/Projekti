#include "Kutija.h"



    Sprite kSprite;
    Texture kText;


    
    
    kutija::kutija(std::string Lokaciaja, int a, int b, int c, int d)
    {
        kText.loadFromFile(Lokaciaja);
        kSprite.setTextureRect(IntRect(0, 0, c, d));
        kSprite.setTexture(kText);

        kSprite.setPosition(Vector2f(a, b));
    }
        void kutija::CrtajKutiju(RenderWindow & window)
        {

            window.draw(kSprite);
        }
        FloatRect kutija::k()
        {
            FloatRect z = kSprite.getGlobalBounds();
            return z;
        }
