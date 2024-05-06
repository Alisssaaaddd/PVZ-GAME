#include "consts.hpp"

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
    vector<Plant*> plants;
    vector<Zombie*> zombies;
    vector<Shot*> plantShots;


    public:
    System(int width, int height);
    RenderWindow window;
    void run();
};