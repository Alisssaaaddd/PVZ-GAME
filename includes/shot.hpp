#pragma once

#include "consts.hpp"

class Shot
{
protected:
    Texture texture;
    Sprite sprite;
    IntRect rect;
    Vector2f pos;
    int damage;
    int speed;
    int lineNumber;
public:
    Shot(Vector2f init_pos, int init_damage, int init_speed, int numOfLine);
    ~Shot();
    FloatRect get_rect();
    virtual void update();
    void render(RenderWindow &window);
    bool is_out();
    int get_line_number();
    int get_damage();
};

class OrdShot : public Shot
{
private:
public:
    OrdShot(Vector2f init_pos, int init_damage, int init_speed, int numOfLine);
    ~OrdShot();
    void update();
};

class IceShot : public Shot
{
private:
public:
    IceShot(Vector2f init_pos, int init_damage, int init_speed, int numOfLine);
    ~IceShot();
    void update();
};

class MelonShot : public Shot
{
private:
public:
    MelonShot(Vector2f init_pos, int init_damage, int init_speed, int numOfLine);
    ~MelonShot();
    void update();
};