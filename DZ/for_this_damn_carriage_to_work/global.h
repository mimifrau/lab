//
// Created by РЎРµСЂРіРµР№ РќРѕРІРёРєРѕРІ on 26.12.2023.
//

#ifndef MAIN_CPP_GLOBAL_H
#define MAIN_CPP_GLOBAL_H

#include <SFML/Graphics.hpp>
#include <ctime>

using namespace sf;

const int M = 20;
const int N = 10;

int field[M][N] = {0};
int w = 34;

int figures[7][4] = {
        1, 3, 5, 7,
        2, 4, 5, 7,
        3, 5, 4, 6,
        3, 5, 4, 7,
        2, 3, 5, 7,
        3, 5, 7, 6,
        2, 3, 4, 5,
};

#endif //MAIN_CPP_GLOBAL_H
