#include "../includes/system.hpp"

System::System(int width, int height){
    window.create(VideoMode(width, height), "UT PVZ", Style::Close);
    window.setFramerateLimit(FRAME_RATE);
    state = IN_GAME;

    if (!backgroundTexture.loadFromFile(PICS_PATH + "bg.png")) {
    debug("failed to load image");
    } 
    backgroundSprite.setTexture(backgroundTexture);
    
}