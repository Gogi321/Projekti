#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Bullet //bullet
{


public:
    Bullet();
    CircleShape bullet;
    Vector2f TrenutnaBrzina;
    float maxBrzina;
    Bullet(float radius );

};

