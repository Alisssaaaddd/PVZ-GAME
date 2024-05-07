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
      int totalCredit = 0;
      Controller* gamePlay;
      Texture backgroundTexture;
      Sprite backgroundSprite;
    
  
    public:
      System(int width, int height);
      RenderWindow window;
      void start();
      void render();
      void handle_events();
      void handle_mouse_press(Event ev);
      void handle_mouse_release(Event ev);
};