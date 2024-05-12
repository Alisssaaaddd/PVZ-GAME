#include "../includes/controller.hpp"


Controller::Controller(){
    Card* sunFolwerCard = new Card("sunfloweractivecard.png", "sunflowerinactivecard.png",
     Vector2i(100, 100), 50, "sunflower.png");
    cards.push_back(sunFolwerCard);

    Plant* peashooter = new Walnut(Vector2f(590, 190));
    plants.push_back(peashooter);
}

void Controller::handle_mouse_press(Vector2i mouse_pos){
    for(Sun* s : suns){
        s->check_if_is_touched(mouse_pos);
        if(s->get_shoud_be_removed()){
            totalCredit += SUN_CREDIT;
            return;
        }
    }

    for(Card* c : cards){
        c->handle_mouse_press(mouse_pos);
        if(c->is_dragging()){
            return;
        }
    }
    //We'll add other objects later too ... .
}

void Controller::handle_mouse_release(Vector2i mouse_pos){
    for(Card* c : cards){
        c->handle_mouse_release(mouse_pos);
    }
    //We'll add other objects later too ... .
}

void Controller::add_sun_random(){
    DynamicSun* s = new DynamicSun(Vector2f(rng() % WIDTH, -100));
    suns.push_back(s);
}

void Controller::add_sun_inposition(Vector2f sunFlowerPos){
    StaticSun* s = new StaticSun(sunFlowerPos, 5);
    suns.push_back(s);
}

void Controller::render(RenderWindow& window){
    
    for(Plant* p : plants){
        p->render(window);
    }

    for(Card* c : cards){
        c->render(window);
    }

    for (Zombie* z : zombies){
        z->render(window);
    }

    for(Sun* s : suns){
        s->render(window);
    }
}

void Controller::update(RenderWindow& window){
    Time elapsed = sunClock.getElapsedTime();

    if(elapsed.asMilliseconds() >= 10000){
        sunClock.restart();
        add_sun_random();
    }

    for(Sun* s : suns){
        s->update();
    }
    remove_touched_and_outside_suns();

    Vector2i mouse_pos = Mouse::getPosition(window);
    for(Card* c : cards){
        c->update(totalCredit, mouse_pos);
    }

    Time zelapsed = zombieClock.getElapsedTime();

    if (zelapsed.asMilliseconds() >= 5000)
    {
        zombieClock.restart();
        add_zombie_random();
    }

    for (Zombie* z : zombies)
    {
        z->update();
    }

    for(Plant* p : plants){
        p->update();

        if(p->get_id() == SUN_FLOWER_ID){
            SunFlower* s = (SunFlower*) p;

            if(s->should_produce_sun()){
                add_sun_inposition(p->get_pos());
            }
        }
    }
}

void Controller::remove_touched_and_outside_suns(){
    vector<Sun*> removed;

    for (Sun* s : suns){
        if (s->get_shoud_be_removed()){
            removed.push_back(s);
        }
    }
    
    suns.erase(remove_if(suns.begin(), suns.end(), 
    [](Sun* p){ return p->get_shoud_be_removed(); }), suns.end());

    for (Sun* s : removed){
        delete(s);
    }
}

void Controller::add_zombie_random()
{
    int x_position = WIDTH - 20;
    int y_position = ((rng() % 5) * 150) + 90;
    int randZom = rng() % 2;
    Zombie* z;

    switch (randZom)
    {
    case 0:
        z = new OrdZombie(Vector2f(x_position, y_position+30));
        break;
    case 1:
        z = new HugeZombie(Vector2f(x_position, y_position));
        break;
    }

    zombies.push_back(z);
}

// void Controller::remove_dead_zombie(){

//     zombies.erase();

//     for (Sun *s : removed)
//     {
//         delete (s);
//     }
// }

// void Controller::handle_collision(){
//     vector <Shot*> trashp;
//     vector <Zombie*> trashz;
//     for(auto s : shots){
//         for(auto z : zombies){
//             FloatRect z_rect = z->get_rect();
//             FloatRect s_rect = s->get_rect();
//             if(z_rect.intersects(p_rect)){
//                 trashp.push_back(p);
//                 trashz.push_back(z);
//             }
//         }
//     }
//     for(auto p : trashp){
//         shots.erase(remove(shots.begin(), shots.end(), p), shots.end());
//         delete p;
//     }
//     for(auto z : trashz){
//         zombies.erase(remove(zombies.begin(), zombies.end(), z), zombies.end());
//         delete z;
//     }
// }