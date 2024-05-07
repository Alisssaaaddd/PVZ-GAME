#pragma once

#include "consts.hpp"

class Zombie{
private:
    int health;
    int speed;
    int eatDamage;
    Texture texture;
    Sprite sprite;
    IntRect rect;
    Vector2i pos;
public:
    Zombie(Vector2i pos);
    ~Zombie();
};

