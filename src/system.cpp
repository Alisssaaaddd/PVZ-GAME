#include "../includes/system.hpp"

vector<string> System::split(string s, string delimiter){
    int start = 0, end = 0;
    vector <string> result;

    while (end != -1) {
        end = s.find(delimiter, start);
        string segment = s.substr(start, end - start);

        if(segment != EMPTY){
            result.push_back(segment);
        }

        start = end + delimiter.size();
    }

    return result;
}

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
    get_zombies_settings();
    get_attacks_settings();
    get_plants_settings();
    get_suns_settings();
    
    gamePlay = new Controller(zombiesSettings, plantsSettings, attacksSettings, sunsSettings);
}

void System::get_zombies_settings(){
    ifstream settingsFile(ZOMBIES_SETTINGS_FILE_PATH);
    string line;
    vector<string> lineVec;
    
    while(getline(settingsFile, line)){
        lineVec = split(line, COMMA);

        for(string temp : lineVec){
            vector<string> data = split(temp, FIELD_SEPARATOR);
            zombieData z;
            z.id = data[0];//Be carefull to not leave a space at the first of zombie id in the csv file!
            z.damage = stoi(data[1]);
            z.health = stoi(data[2]);
            z.eatingRate = stoi(data[3]);
            z.speed = stoi(data[4]);
            
            zombiesSettings.push_back(z);
        }
    }
}

void System::get_plants_settings(){
    ifstream settingsFile(PLANTS_SETTINGS_FILE_PATH);
    string line;
    vector<string> lineVec;

    while(getline(settingsFile, line)){
        lineVec = split(line, COMMA);

        for(string temp : lineVec){
            vector<string> data = split(temp, FIELD_SEPARATOR);
            plantData p;
            p.id = data[0];//Be carefull to not leave a space at the first of zombie id in the csv file!
            p.damage = stoi(data[1]);
            p.health = stoi(data[2]);
            p.coolDown = stoi(data[3]);
            p.hitRate = stoi(data[4]);
            p.speed = stoi(data[5]);
            p.price = stoi(data[6]);
            
            plantsSettings.push_back(p);
        }
    }
}

void System::get_suns_settings(){
    ifstream settingsFile(SUNS_SETTINGS_FILE_PATH);
    string line;
    getline(settingsFile, line);
    vector<string> lineVec;
    lineVec = split(line, FIELD_SEPARATOR);

    for(string s : lineVec){
        sunsSettings.push_back(stoi(s));
    }
}

void System::get_attacks_settings(){
    ifstream settingsFile(ATTACKS_SETTINGS_FILE_PATH);
    string line;
    getline(settingsFile, line);
    vector<string> lineVec;
    lineVec = split(line, FIELD_SEPARATOR);

    for(string s : lineVec){
        attacksSettings.push_back(stoi(s));
    }
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