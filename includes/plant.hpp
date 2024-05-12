#pragma once

#include "consts.hpp"

class Plant{
protected:
    int health;
    int cost;
    string id;
    Texture texture;
    Sprite sprite;
    Vector2f pos;
public:
    Plant(Vector2f p);
    ~Plant();
    Vector2f get_pos();
    string get_id();
    virtual void update();
    void render(RenderWindow& window);
};

class SunFlower : public Plant{
    private:
        Clock produceClock;
        int produceRate;
    public:
        SunFlower(Vector2f p, int rate);
        ~SunFlower();
        void update();
        bool should_produce_sun();
};

class PeaShooter : public Plant{
    private:
        Clock shootClock;
        int hitRate;
    public:
        PeaShooter(Vector2f p, int rate);
        ~PeaShooter();
        void update();
        bool should_shoot();
};
class IcePeaShooter : public Plant{
    private:
        Clock shootClock;
        int hitRate;
    public:
        IcePeaShooter(Vector2f p, int rate);
        ~IcePeaShooter();
        void update();
        bool should_shoot();
};

class Walnut : public Plant{
    private:
        
    public:
        Walnut(Vector2f p);
        ~Walnut();
        void update();
};

class MelonPalt : public Plant{
    private:
        Clock shootClock;
        int hitRate;
    public:
        MelonPalt(Vector2f p, int rate);
        ~MelonPalt();
        void update();
        bool should_shoot();
};