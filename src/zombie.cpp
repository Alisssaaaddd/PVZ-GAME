#include "../includes/zombie.hpp"

Zombie::Zombie(Vector2f init_pos,string init_id ,
               int damage, int init_health, int init_hitRate, int init_speed, int numofLine){
    pos = init_pos;
    eatDamage = damage;
    health = init_health;
    hitRate = init_hitRate;
    speed = init_speed;
    lineNumber = numofLine;
    id = init_id;
}
  
Zombie::~Zombie(){

}

void Zombie::render(RenderWindow &window){
    window.draw(sprite);
}

void Zombie::update(){

}

FloatRect Zombie::get_rect(){
    return sprite.getGlobalBounds();
}

int Zombie::get_line_number(){
    return lineNumber;
}

int Zombie::get_x(){
    return pos.x;
}

int Zombie::get_speed(){
    return speed;
}

void Zombie::reduce_health(int damage){
    health -= damage;
}

bool Zombie::is_dead(){
    return health <= 0;
}

bool Zombie::is_gone_in_the_house(){
    return pos.x <= 540;
}


OrdZombie::OrdZombie(Vector2f init_pos, string init_id, int damage, int init_health, int init_hitRate, int init_speed, int numofLine) :
                     Zombie(init_pos, init_id, damage, init_health, init_hitRate, init_speed, numofLine)
{
    pos = init_pos;

    if (!texture.loadFromFile(PICS_PATH + id + "/walking/1.png"))
    {
        debug("failed to load zombie texture");
    }

    sprite.setTexture(texture);
    sprite.setScale(0.2, 0.2);
    sprite.setPosition(init_pos);
}

void OrdZombie::update()
{
    pos.x -= speed;
    sprite.setPosition(pos);
}

HugeZombie::HugeZombie(Vector2f init_pos, string init_id, int damage, int init_health, int init_hitRate, int init_speed, int numofLine) :
                       Zombie(init_pos, init_id, damage, init_health, init_hitRate, init_speed, numofLine)
{
    pos = init_pos;

    if (!texture.loadFromFile(PICS_PATH + "Gargantuar.png"))
    {
        debug("failed to load zombie texture");
    }

    sprite.setTexture(texture);
    sprite.setScale(0.4, 0.4);
    sprite.setPosition(init_pos);
}

void HugeZombie::update()
{
    pos.x -= speed;
    sprite.setPosition(pos);
}
