#include "../includes/zombie.hpp"

Zombie::Zombie(Vector2f p){
    pos = p;
    if (!texture.loadFromFile(PICS_PATH + "Zombie_healthy.png")) {
        debug("failed to load zombie texture");
    }
    sprite.setTexture(texture);
    sprite.setScale(0.3, 0.3);  
    IntRect rect;
    rect.width = 291; 
    rect.height = 465;
    sprite.setTextureRect(rect);
}
       
Zombie::~Zombie(){

}

void Zombie::render(RenderWindow &window){
    window.draw(sprite);
}

void Zombie::update(){
    Time elapsed = clock.getElapsedTime();
    // if(elapsed.asMilliseconds() >= 300){
    //     clock.restart();
    //     // cur_rect = (cur_rect + 1) % 3;
    //     // IntRect rect;
    //     // rect.width = 34; 
    //     // rect.height = 62;
    //     // rect.left = poses[cur_rect];
    //     // sprite.setTextureRect(rect);
    // }
    pos.x -= speed;
    sprite.setPosition(pos);
}

FloatRect Zombie::get_rect(){
    return sprite.getGlobalBounds();
}

// Zombie::Zombie(Vector2f init_pos)
// {
//     pos = init_pos;

//     if (!texture.loadFromFile(PICS_PATH + "Zombie_healthy.png"))
//     {
//         debug("failed to load zombie texture");
//     }

//     sprite.setTexture(texture);
//     sprite.setScale(1.2, 1.2);
//     IntRect rect;
//     rect.width = 34;
//     rect.height = 62;
//     sprite.setTextureRect(rect);
//     sprite.setPosition(init_pos);
// }

// Zombie::~Zombie()
// {
// }

// void Zombie::update()
// {
// }

// // int Zombie::get_health()
// // {
// //     return health;
// // }

// void Zombie::render(RenderWindow &window)
// {
//     window.draw(sprite);
// }

// FloatRect Zombie::get_rect()
// {
//     return sprite.getGlobalBounds();
// }

// OrdZombie::OrdZombie(Vector2f init_pos) : Zombie(init_pos)
// {
//     pos = init_pos;

//     if (!texture.loadFromFile(PICS_PATH + "Zombie_healthy.png"))
//     {
//         debug("failed to load zombie texture");
//     }

//     sprite.setTexture(texture);
//     sprite.setScale(1.2, 1.2);
//     IntRect rect;
//     rect.width = 34;
//     rect.height = 62;
//     sprite.setTextureRect(rect);
//     sprite.setPosition(init_pos);
//     is_dead = false;
// }

// void OrdZombie::update()
// {
//     pos.x -= speed;
//     sprite.setPosition(pos);
// }

// HugeZombie::HugeZombie(Vector2f init_pos) : Zombie(init_pos)
// {
//     pos = init_pos;

//     if (!texture.loadFromFile(PICS_PATH + "Zombie_healthy.png"))
//     {
//         debug("failed to load zombie texture");
//     }

//     sprite.setTexture(texture);
//     sprite.setScale(1.2, 1.2);
//     IntRect rect;
//     rect.width = 34;
//     rect.height = 62;
//     sprite.setTextureRect(rect);
//     sprite.setPosition(init_pos);
//     is_dead = false;
// }
