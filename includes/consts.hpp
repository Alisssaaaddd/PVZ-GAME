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

const int WIDTH = 1400;
const int HEIGHT = 600;
const int FRAME_RATE = 144;

const string PICS_PATH = "./files/pics/", AUDIO_PATH = "./files/audio/",
             FONTS_PATH = "./files/fonts/";

const Color BLUE = Color(50, 115, 220);
const Color PURPLE = Color(130, 50, 220);
const Color YELLOW = Color(255, 248, 220);

#define debug(x) cout << x << endl, exit(0);