#pragma once

#include "consts.hpp"

class Plant
{
private:
    int health;
    int cost;
    int shotRate;
    Texture texture;
    Sprite sprite;
    IntRect rect;
    Vector2i pos;
public:
    Plant(Vector2i pos);
    ~Plant();
};

