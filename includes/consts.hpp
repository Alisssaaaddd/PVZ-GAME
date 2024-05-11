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

const string PICS_PATH = "./files/images/", AUDIO_PATH = "./files/audio/",
             FONTS_PATH = "./files/fonts/";

const Color BLUE = Color(50, 115, 220);
const Color PURPLE = Color(130, 50, 220);
const Color YELLOW = Color(255, 248, 220);
const Color LOW_TRANSPARENCY = Color(255, 255, 255, 150);

#define debug(x) cout << x << endl, exit(0);