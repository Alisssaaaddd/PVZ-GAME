#include "../includes/plant.hpp"

Plant::Plant(Vector2f p){
    pos = Vector2f(p.x, p.y - 20);
}

Plant::~Plant(){

}

Vector2f Plant::get_pos(){
    return pos;
}

void Plant::update(){

}

void Plant::render(RenderWindow& window){
    window.draw(sprite);
}

string Plant::get_id(){
    return id;
}

SunFlower::SunFlower(Vector2f p, int rate) : Plant(p){
    id = SUN_FLOWER_ID;
    produceRate = rate;

    if(!texture.loadFromFile(PICS_PATH + "sunflower.png")) {
        debug("failed to load sunflower texture");
    }
    texture.setSmooth(true);
    sprite.setTexture(texture);
    sprite.setScale(0.6, 0.6);
    
    sprite.setPosition(pos);
}

SunFlower::~SunFlower(){

}

bool SunFlower::should_produce_sun(){
    Time elapsed = produceClock.getElapsedTime();

    if(elapsed.asSeconds() >= produceRate){
        produceClock.restart();
        return true;
    }

    return false;
}

void SunFlower::update(){

}

PeaShooter::PeaShooter(Vector2f p, int rate) : Plant(p){
    id = PEA_SHOOTER_ID;
    hitRate = rate;

    if(!texture.loadFromFile(PICS_PATH + id + "/1.png")) {
        debug("failed to load peashooter texture");
    }
    texture.setSmooth(true);
    sprite.setTexture(texture);
    sprite.setScale(0.3, 0.3);
    
    sprite.setPosition(pos);
}

PeaShooter::~PeaShooter(){

}

bool PeaShooter::should_shoot(){
    Time elapsed = shootClock.getElapsedTime();

    if(elapsed.asSeconds() >= hitRate){
        shootClock.restart();
        return true;
    }

    return false;
}

void PeaShooter::update(){

}

IcePeaShooter::IcePeaShooter(Vector2f p, int rate) : Plant(p){
    id = ICE_PEA_SHOOTER_ID;
    hitRate = rate;

    if(!texture.loadFromFile(PICS_PATH + id + "/1.png")) {
        debug("failed to load IcePeaShooter texture");
    }
    texture.setSmooth(true);
    sprite.setTexture(texture);
    sprite.setScale(0.3, 0.3);
    
    sprite.setPosition(pos);
}

IcePeaShooter::~IcePeaShooter(){

}

bool IcePeaShooter::should_shoot(){
    Time elapsed = shootClock.getElapsedTime();

    if(elapsed.asSeconds() >= hitRate){
        shootClock.restart();
        return true;
    }

    return false;
}

void IcePeaShooter::update(){

}

Walnut::Walnut(Vector2f p) : Plant(p){
    id = WALNUT_ID;

    if(!texture.loadFromFile(PICS_PATH + id + "/1.png")) {
        debug("failed to load Walnut texture");
    }
    texture.setSmooth(true);
    sprite.setTexture(texture);
    sprite.setScale(0.5, 0.5);
    
    sprite.setPosition(pos);
}

Walnut::~Walnut(){

}

void Walnut::update(){

}

MelonPalt::MelonPalt(Vector2f p, int rate) : Plant(p){
    id = MELONPALT_ID;
    hitRate = rate;

    if(!texture.loadFromFile(PICS_PATH + id + "/1.png")) {
        debug("failed to load MelonPalt texture");
    }
    texture.setSmooth(true);
    sprite.setTexture(texture);
    sprite.setScale(0.3, 0.3);
    
    sprite.setPosition(pos);
}

MelonPalt::~MelonPalt(){

}

bool MelonPalt::should_shoot(){
    Time elapsed = shootClock.getElapsedTime();

    if(elapsed.asSeconds() >= hitRate){
        shootClock.restart();
        return true;
    }
    
    return false;
}

void MelonPalt::update(){

}
