#include "../includes/sun.hpp"

Sun::Sun(Vector2i init_pos){
    pos = init_pos;
    should_be_removed = false;

    if(!texture.loadFromFile(PICS_PATH + "sun.png")) {
        debug("failed to load sun texture");
    }

    sprite.setTexture(texture);
    sprite.setScale(0.5, 0.5);

    IntRect rect;
    rect.width = 250; 
    rect.height = 250;
    sprite.setTextureRect(rect);
    sprite.setPosition((Vector2f)init_pos);
}

Sun::~Sun(){

}

void Sun::update(){
    
}

void Sun::render(RenderWindow& window){
    window.draw(sprite);
}

void Sun::check_if_is_touched(Vector2i mouse_pos){
    if(sprite.getGlobalBounds().contains((Vector2f)mouse_pos)){
        should_be_removed = true;
    }
}

bool Sun::get_shoud_be_removed(){
    return should_be_removed;
}

DynamicSun::DynamicSun(Vector2i pos) : Sun(pos) {
    speed = 1;
}

void DynamicSun::check_if_is_outside(){
    if(pos.y > HEIGHT){
        should_be_removed = true;
    }
}

void DynamicSun::update(){
    pos.y += speed;
    sprite.setPosition((Vector2f)pos);

    check_if_is_outside();
}

StaticSun::StaticSun(Vector2i pos) : Sun(pos) {
    spawnTime = 10;
}

void StaticSun::check_if_spawn_time_spent(){
    
}

void StaticSun::update(){
    check_if_spawn_time_spent();
}