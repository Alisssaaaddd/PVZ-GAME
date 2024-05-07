#pragma once

#include "zombie.hpp"
#include "plant.hpp"
#include "shot.hpp"
#include "sun.hpp"

class Controller{
    private:
        mt19937 rng;
        Clock clock, sunClock, zombieClock;
        vector<Zombie*> zombies;
        vector<Shot*> shots;
        vector<Plant*> plants;
        vector<Sun*> suns;

    public:
        Controller();
        void draw_sun_random();
        void draw_sun(Vector2i sunFlowerPos);
        

};