#include "../includes/controller.hpp"

Controller::Controller(){
    Card* sunFolwerCard = new Card("sunfloweractivecard.png", "sunflowerinactivecard.png",
     Vector2i(100, 100), 50, SUN_FLOWER_ID);
    cards.push_back(sunFolwerCard);

    Plant* peashooter = new PeaShooter(Vector2f(595, 215), 1.5);
    plants.push_back(peashooter);
    Plant* Icepeashooter = new IcePeaShooter(Vector2f(595, 365), 1.5);
    plants.push_back(Icepeashooter);
    Plant* walnut = new Walnut(Vector2f(595, 510));
    plants.push_back(walnut);
    Plant* sunFlower = new SunFlower(Vector2f(595, 660), 5);
    plants.push_back(sunFlower);

    initialize_blocks();
    should_draw_currentBlock = false;
}

Controller::~Controller()
{
    for (auto s : shots)
    {
        delete s;
    }
    for (auto z : zombies)
    {
        delete z;
    }
    for (auto sun : suns)
    {
        delete sun;
    }
    for (auto p : plants)
    {
        delete p;
    }
}

void Controller::initialize_blocks()
{
    for(int y=225; y<1011; y+=157){
        for(int x=630; x<1824; x+=132){
            RectangleShape block;
            block.setPosition(Vector2f(x,y));
            block.setSize(Vector2f(132, 150));
            block.setFillColor(WHITE_BLOCKS_LOW_TRANSPARENCY);
            blocks.push_back(block);
        }
    }
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
        c->handle_mouse_press(mouse_pos, totalCredit);
        if(c->is_dragging()){
            return;
        }
    }
    //We'll add other objects later too ... .
}

void Controller::handle_mouse_release(Vector2i mouse_pos){
    if(should_draw_currentBlock){
        should_draw_currentBlock = false;

        for(Card* c : cards){
            if(c->is_dragging()){
                c->handle_mouse_release(mouse_pos);
                if(c->can_seed()){
                    if(blocks[currentBlockIndex].getFillColor() != RED_BLOCKS_LOW_TRANSPARENCY){
                        Vector2f seed_pos = {blocks[currentBlockIndex].getGlobalBounds().left, blocks[currentBlockIndex].getGlobalBounds().top};//will change
                        string plantId = c->get_plant_id();
                        totalCredit -= c->get_price();
                        seed(seed_pos, plantId);

                        blocks[currentBlockIndex].setFillColor(RED_BLOCKS_LOW_TRANSPARENCY);
                        break;
                    }
                }
            }
        }
    }
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
    if(should_draw_currentBlock){
        window.draw(blocks[currentBlockIndex]);
    }

    for(Plant* p : plants){
        p->render(window);
    }

    for(Card* c : cards){
        c->render(window);
    }

    for (Zombie* z : zombies){
        z->render(window);
    }

    for(Shot* s : shots){
        s->render(window);
    }

    for(Sun* s : suns){
        s->render(window);
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
        z = new OrdZombie(Vector2f(x_position, y_position+40));
        break;
    case 1:
        z = new HugeZombie(Vector2f(x_position, y_position + 10));
        break;
    }

    zombies.push_back(z);
}

void Controller::remove_outside_shots(){
    vector<Shot*> removed_shots;

    for (Shot* s : shots){
        if (s->is_out()){
            removed_shots.push_back(s);
        }
    }
    
    shots.erase(remove_if(shots.begin(), shots.end(), 
    [](Shot* p){ return p->is_out(); }), shots.end());

    for (Shot* s : removed_shots){
        delete(s);
    }
}

void Controller::update_cards(RenderWindow& window){
    Vector2i mouse_pos = Mouse::getPosition(window);
    for (Card *c : cards)
    {
        c->update(totalCredit, mouse_pos);
        if(c->is_dragging()){
            for(int i = 0;i<NUM_OF_GAME_BLOCKS;i++){
                if(blocks[i].getGlobalBounds().contains((Vector2f)mouse_pos)){
                    should_draw_currentBlock = true;
                    currentBlockIndex = i;
                    break;
                }
            }
        }
    }
}

