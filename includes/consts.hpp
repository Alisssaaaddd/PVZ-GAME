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

const string PICS_PATH = "./files/images/", AUDIO_PATH = "./files/audio/",
             FONT_PATH = "./files/fonts/shlop.otf";

const Color BLUE = Color(50, 115, 220);
const Color PURPLE = Color(130, 50, 220);
const Color YELLOW = Color(255, 248, 220);
const Color DRAGGING_LOW_TRANSPARENCY = Color(255, 255, 255, 150);
const Color WHITE_BLOCKS_LOW_TRANSPARENCY = Color(255, 255, 255, 100);
const Color RED_BLOCKS_LOW_TRANSPARENCY = Color(255, 0, 0, 100);
// const co

#define debug(x) cout << x << endl, exit(0);