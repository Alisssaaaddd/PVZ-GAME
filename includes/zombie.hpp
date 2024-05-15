#pragma once

#include "consts.hpp"

class Zombie
{
protected:
    int health = 10;
    int speed = 2;
    int lineNumber = 1;
    int hitRate;
    int eatDamage;
    Texture texture;
    string id;
    Sprite sprite;
    IntRect rect;
    Vector2f pos;
    Clock clock;
    // int poses[4] = {0, 50, 102, 152};
    // int cur_rect = 0;

public:
    Zombie(Vector2f init_pos, string init_id, int damage, int init_health, int init_hitRate, int init_speed, int numofLine);
    ~Zombie();
    virtual void update();
    bool is_dead();
    void render(RenderWindow &window);
    FloatRect get_rect();
    int get_line_number();
    void reduce_health(int damage);
};

class OrdZombie : public Zombie
{
private:
public:
    OrdZombie(Vector2f init_pos, string init_id, int damage, int init_health, int init_hitRate, int init_speed, int numofLine);
    ~OrdZombie(){};
    void update();
};

class HugeZombie : public Zombie
{
private:
public:
    HugeZombie(Vector2f init_pos, string init_id, int damage, int init_health, int init_hitRate, int init_speed, int numofLine);
    ~HugeZombie(){};
    void update();
};
