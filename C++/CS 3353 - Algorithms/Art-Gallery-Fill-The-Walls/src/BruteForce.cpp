//
// Created by kianr on 9/2/2021.
//

#include "BruteForce.h"

void BruteForce::setPaintings(vector<vector<int>> paintingVector) {
    paintings = paintingVector;
}
vector<vector<int> > BruteForce::getPaintings() {
    return paintings;
}
void BruteForce::setTotalPrice(int total) {
    totalPrice = total;
}
int BruteForce::getTotalPrice() {
    return totalPrice;
}

void BruteForce::Brute(vector<vector<int>> paintings, int rows, int cols) {

     if(paintings.size() > 10) {
        ofstream output("../output/testing-bruteforce.txt");
        output << "Data set exceeds maximum";
        return;
    }


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
        ////////////////////////////

    MostExpensive me;
    me.setPaintings(paintings);
    vector<vector<int>> vec = me.Expensive(me.getPaintings(), rows, cols);

    ByShortest shorts;
    shorts.setPaintings(paintings);
    vector<vector<int>> vec2 = shorts.Shortest(shorts.getPaintings(), rows, cols);

    int bfSum = 0;
    //brute force vector
    for(int i = 0; i < allCoordinatesOfPaintings.size(); i++) {
        bfSum+=allCoordinatesOfPaintings[i][1];
    }
    int meSum = 0;
    //most expensive vector
    for(int i = 0; i < vec.size(); i++) {
        meSum+=vec[i][1];
    }
    int sSum = 0;
    //shortest vector
    for(int i = 0; i < vec2.size(); i++) {
        sSum+=vec2[i][1];
    }

    if(meSum > bfSum)
        allCoordinatesOfPaintings = vec;
    else if(sSum > bfSum)
        allCoordinatesOfPaintings = vec2;

        ////////////////////////////////

       // string fileName = argv[1] + "-bruteforce.txt"
    ofstream output("../output/testing-bruteforce.txt");

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

}

