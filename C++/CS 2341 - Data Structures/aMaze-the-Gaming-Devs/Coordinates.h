//
// Created by kianr on 3/24/2021.
//

#ifndef PA04_AMAZING_COORDINATES_H
#define PA04_AMAZING_COORDINATES_H


#include <iostream>

using namespace std;

class Coordinates {
public:
    int x, y, dir;

    Coordinates() {

    };
    Coordinates(int i, int j) {
        x = i;
        y = j;
        dir = 0;
    }
};


#endif //PA04_AMAZING_COORDINATES_H
