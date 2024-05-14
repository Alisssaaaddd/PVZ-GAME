#pragma once

#include "consts.hpp"

class Card{
private:
    int price;
    bool dragging_situation;
    bool is_active;
    string plantId;
    Texture active_texture;
    Texture inactive_texture;
    Texture plant_texture;
    Sprite sprite;
    Sprite plant_sprite;
    Vector2i pos;
    Vector2i plant_pos;
    Font font;
    Text priceText;

    void set_scale_for_plant_sprite();
public:
    Card(string active_pic_name, string inactive_pic_name, Vector2i p, int cost
    , string plant_pic_name);
    ~Card();
    bool is_dragging();
    bool can_seed();
    string get_plant_id();
    int get_price();
    void render(RenderWindow& window);
    void update(int totalCredit, Vector2i mouse_pos);
    void handle_mouse_press(Vector2i mousePos, int totalCredit);
    void handle_mouse_release(Vector2i mousePos);
    void fix_position();
};
