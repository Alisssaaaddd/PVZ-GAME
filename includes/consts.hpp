#pragma once

#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <cmath>
#include <random>
#include <string>
#include <vector>

using namespace sf;
using namespace std;

typedef struct ZombieData{
    string id;
    int damage;
    int health;
    int eatingRate;
    int speed;
}zombieData;

typedef struct PlantData{
    string id;
    int damage;
    int health;
    int coolDown;
    int hitRate;
    int speed;
    int price;
}plantData;

const int WIDTH = 1800;
const int HEIGHT = 1012;
const int FRAME_RATE = 144;
const int SUN_SPEED = 10;
const int SUN_CREDIT = 10;
const int NUM_OF_GAME_BLOCKS = 45;
const string SUN_FLOWER_ID = "sunflower";
const string PEA_SHOOTER_ID = "peashooter";
const string ICE_PEA_SHOOTER_ID = "icepeashooter";
const string WALNUT_ID = "walnut";
const string MELONPULT_ID = "melonpult";
const string ORDINARY_ZOMBIE_ID = "ordinary";
const string HAIRMETALGARGANTUAR_ZOMBIE_ID = "hairmetalgargantuar";

const string EMPTY = "";

const string PICS_PATH = "./files/images/", AUDIO_PATH = "./files/audio/",
             FONT_PATH = "./files/fonts/shlop.otf",
             ZOMBIES_SETTINGS_FILE_PATH = "./files/settings/zombies.csv",
             PLANTS_SETTINGS_FILE_PATH = "./files/settings/plants.csv",
             SUNS_SETTINGS_FILE_PATH = "./files/settings/suns.csv",
             ATTACKS_SETTINGS_FILE_PATH = "./files/settings/attacks.csv";

    const string FIELD_SEPARATOR = "-";
    const string COMMA = ",";


const Color BLUE = Color(50, 115, 220);
const Color PURPLE = Color(130, 50, 220);
const Color YELLOW = Color(255, 248, 220);
const Color DRAGGING_LOW_TRANSPARENCY = Color(255, 255, 255, 150);
const Color WHITE_BLOCKS_LOW_TRANSPARENCY = Color(255, 255, 255, 100);
const Color RED_BLOCKS_LOW_TRANSPARENCY = Color(255, 0, 0, 100);

#define debug(x) cout << x << endl, exit(0);