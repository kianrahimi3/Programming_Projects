//
// Created by kianr on 3/31/2021.
//

#ifndef PA04_AMAZING_MAZEWORK_H
#define PA04_AMAZING_MAZEWORK_H

#include "DSStack.h"
#include "DSList.h"
#include "DSVector.h"
#include "Coordinates.h"
#include <fstream>
#include <cstring>

class MazeWork {
private:
    int cost = 1;
    int roomcount = 1;

    int rows;
    int cols;
    DSVector<DSVector<int>> graph;
    DSVector<DSVector<Coordinates>> portals;
    DSVector<int> lifePoints;
    DSVector<bool> portalDone;
    DSVector<DSVector<bool>> visitedd;


public:
    DSStack<Coordinates> NoPortalsYesPop(DSVector<DSVector<int>> maze, int n, int m,int startx, int starty, int fx, int fy, DSVector<DSVector<bool>> visited, DSVector<DSVector<Coordinates>> portals, DSVector<int> lifePoints, DSVector<bool> portalDone);
    DSStack<Coordinates> NoPortalsNoPop(DSVector<DSVector<int>> maze, int n, int m,int startx, int starty, int fx, int fy, DSVector<DSVector<bool>> visited, DSVector<DSVector<Coordinates>> portals, DSVector<int> lifePoints, DSVector<bool> portalDone);
    DSStack<Coordinates> YesPortalsNoPop(DSVector<DSVector<int>> maze, int n, int m,int startx, int starty, int fx, int fy, DSVector<DSVector<bool>> visited, DSVector<DSVector<Coordinates>> portals, DSVector<int> lifePoints, DSVector<bool> portalDone);
    DSStack<Coordinates> YesPortalsYesPop(DSVector<DSVector<int>> maze, int n, int m,int startx, int starty, int fx, int fy, DSVector<DSVector<bool>> visited, DSVector<DSVector<Coordinates>> portals, DSVector<int> lifePoints, DSVector<bool> portalDone);

    void setCost(int num);
    int getCost();
    void setRoomCount(int num);
    int getRoomCount();

    void outputShortest(char* filename, DSVector<DSVector<Coordinates>> comparisons, DSVector<MazeWork> mazePaths, DSVector<DSVector<Coordinates>> portals,  DSVector<int> lifePoints);
    void outputLongest(char* filename, DSVector<DSVector<Coordinates>> comparisons, DSVector<MazeWork> mazePaths, DSVector<DSVector<Coordinates>> portals,  DSVector<int> lifePoints);

    void ReadInFile(char* inputfile, char* output1, char* output2);
};


#endif //PA04_AMAZING_MAZEWORK_H
