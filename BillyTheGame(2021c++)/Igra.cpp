#include <SFML/Graphics.hpp>
#include<math.h>
#include<iostream>
#include<vector>
#include<stdlib.h>
#include<ctime>
#include<string>
#include"Billy.h"
#include"Kutija.h"
#include"Protivnik.h"

using namespace sf;

class Bullet //bullet
{


public:

    CircleShape bullet;
    Vector2f TrenutnaBrzina;
    float maxBrzina;
    Bullet(float radius = 5.5) : TrenutnaBrzina(0.f, 0.f), maxBrzina(10.f)
    {
        bullet.setRadius(radius);
        bullet.setFillColor(Color::Red);
    }


};



int generirajSlucajniBroj(int donjaGranica, int gornjaGranica)
{
    return rand() % (gornjaGranica - donjaGranica + 1) + donjaGranica;
}

int main()
{
    float sat = 3;
    sf::Text mytext;
    int pp = 1;
    int bodovi = 0; //bodovi
    sf::Clock clock;  //sat za metak
    float respawn_timer;  //respawn zombija
    Billy Igrac("Slike/Billy.png"); //ocitavanje objekta billy
    Igrac.PozicijaP(Vector2f(120, 120)); //pocetna pozicija
    //ucitavanje granice
    kutija gornja("Slike/235.png", 0, 0, 1280, 50);
    kutija lijeva("Slike/vkutije.png", 0, 0, 50, 720);
    kutija desna("Slike/vkutije.png", 1230, 0, 50, 720);
    kutija donja("Slike/235.png", 0, 670, 1280, 50);
    srand(time(NULL)); //slucajni brojeva

    //przor
    RenderWindow window(sf::VideoMode(1280, 720), "| Arcade Igra |");
    window.setFramerateLimit(60);
    //pozadina 
    sf::Texture BackgroundTexture;
    sf::Sprite background;
    sf::Vector2u TextureSize;
    sf::Vector2u WindowSize;

    if (!BackgroundTexture.loadFromFile("Slike/Pozadian.jpg")) //provjera postojanja
    {
        return -1;
    }
    else
    {
        TextureSize = BackgroundTexture.getSize(); //Get size of texture.
        WindowSize = window.getSize();             //Get size of window.

        float ScaleX = (float)WindowSize.x / TextureSize.x;
        float ScaleY = (float)WindowSize.y / TextureSize.y;     //Calculate scale.

        background.setTexture(BackgroundTexture);
        background.setScale(ScaleX, ScaleY);      //Set scale.  

    }

    //meci
    Bullet b1;
    std::vector<Bullet> bullets;

    //Protivnici
    Protivnik a1("Slike/zombie.png");
    std::vector<Protivnik> enemies;
    //tekst za end i loadanje fonta
    sf::Text text;
    sf::Font font;
    font.loadFromFile("ARIAL.ttf");

    //vectori za gađanje
    Vector2f Centar;
    Vector2f Pozicija;
    Vector2f gadanje;
    Vector2f aumDirNorm;
    Vector2f micanje;
    Vector2f poz;
    Vector2f a;
    Vector2f LokacijaProtivnika;
    int timer = 0;
    while (window.isOpen())
    {
        sat = clock.getElapsedTime().asSeconds();
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //update
        Centar = Igrac.Pozicija(), Igrac.Pozicija();
        Pozicija = Vector2f(Mouse::getPosition(window));
        gadanje = Pozicija - Centar;
        aumDirNorm = gadanje / sqrt(pow(gadanje.x, 2) + pow(gadanje.y, 2));


        LokacijaProtivnika = Vector2f(a1.protivnik.getPosition().x, a1.protivnik.getPosition().y);
        micanje = Centar - LokacijaProtivnika;
        a = micanje / sqrt(pow(micanje.x, 2) + pow(micanje.y, 2));

        //player hodanje i setanje limita

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            Igrac.hodanje('u', 6.0);
            if (Igrac.Pozicija().y < 93)
                Igrac.hodanje('u', -10.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            Igrac.hodanje('d', 6.0);
            if (Igrac.Pozicija().y > 640)
                Igrac.hodanje('d', -10.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            Igrac.hodanje('l', 6.0);
            if (Igrac.Pozicija().x < 120)
                Igrac.hodanje('l', -10.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            Igrac.hodanje('r', 6.0);
            if (Igrac.Pozicija().x > 1240)
                Igrac.hodanje('r', -10.f);
        }





        if (enemies.empty() == false) //provjera
        {
            if (a1.protivnik.getPosition() == Igrac.Pozicija())
            {
            }
            else
            {


                a1.TrenutnaBrzina = a * a1.maxBrzina;
                enemies[0].protivnik.move(a1.TrenutnaBrzina);

            }

        }
        else
        {//spawn

            int vrata = generirajSlucajniBroj(1, 4);

            if (vrata == 1)
            {
                a1.protivnik.setPosition(1240, 340);
                enemies.push_back(Protivnik(a1));

            }
            if (vrata == 2)
            {
                a1.protivnik.setPosition(40, 340);
                enemies.push_back(Protivnik(a1));

            }
            if (vrata == 3)
            {
                a1.protivnik.setPosition(700, 640);
                enemies.push_back(Protivnik(a1));

            }
            if (vrata == 4)
            {
                a1.protivnik.setPosition(700, 50);
                enemies.push_back(Protivnik(a1));

            }
        }


        //pucanje i pushanje metka u vektor
        if (Mouse::isButtonPressed(Mouse::Left))
        {
            if (sat > 1.5)
            {
                b1.bullet.setPosition(Centar);
                b1.TrenutnaBrzina = aumDirNorm * b1.maxBrzina;


                bullets.push_back(Bullet(b1));
                clock.restart();
            }
       
        }
        //crtanje
        window.clear();
        window.draw(background);

        if (enemies.empty() == false)
            window.draw(enemies[0].protivnik);
        Igrac.CrtajBilly(window);
        gornja.CrtajKutiju(window);
        donja.CrtajKutiju(window);
        lijeva.CrtajKutiju(window);
        desna.CrtajKutiju(window);

        //ponašanje metka
        for (size_t i = 0; i < bullets.size(); i++)
        {

            window.draw(bullets[i].bullet);
            b1.TrenutnaBrzina = aumDirNorm * b1.maxBrzina;
            bullets[i].bullet.move(bullets[i].TrenutnaBrzina);
            for (size_t k = 0; k < enemies.size(); k++)
            {
                if (bullets[i].bullet.getGlobalBounds().intersects(enemies[k].protivnik.getGlobalBounds()))
                {
                    bullets.erase(bullets.begin() + i);
                    enemies.erase(enemies.begin() + k);
                    //break
                    bodovi++;

                }


            }



            if (bullets.empty() == false && (bullets[i].bullet.getPosition().x > window.getSize().x - 53 || bullets[i].bullet.getPosition().y <  50 || bullets[i].bullet.getPosition().y > window.getSize().y - 53
                || bullets[i].bullet.getPosition().x < 50))
            {
                bullets.erase(bullets.begin() + i);
            }

        }

        std::string intStr = std::to_string(bodovi);
        mytext.setString(intStr);
        mytext.setCharacterSize(25); // in pixels, not points!
        mytext.setPosition(1200, 50);
        mytext.setFillColor(sf::Color::White);
        mytext.setFont(font);
        window.draw(text);
        window.draw(mytext);

        //limiti protivnika
        if (!enemies.empty())
        {
            if (enemies[0].protivnik.getPosition().y < 50)
            {
                enemies[0].protivnik.move(0, +6);

            }
            if (enemies[0].protivnik.getPosition().y > 600)
            {
                enemies[0].protivnik.move(0, -10.f);

            }
            if (enemies[0].protivnik.getPosition().x < 50)
            {
                enemies[0].protivnik.move(+6, 0);

            }
            if (enemies[0].protivnik.getPosition().x > 1150)
            {
                enemies[0].protivnik.move(-6, 0);

            }
            //defeat
            if (enemies[0].protivnik.getGlobalBounds().intersects(Igrac.p()))
            {
                std::cout << "a\n\n\n\n\n\n";
                pp = 0;

                while (pp == 0)
                {
                    window.clear(Color::Black);
                    std::string intStr = std::to_string(bodovi);
                    text.setString("Game Over\n\nPress space...");
                    text.setFont(font);
                    text.setCharacterSize(100);
                    text.setPosition(380, 260);
                    mytext.setString(intStr);
                    mytext.setCharacterSize(100);
                    mytext.setPosition(620, 400);
                    mytext.setFillColor(sf::Color::Red);
                    mytext.setFont(font);
                    window.draw(text);
                    window.draw(mytext);
                    window.display();
                    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Space)))
                    {

                        window.close();
                        break;
                    }
                }
            }
        }


        window.display();




    }

    return 0;
}