void Controller::update_plants(){
    for(Plant* p : plants){
        p->update();
        string id = p->get_id();

        if(id == SUN_FLOWER_ID){
            SunFlower* s = (SunFlower*) p;

            if(s->should_produce_sun()){
                add_sun_inposition(p->get_pos());
            }
        }

        else if(id == PEA_SHOOTER_ID){
            PeaShooter* pea = (PeaShooter*) p;

            if(pea->should_shoot()){
                add_shot(pea->get_pos(), id);
            }
        }

        else if(id == ICE_PEA_SHOOTER_ID){
            IcePeaShooter* ice = (IcePeaShooter*) p;

            if(ice->should_shoot()){
                add_shot(ice->get_pos(), id);
            }
        }

        else if(id == MELONPULT_ID){
            MelonPult* melon = (MelonPult*) p;

            if(melon->should_shoot()){
                add_shot(melon->get_pos(), id);
            }
        }
    }
}

void Controller::update_shots(){
    for(Shot* s : shots){
        s->update();
    }

    remove_outside_shots();
}

void Controller::update_suns(){
    Time elapsed = sunClock.getElapsedTime();

    if(elapsed.asMilliseconds() >= 10000){
        sunClock.restart();
        add_sun_random();
    }

    for(Sun* s : suns){
        s->update();
    }

    remove_touched_and_outside_suns();
}

void Controller::update_zombies(){
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
}

void Controller::update(RenderWindow& window){
    update_cards(window);
    update_plants();
    update_shots();
    update_suns();
    update_zombies();
    handle_collisions();
}

void Controller::seed(Vector2f pos, string plantId){
    if(plantId == SUN_FLOWER_ID){
        SunFlower* s = new SunFlower(pos, 10);//rate will be changed.
        plants.push_back(s);
    }

    else if(plantId == PEA_SHOOTER_ID){
        PeaShooter* p = new PeaShooter(pos, 5);//rate will be changed.
        plants.push_back(p);
    }

    else if(plantId == ICE_PEA_SHOOTER_ID){
        IcePeaShooter* i = new IcePeaShooter(pos, 5);//rate will be changed.
        plants.push_back(i);
    }

    else if(plantId == WALNUT_ID){
        Walnut* w = new Walnut(pos);
        plants.push_back(w);
    }

    else if(plantId == MELONPULT_ID){
        MelonPult* m = new MelonPult(pos, 8);//rate will be changed.
        plants.push_back(m);
    }

}

void Controller::add_shot(Vector2f plant_pos, string plantId){
    Vector2f shot_init_pos;

    if(plantId == PEA_SHOOTER_ID){
        shot_init_pos = {plant_pos.x + 85, plant_pos.y + 20};
        OrdShot* o = new OrdShot(shot_init_pos);
        shots.push_back(o);
    }
    
    else if(plantId == ICE_PEA_SHOOTER_ID){
        shot_init_pos = {plant_pos.x + 85, plant_pos.y + 25};
        IceShot* i = new IceShot(shot_init_pos);
        shots.push_back(i);
    }

    else if(plantId == MELONPULT_ID){
        shot_init_pos = {plant_pos.x + 5, plant_pos.y + 10};
        MelonShot* m = new MelonShot(shot_init_pos);
        shots.push_back(m);
    }
}

void Controller::handle_collisions(){
    vector <Shot*> removed_shots;
    vector <Zombie*> hurt_zombies;
    FloatRect zombie_rect;
    FloatRect shot_rect;

    for(Shot* s : shots){
        shot_rect = s->get_rect();

        for(Zombie* z : zombies){
            zombie_rect = z->get_rect();

            if(zombie_rect.intersects(shot_rect) and s->get_line_number() == z->get_line_number()){
                removed_shots.push_back(s);
                z->reduce_health(s->get_damage());
                hurt_zombies.push_back(z);
                break;
            }
        }
    }

    for(Shot* s : removed_shots){
        shots.erase(remove(shots.begin(), shots.end(), s), shots.end());   
        delete s;
    }
    
    remove_dead_zombies(hurt_zombies);
}

void Controller::remove_dead_zombies(vector<Zombie*>& hurt_zombies){
    vector<Zombie*> dead_zombies;

    for (Zombie* z : hurt_zombies){
        if (z->is_dead()){
            dead_zombies.push_back(z);
        }
    }
    
    for(Zombie* z : dead_zombies){
        zombies.erase(remove(zombies.begin(), zombies.end(), z), zombies.end());
        delete z;
    }
}