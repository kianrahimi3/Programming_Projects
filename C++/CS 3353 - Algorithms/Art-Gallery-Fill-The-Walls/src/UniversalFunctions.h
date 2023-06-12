//
// Created by kianr on 9/6/2021.
//

#ifndef INC_21F_PA01_KIAN_S_TEAM_MAIN_UNIVERSALFUNCTIONS_H
#define INC_21F_PA01_KIAN_S_TEAM_MAIN_UNIVERSALFUNCTIONS_H

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
class UniversalFunctions {
public:
    //vector<vector<int>>& findCoordinates(vector<vector<int>> paintings, int **array, int paintingID, int paintingCost, int paintingWidth, int paintingHeight, int totalPrice, int colLoc, int rowLoc, int shelfWidth, int shelfHeight);
    void outputToFile(char* file, vector<vector<int>> allCoordinatesOfPaintings);

};


#endif //INC_21F_PA01_KIAN_S_TEAM_MAIN_UNIVERSALFUNCTIONS_H
