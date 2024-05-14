#pragma once

#include "zombie.hpp"
#include "plant.hpp"
#include "shot.hpp"
#include "sun.hpp"
#include "card.hpp"

class Controller{
    private:
        mt19937 rng;
        Clock clock, sunClock, zombieClock;
        int totalCredit = 0;
        vector<Zombie*> zombies;
        void update_zombies();
        vector<Shot*> shots;
        void update_shots();
        vector<Plant*> plants;
        void update_plants();
        vector<Sun*> suns;
        void update_suns();
        vector<Card*> cards;
        void update_cards(RenderWindow& window);

        vector<RectangleShape> blocks;
        int currentBlockIndex;
        bool should_draw_currentBlock;
    public:
        Controller();
        ~Controller();
        void render(RenderWindow& window);
        void update(RenderWindow& window);
        void add_sun_random();
        void add_sun_inposition(Vector2f sunFlowerPos);
        void handle_mouse_press(Vector2i pos);
        void handle_mouse_release(Vector2i pos);
        void initialize_blocks();

        void remove_touched_and_outside_suns();
        
        void add_zombie_random();

        void seed(Vector2f pos, string plantId);
        void add_shot(Vector2f init_pos, string plantId);
        void remove_outside_shots();

        void remove_dead_zombies(vector<Zombie*>& hurt_zombies);
        void handle_collisions();
};