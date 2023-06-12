//
// Created by kianr on 3/25/2021.
//

#ifndef PA04_AMAZING_MAZEADJLIST_H
#define PA04_AMAZING_MAZEADJLIST_H

//#include "DSList.h"

#include <iostream>

#include "DSVector.h"
#include "Coordinates.h"
#include "DSStack.h"

using namespace std;

class MazeAdjList {
private:
    DSVector<DSVector<int>> mazeList;

    DSVector<Coordinates> adjacents;

public:
    MazeAdjList();
    ~MazeAdjList();

    //https://www.tutorialspoint.com/cplusplus-program-to-implement-adjacency-list
    void addEdge(DSVector<DSVector<int>> adj, int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    };


    //Coordinates is another class i have created...holds the location and direction it is facing

    void add_edge(Coordinates source, Coordinates destination, int rows, int cols) {

        for(int i = 0; i < rows; i++) {
            DSVector<int> vectorX;


            for(int j = 0; j < cols; j++) {
                Coordinates loc(i, j);

                if((loc.x == source.x) && (loc.y == source.y) ) {
                    //nothing
                }
                else if((loc.x == destination.x) && (loc.y == destination.y) ) {
                    break;
                }
                else {
                    vectorX.push_back(j);
                }
            }

            mazeList.push_back(vectorX);
        }
    }



    //got help from geeks for geeks
    //must keep looking over this
    //Coordinates is another class i have created...holds the location and direction it is facing
    DSVector<Coordinates> get_adjacent_rooms(Coordinates loc, DSVector<DSVector<bool>> visited, int rows, int cols) {

        DSStack<Coordinates> s;
        s.push(loc);


        // up direction

        if (loc.dir == 0) {

            if (loc.x - 1 >= 0 && mazeList[loc.x - 1][loc.y] && visited[loc.x - 1][loc.dir] ) {
                Coordinates temp1(loc.x - 1, loc.y);
                visited[loc.x - 1][loc.y] = false;
                s.push(temp1);

                //  cout << "(" << temp1.x << ", " << temp1.y << ")" << endl;
            }
        }

            // left direction

        else if (loc.dir == 1) {

            if (loc.y - 1 >= 0 && mazeList[loc.x][loc.y - 1] && visited[loc.x][loc.dir - 1]) {
                Coordinates temp1(loc.x, loc.y - 1);
                visited[loc.x][loc.y - 1] = false;
                s.push(temp1);
                //   cout << "(" << temp1.x << ", " << temp1.y << ")" << endl;

            }
        }

            // down direction

        else if (loc.dir == 2) {

            if (loc.x + 1 < rows && mazeList[loc.x + 1][loc.y] && visited[loc.x + 1][loc.dir]) {
                Coordinates temp1(loc.x + 1, loc.y);
                visited[loc.x + 1][loc.y] = false;
                s.push(temp1);

                //   cout << "(" << temp1.x << ", " << temp1.y << ")" << endl;
            }
        }

            // right direction

        else if (loc.dir == 3) {

            if (loc.y + 1 < cols && mazeList[loc.x][loc.y + 1] && visited[loc.x][loc.y + 1]) {
                Coordinates temp1(loc.x, loc.y + 1);
                visited[loc.x][loc.y + 1] = false;
                s.push(temp1);

                //   cout << "(" << temp1.x << ", " << temp1.y << ")" << endl;
            }
        }

        else {
            // when visited == true...it means it has not been there (unvisited)
            visited[loc.x][loc.y] = true;
            s.pop();
        }

        return s.getList();
    }


};


#endif //PA04_AMAZING_MAZEADJLIST_H
