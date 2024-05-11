#include "../includes/card.hpp"

Card::Card(string active_pic_name, string inactive_pic_name, Vector2i p, int cost
          ,string plant_pic_name){
    pos = p;
    dragging_situation = false;
    price = cost;

    if(!plant_texture.loadFromFile(PICS_PATH + plant_pic_name)) {
        debug("failed to load plant texture");
    }
    plant_sprite.setTexture(plant_texture);
    
    plant_sprite.setScale(0.45, 0.45);
    plant_sprite.setColor(LOW_TRANSPARENCY);
    plant_sprite.setPosition((Vector2f)p);


    if(!active_texture.loadFromFile(PICS_PATH + active_pic_name)) {
        debug("failed to load active texture");
    }
    if(!inactive_texture.loadFromFile(PICS_PATH + inactive_pic_name)) {
        debug("failed to load inactive texture");
    }

    sprite.setTexture(inactive_texture);
    sprite.setScale(1, 1);

    sprite.setPosition((Vector2f)p);
}

void Card::render(RenderWindow& window){
    window.draw(sprite);

    if(dragging_situation){
        window.draw(plant_sprite);
    }
}

void Card::update(int totalCredit, Vector2i mouse_pos){
    if(dragging_situation){
        Vector2f target((float)(mouse_pos.x) - plant_sprite.getGlobalBounds().width/2,
         (float)(mouse_pos.y) - plant_sprite.getGlobalBounds().height/2);
        plant_sprite.setPosition((Vector2f)target);
        fix_position();
    }

    if(totalCredit >= price){
        sprite.setTexture(active_texture);
    }
    else{
        sprite.setTexture(inactive_texture);
    }
}

void Card::handle_mouse_press(Vector2i mousePos){
    if(dragging_situation){
        if(plant_sprite.getGlobalBounds().contains((Vector2f)mousePos)){
            return;
        }
    }

    if(sprite.getGlobalBounds().contains((Vector2f)mousePos)){
        dragging_situation = true;
    }
}

void Card::handle_mouse_release(Vector2i mousePos){
    if(dragging_situation){
        dragging_situation = false;
        plant_sprite.setPosition((Vector2f)pos);
    }
}

void Card::fix_position(){
    FloatRect rect = plant_sprite.getGlobalBounds();
    rect.top = max(0.f, rect.top);
    rect.top = min(rect.top, HEIGHT - rect.height);
    rect.left = max(0.f, rect.left);
    rect.left = min(rect.left, WIDTH - rect.width);
    plant_sprite.setPosition(rect.left, rect.top);
}

bool Card::is_dragging(){
    return dragging_situation;
}