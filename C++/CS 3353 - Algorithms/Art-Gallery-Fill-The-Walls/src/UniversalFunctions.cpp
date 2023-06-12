//
// Created by kianr on 9/6/2021.
//

#include "UniversalFunctions.h"

/*
vector<vector<int>>& UniversalFunctions::findCoordinates(vector<vector<int>> paintings, int **array, int paintingID, int paintingCost, int paintingWidth, int paintingHeight, int totalPrice, int colLoc, int rowLoc, int shelfWidth, int shelfHeight) {

    int k = 0;
    vector<int> coordinates;
    vector<vector<int>> allCoordinatesOfPaintings;

    bool run = true;
    while(run == true) {

        paintingID = paintings[k][0];
        paintingCost = paintings[k][1];
        paintingWidth = paintings[k][2];
        paintingHeight = paintings[k][3];

        if(colLoc + paintings[k][3] >= shelfWidth) {
            rowLoc = rowLoc - shelfHeight;
            colLoc = 0;
            shelfHeight = 0;
        }
        if(rowLoc - paintings[k][2] < -1) {
            if(k+1 >= paintings.size())
                break;
            else
                k++;
            continue;
        }

        coordinates.push_back(paintingID);
        coordinates.push_back(paintingCost);
        coordinates.push_back(paintingWidth);
        coordinates.push_back(paintingHeight);

        for(int i = rowLoc; i > rowLoc - paintings[k][2]; i--) {
            for(int j = colLoc; j < colLoc + paintings[k][3]; j++) {
                array[i][j] = paintingID;
                if(i == rowLoc - paintings[k][2] +1 && j == 0) {
                    coordinates.push_back(i);
                    coordinates.push_back(j);
                    allCoordinatesOfPaintings.push_back(coordinates);
                    coordinates.clear();
                }
                else if(i == rowLoc - paintings[k][2] +1 && j == colLoc) {
                    coordinates.push_back(i);
                    coordinates.push_back(j);
                    allCoordinatesOfPaintings.push_back(coordinates);
                    coordinates.clear();
                }
            }
        }
        colLoc += paintings[k][3];


        if(shelfHeight < paintings[k][2])
            shelfHeight = paintings[k][2];

        totalPrice += paintings[k][1];
        k++;

        if(k > paintings.size() - 1)
            run = false;


    }
}
 */

void UniversalFunctions::outputToFile(char* file, vector<vector<int>> allCoordinatesOfPaintings) {
    ofstream output(file);
    for(int i = 0; i < allCoordinatesOfPaintings.size(); i++) {
        for(int j = 0; j < allCoordinatesOfPaintings[i].size(); j++) {
            output << allCoordinatesOfPaintings[i][j] << " ";
        }
        output << endl;
    }

}