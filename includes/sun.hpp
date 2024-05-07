#pragma once

#include "consts.hpp"

class Sun{
private:
    int credit;
    Texture texture;
    Sprite sprite;
    IntRect rect;
    Vector2i pos;

public:
    Sun(Vector2i init_pos);
    bool is_outside();
    void update();
    void render(RenderWindow& window);

};