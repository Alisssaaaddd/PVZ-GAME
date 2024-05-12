#pragma once

#include "consts.hpp"

class WhiteBlock
{
private:
    bool ready_to_show;
    Texture texture;
    Sprite sprite;
    Vector2i pos;

public:
    WhiteBlock(Vector2f show_pos);
    ~WhiteBlock();
    void render(RenderWindow &window);
    bool get_ready_to_show();
    void change_pos(Vector2f pos);
    void show();
    void hide();
};