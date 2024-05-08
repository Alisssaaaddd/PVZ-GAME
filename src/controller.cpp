#include "../includes/controller.hpp"


Controller::Controller(){
}

void Controller::handle_mouse_press(Vector2i mouse_pos){
    for(Sun* s : suns){
        s->check_if_is_touched(mouse_pos);
        if(s->get_shoud_be_removed()){
            totalCredit += SUN_CREDIT;
            return;
        }
    }

    //We'll add other objects later too ... .
}

void Controller::add_sun_random(){
    DynamicSun* s = new DynamicSun(Vector2i(rng() % WIDTH, 0));
    suns.push_back(s);
}

void Controller::add_sun_inposition(Vector2i sunFlowerPos){
    
}

void Controller::render(RenderWindow& window){
    for(Sun* s : suns){
        s->render(window);
    }
}

void Controller::update(){
    Time elapsed = sunClock.getElapsedTime();

    if(elapsed.asMilliseconds() >= 1000){
        sunClock.restart();
        add_sun_random();
    }

    for(Sun* s : suns){
        s->update();
    }
    remove_touched_and_outside_suns();
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