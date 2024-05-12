#include "../includes/white.hpp"

WhiteBlock::WhiteBlock(Vector2f show_pos)
{
    // if (mouse_pos.x >= 590 and mouse_pos.x <= 1760 and mouse_pos.y >= 220 and mouse_pos.y <= 1020)
    ready_to_show = false;
    if (!texture.loadFromFile(PICS_PATH + "white.png"))
    {
        debug("failed to load sun texture");
    }
    sprite.setTexture(texture);
    sprite.setScale(0.8, 0.8);
    sprite.setPosition(show_pos);
}

WhiteBlock::~WhiteBlock(){

}

void WhiteBlock::render(RenderWindow &window)
{
    window.draw(sprite);
}

bool WhiteBlock::get_ready_to_show()
{
    return ready_to_show;
}

void WhiteBlock::change_pos(Vector2f pos){
    sprite.setPosition(pos);
}

void WhiteBlock::show(){
    ready_to_show = true;
}

void WhiteBlock::hide(){
    ready_to_show = false;
}