#pragma once

#include "consts.hpp"

class Sun{
protected:
    int credit;
    bool should_be_removed;
    Texture texture;
    Sprite sprite;
    IntRect rect;
    Vector2i pos;

public:
    Sun(Vector2i init_pos);
    ~Sun();
    void check_if_is_touched(Vector2i mouse_pos);
    virtual void update();
    void render(RenderWindow& window);
    bool get_shoud_be_removed();
};

class DynamicSun : public Sun{
    private:
        int speed;
    public:
        DynamicSun(Vector2i pos);
        ~DynamicSun() {};
        void check_if_is_outside();
        void update();
};

class StaticSun : public Sun{
    private:
        int spawnTime;
    public:
        StaticSun(Vector2i pos);
        ~StaticSun() {};
        void check_if_spawn_time_spent();
        void update();
};