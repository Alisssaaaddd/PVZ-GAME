#pragma once

#include "consts.hpp"

class Sun{
protected:
    int credit;
    bool should_be_removed;
    Texture texture;
    Sprite sprite;
    Vector2f pos;

public:
    Sun(Vector2f init_pos);
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
        DynamicSun(Vector2f pos);
        ~DynamicSun() {};
        void check_if_is_outside();
        void update();
};

enum PlaceSituation{
    GOING_UP,
    GOING_DOWN,
    ON_RIGHT_PLACE
};

class StaticSun : public Sun{
    private:
        PlaceSituation place;
        int spawnTime;
        int numOfMoves;
        Clock lifeClock;
    public:
        StaticSun(Vector2f pos, int s_time);
        ~StaticSun() {};
        void check_if_spawn_time_spent();
        void update();
};