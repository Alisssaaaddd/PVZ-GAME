#pragma once

#include "consts.hpp"

class Zombie{
public:
    Zombie(Vector2f pos);
    ~Zombie();
    void render(RenderWindow &window);
    void update();
    FloatRect get_rect();
private: 
    Clock clock;
    const float speed = 1.2;
    Texture texture;
    Sprite sprite;
    Vector2f pos;
    int poses[4] = {0, 50, 102, 152};
    int cur_rect = 0;
};

// class Zombie
// {
// protected:
//     int health;
//     int speed=2;
//     // int eatDamage;
//     bool is_dead;
//     Texture texture;
//     Sprite sprite;
//     IntRect rect;
//     Vector2f pos;
//     Clock clock;
//     // int poses[4] = {0, 50, 102, 152};
//     // int cur_rect = 0;

// public:
//     Zombie(Vector2f init_pos);
//     ~Zombie();
//     virtual void update();
//     // virtual int get_health();
//     void render(RenderWindow &window);
//     FloatRect get_rect();
// };

// class OrdZombie : public Zombie
// {
// private:
// public:
//     OrdZombie(Vector2f pos);
//     ~OrdZombie(){};
//     void update();
// };

// class HugeZombie : public Zombie
// {
// private:
// public:
//     HugeZombie(Vector2f pos);
//     ~HugeZombie(){};
//     void update();
// };
