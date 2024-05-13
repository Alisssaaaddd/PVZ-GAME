#include "../includes/shot.hpp"

Shot::Shot(Vector2f init_pos)
{
    pos = init_pos;
}

Shot::~Shot()
{
}

void Shot::render(RenderWindow &window)
{
    window.draw(sprite);
}

void Shot::update()
{
}

bool Shot::is_out()
{
    return sprite.getPosition().x > WIDTH + 50;
}

FloatRect Shot::get_rect(){
    return sprite.getGlobalBounds();
}

OrdShot::OrdShot(Vector2f init_pos) : Shot(init_pos)
{
    if (!texture.loadFromFile(PICS_PATH + "tir.png"))
    {
        debug("failed to load player texture");
    }
    sprite.setTexture(texture);
    sprite.setScale(0.7, 0.7);
    sprite.setPosition(pos);
}

OrdShot::~OrdShot()
{
}

void OrdShot::update()
{
    pos.x += speed;
    sprite.setPosition(pos);
}

IceShot::IceShot(Vector2f init_pos) : Shot(init_pos)
{
    if (!texture.loadFromFile(PICS_PATH + "tir.png"))
    {
        debug("failed to load player texture");
    }
    sprite.setTexture(texture);
    sprite.setScale(0.7, 0.7);
    sprite.setPosition(pos);
}

IceShot::~IceShot()
{
}

void IceShot::update()
{
    pos.x += speed;
    sprite.setPosition(pos);
}

MelonShot::MelonShot(Vector2f init_pos) : Shot(init_pos)
{
    if (!texture.loadFromFile(PICS_PATH + "tir.png"))
    {
        debug("failed to load player texture");
    }
    sprite.setTexture(texture);
    sprite.setScale(0.7, 0.7);
    sprite.setPosition(pos);
}

MelonShot::~MelonShot()
{
}

void MelonShot::update()
{
    pos.x += speed;
    sprite.setPosition(pos);
}
