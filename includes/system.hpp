#pragma once

#include "controller.hpp"

enum State {
  IN_GAME,
  PAUSE_MENU,
  MAIN_MENU,
  VICTORY_SCREEN,
  GAMEOVER_SCREEN,
  EXIT
};

class System{
    private:
      State state;
      Controller* gamePlay;
      Texture backgroundTexture;
      Sprite backgroundSprite;
      
      vector<zombieData> zombiesSettings;
      vector<plantData> plantsSettings;
      vector<int> attacksSettings;
      vector<int> sunsSettings;
      
    public:
      System(int width, int height);
      vector<string> split(string s, string delimiter);

      RenderWindow window;
      void start();
      void render();
      void update();
      void handle_events();
      void handle_mouse_press(Event ev);
      void handle_mouse_release(Event ev);

      void get_zombies_settings();
      void get_plants_settings();
      void get_suns_settings();
      void get_attacks_settings();
};