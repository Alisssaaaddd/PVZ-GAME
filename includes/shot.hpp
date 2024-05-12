#pragma once

#include "consts.hpp"

class Shot
{
protected:
    Texture texture;
    Sprite sprite;
    IntRect rect;
    Vector2i pos;
    int damage;
    int speed = 2;

public:
    Shot();
    ~Shot();
    FloatRect get_rect();
    virtual void update();
    bool is_out();
};

class OrdShot : public Shot
{
private:
public:
    void update();
};

class IceShot : public Shot
{
private:
public:
    void update();
};
