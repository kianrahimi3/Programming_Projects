//
// Created by kianr on 3/9/2021.
//

#ifndef PA03_TEMPLATE_SORTS_H
#define PA03_TEMPLATE_SORTS_H

#include <iostream>
#include <chrono>
#include "include/sorting_library.h"
#include <map>

using namespace std;

class Sorts {
public:
    int sortManager(int choice, int array[], int size);

    map<string, chrono::duration<double>> sortTimings;
    map<string, chrono::duration<double> >::iterator it = sortTimings.begin();

    void printTimings();
};


#endif //PA03_TEMPLATE_SORTS_H
