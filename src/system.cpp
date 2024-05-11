#include "../includes/system.hpp"

System::System(int width, int height)
{
    sf::Music music;
    window.create(VideoMode(width, height), "UT PVZ", Style::Close);
    window.setFramerateLimit(FRAME_RATE);
    state = IN_GAME;

    if (!backgroundTexture.loadFromFile(PICS_PATH + "background.png"))
    {
        debug("failed to load image");
    }
    backgroundSprite.setTexture(backgroundTexture);

    if (!music.openFromFile(AUDIO_PATH + "bg.ogg"))
    {
        debug("failed to load music");
    }
    music.setLoop(true);
    music.play();
    
    gamePlay = new Controller();
}

void System::start()
{
    while (window.isOpen() and state != EXIT)
    {
        update();
        render();
        handle_events();
    }
    exit(0);
}

void System::render()
{
    window.clear();

    switch (state){
        case (IN_GAME):
            window.draw(backgroundSprite);
            gamePlay->render(window);
            break;
        case (PAUSE_MENU):
            break;
        case (MAIN_MENU):
            break;
        case (VICTORY_SCREEN):
            break;
        case (GAMEOVER_SCREEN):
            break;
            // case (EXIT):
            //     abort();
            //     break;
    }
    window.display();
}

void System::handle_events()
{
    Event event;
    while (window.pollEvent(event))
    {
        switch (event.type){
            case (Event::Closed):
                window.close();
                state = EXIT;
                break;
            case (Event::MouseButtonPressed):
                handle_mouse_press(event);
                break;
            case (Event::MouseButtonReleased):
                handle_mouse_release(event);
                break;
            default:
                break;
        }
    }
}

void System::handle_mouse_press(Event ev)
{
    if (ev.mouseButton.button == Mouse::Right)
        return;
    Vector2i mouse_pos = {ev.mouseButton.x, ev.mouseButton.y};
    switch (state){
        case (IN_GAME):
            gamePlay->handle_mouse_press(mouse_pos);
            break;
        case (PAUSE_MENU):
            break;
        case (MAIN_MENU):
            break;
        case (VICTORY_SCREEN):
            break;
        case (GAMEOVER_SCREEN):
            break;
    }
}

void System::handle_mouse_release(Event ev)
{
    if (ev.mouseButton.button == Mouse::Right)
        return;
    Vector2i mouse_pos = {ev.mouseButton.x, ev.mouseButton.y};
    switch (state)
    {
    case (IN_GAME):
        gamePlay->handle_mouse_release(mouse_pos);
        break;
    case (PAUSE_MENU):
        break;
    case (MAIN_MENU):
        break;
    case (VICTORY_SCREEN):
        break;
    case (GAMEOVER_SCREEN):
        break;
    }
}

void System::update(){
    switch (state) {
        case (IN_GAME):
            gamePlay->update(window);
            break;
        case (PAUSE_MENU):
            break;
        case (MAIN_MENU):
            break;
        case (VICTORY_SCREEN):
            break;
        case (GAMEOVER_SCREEN):
            break;
    }
}