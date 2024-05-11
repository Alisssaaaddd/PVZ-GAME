#pragma once

#include "zombie.hpp"
#include "plant.hpp"
#include "shot.hpp"
#include "sun.hpp"

class Controller{
    private:
        mt19937 rng;
        Clock clock, sunClock, zombieClock;
        int totalCredit = 0;
        vector<Zombie*> zombies;
        vector<Shot*> shots;
        vector<Plant*> plants;
        vector<Sun*> suns;
    public:
        Controller();
        ~Controller();
        void render(RenderWindow& window);
        void update();
        void add_sun_random();
        void add_sun_inposition(Vector2i sunFlowerPos);
        void handle_mouse_press(Vector2i pos);
        void remove_touched_and_outside_suns();

        void add_zombie_random();
        // void remove_dead_zombie();
        // void handle_collision();
};