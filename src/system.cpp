#include "../includes/system.hpp"

System::System(int width, int height){
    window.create(VideoMode(width, height), "UT PVZ", Style::Close);
    window.setFramerateLimit(FRAME_RATE);
    state = IN_GAME;

    if(!backgo)
}