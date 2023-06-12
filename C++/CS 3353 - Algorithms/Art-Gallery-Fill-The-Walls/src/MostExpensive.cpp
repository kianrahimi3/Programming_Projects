//
// Created by kianr on 9/2/2021.
//

#include "MostExpensive.h"


bool sortcol( const vector<int>& v1,
              const vector<int>& v2 ) {
    return v1[1] > v2[1];
}

void MostExpensive::setPaintings(vector<vector<int>> paintingVector) {
    vector<vector<int>> temp;
    temp = paintingVector;

    sort(temp.begin(), temp.end(), sortcol);

    paintings = temp;
}
vector<vector<int>> MostExpensive::getPaintings() {
    return paintings;
}
void MostExpensive::setTotalPrice(int total) {
    totalPrice = total;
}
int MostExpensive::getTotalPrice() {
    return totalPrice;
}


vector<vector<int>> MostExpensive::Expensive(vector<vector<int>> paintings, int rows, int cols) {

    int array[rows][cols];

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            array[i][j] = 0;
        }
    }

    int rowLoc = rows-1;
    int colLoc = 0;

    shelfWidth = cols;

    int k = 0;

    vector<int> coordinates;
    vector<vector<int>> allCoordinatesOfPaintings;

    bool run = true;
    while(run == true) {

        if(k >= paintings.size())
            break;

        paintingID = paintings[k][0];
        paintingCost = paintings[k][1];
        paintingHeight = paintings[k][2];
        paintingWidth = paintings[k][3];

        if(paintingWidth > shelfWidth) {
            k++;
            continue;
        }

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

        int count = 0;

        for(int i = rowLoc; i > rowLoc - paintings[k][2]; i--) {
            for(int j = colLoc; j < colLoc + paintings[k][3]; j++) {
                array[i][j] = paintingID;
                if(i == rowLoc - paintings[k][2] +1 && j == 0) {
                    coordinates.push_back(i);
                    coordinates.push_back(j);
                    allCoordinatesOfPaintings.push_back(coordinates);
                    coordinates.clear();

                    // rowLoc = rowLoc - paintings[k][2] + 1;
                }
                else if(i == rowLoc - paintings[k][2] +1 && j == colLoc) {
                    coordinates.push_back(i);
                    coordinates.push_back(j);
                    allCoordinatesOfPaintings.push_back(coordinates);
                    coordinates.clear();

                    //   rowLoc = rowLoc - paintings[k][2] + 1;

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

    ofstream output("../output/testing-highvalue.txt");

    int sum = 0;

    for(int i = 0; i < allCoordinatesOfPaintings.size(); i++) {
        sum+= allCoordinatesOfPaintings[i][1];
    }

    output << sum << endl;

    for(int i = 0; i < allCoordinatesOfPaintings.size(); i++) {
        for(int j = 0; j < allCoordinatesOfPaintings[i].size(); j++) {
            output << allCoordinatesOfPaintings[i][j] << " ";
        }
        output << endl;
    }

    return allCoordinatesOfPaintings;
}
