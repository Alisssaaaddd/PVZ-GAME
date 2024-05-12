#include "../includes/controller.hpp"

Controller::Controller()
{
    Card *sunFolwerCard = new Card("sunfloweractivecard.png", "sunflowerinactivecard.png",
                                   Vector2i(100, 100), 50, "sunflower.png");
    cards.push_back(sunFolwerCard);
    wb = new WhiteBlock(Vector2f(100, 200));
}

void Controller::handle_mouse_press(Vector2i mouse_pos)
{
    for (Sun *s : suns)
    {
        s->check_if_is_touched(mouse_pos);
        if (s->get_shoud_be_removed())
        {
            totalCredit += SUN_CREDIT;
            return;
        }
    }

    for (Card *c : cards)
    {
        c->handle_mouse_press(mouse_pos);
        if (c->is_dragging())
        {
            return;
        }
    }
}

void Controller::handle_mouse_release(Vector2i mouse_pos)
{
    for (Card *c : cards)
    {
        c->handle_mouse_release(mouse_pos);
    }
}

void Controller::add_sun_random()
{
    DynamicSun *s = new DynamicSun(Vector2i(rng() % WIDTH, -100));
    suns.push_back(s);
}

void Controller::add_sun_inposition(Vector2i sunFlowerPos)
{
}

void Controller::render(RenderWindow &window)
{
    if (wb->get_ready_to_show())
    {
        wb->render(window);
    }

    for (Sun *s : suns)
    {
        s->render(window);
    }

    for (Card *c : cards)
    {
        c->render(window);
    }

    for (auto *z : zombies)
    {
        z->render(window);
    }
    
}

void Controller::update(RenderWindow &window)
{
    Time elapsed = sunClock.getElapsedTime();

    if (elapsed.asMilliseconds() >= 5000)
    {
        sunClock.restart();
        add_sun_random();
    }

    for (Sun *s : suns)
    {
        s->update();
    }
    remove_touched_and_outside_suns();

    Vector2i mouse_pos = Mouse::getPosition(window);
    for (Card *c : cards)
    {
        c->update(totalCredit, mouse_pos);
        if(c->is_dragging()){
            if (mouse_pos.x >= 650 and mouse_pos.x <= 1700 and mouse_pos.y >= 300 and mouse_pos.y <= 980)
            {   
                int x_appear = mouse_pos.x / 125;
                int y_appear = mouse_pos.y / 145;
                wb->change_pos(Vector2f(x_appear * 125 - 25, y_appear * 145 - 50));
                wb->show();
            }
            else{
                wb->hide();

            }
        }
    }

    Time zelapsed = zombieClock.getElapsedTime();

    if (zelapsed.asMilliseconds() >= 5000)
    {
        zombieClock.restart();
        add_zombie_random();
    }

    for (auto z : zombies)
    {
        z->update();
    }
}

void Controller::remove_touched_and_outside_suns()
{
    vector<Sun *> removed;

    for (Sun *s : suns)
    {
        if (s->get_shoud_be_removed())
        {
            removed.push_back(s);
        }
    }

    suns.erase(remove_if(suns.begin(), suns.end(),
                         [](Sun *p)
                         { return p->get_shoud_be_removed(); }),
               suns.end());

    for (Sun *s : removed)
    {
        delete (s);
    }
}

void Controller::add_zombie_random()
{
    int x_position = WIDTH - 20;
    int y_position = ((rng() % 5) * 160) + 90;
    int randZom = rng() % 2;
    Zombie *z;

    switch (randZom)
    {
    case 0:
        z = new OrdZombie(Vector2f(x_position, y_position + 30));
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