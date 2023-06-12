//
// Created by kianr on 9/5/2021.
//

#ifndef INC_21F_PA01_KIAN_S_TEAM_MAIN_BYSHORTEST_H
#define INC_21F_PA01_KIAN_S_TEAM_MAIN_BYSHORTEST_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "UniversalFunctions.h"
using namespace std;
class ByShortest {
    vector<vector<int>> paintings;
    int totalPrice = 0;
    int paintingID;
    int paintingCost = 0;
    int paintingHeight = 0;
    int paintingWidth = 0;
    int shelfHeight = 0;
    int shelfWidth;
public:
    void setPaintings(vector<vector<int>> insert);
    vector<vector<int>> getPaintings();
    void setTotalPrice(int total);
    int getTotalPrice();

    vector<vector<int>> Shortest(vector<vector<int>> paintings, int rows, int cols);
};


#endif //INC_21F_PA01_KIAN_S_TEAM_MAIN_BYSHORTEST_H
