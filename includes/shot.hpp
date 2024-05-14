#pragma once

#include "consts.hpp"

class Shot
{
protected:
    Texture texture;
    Sprite sprite;
    IntRect rect;
    Vector2f pos;
    int damage = 3;
    int speed = 2;
    int lineNumber = 1;
public:
    Shot(Vector2f init_pos);
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
    OrdShot(Vector2f init_pos);
    ~OrdShot();
    void update();
};

class IceShot : public Shot
{
private:
public:
    IceShot(Vector2f init_pos);
    ~IceShot();
    void update();
};

class MelonShot : public Shot
{
private:
public:
    MelonShot(Vector2f init_pos);
    ~MelonShot();
    void update();
};