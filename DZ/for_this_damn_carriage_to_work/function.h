//
// Created by Сергей Новиков on 26.05.2023.
//

#ifndef MAIN_CPP_FUNCTION_H
#define MAIN_CPP_FUNCTION_H

#include "global.h"

struct Point {
    int x, y;
} a[4], b[4];

bool check() {
    for (int i = 0; i < 4; i++)
        if (a[i].x < 0 or a[i].x >= N or a[i].y >= M)
            return 0;
        else if (field[a[i].y][a[i].x])
            return 0;

    return 1;
}

#endif //MAIN_CPP_FUNCTION_H
