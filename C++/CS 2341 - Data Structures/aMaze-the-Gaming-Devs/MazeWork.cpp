//
// Created by kianr on 3/31/2021.
//

#include "MazeWork.h"




DSStack<Coordinates> MazeWork::NoPortalsYesPop(DSVector<DSVector<int>> maze, int n, int m,int startx, int starty, int fx, int fy, DSVector<DSVector<bool>> visited, DSVector<DSVector<Coordinates>> portals, DSVector<int> lifePoints, DSVector<bool> portalDone) {

    DSStack<Coordinates> kian;
    DSStack<Coordinates> s;
    Coordinates temp(startx, starty);

 //   int cost = 0;
    s.push(temp);
   // cost++;

    while (!s.empty()) {

        //Set top of stack as temp and put it to work but also
        //Pop top coordinates and then look at all sides using if statements
        //...else go back

        temp = s.top();
        int direction = temp.dir;

        // Increment the direction and
        // push the Coordinates in the DSStack again.

        // Direction = integer
        // 0 = up
        // 1 = left
        // 2 = down
        // 3 = right
        temp.dir++;


        s.pop();
        s.push(temp);
        //   cost++;



        // If coordinates == end coordinates
        // ...return stack
        if (temp.x == fx && temp.y == fy) {

            kian = s;
           // setCost(cost);              //Life Points
            setCost(roomcount); //since typical room = 1 and not going through portals...
            setRoomCount(roomcount);    //Room Count
            return kian;
        }



        //// All if statments are about the same...
        //// checks if there's a location above, below, or to the side of current location depending on direction
        //// if the location being checked is not a wall
        //// and if it has not been visited yet

        /// UP
        if (direction == 0) {

            if (temp.x - 1 >= 0 && maze[temp.x - 1][temp.y] == 0 && visited[temp.x - 1][temp.y] == true ) {

                Coordinates temp1(temp.x - 1, temp.y);  //new location
                visited[temp.x - 1][temp.y] = false;      //false == visited

                int amtToAdd = 1;

                s.push(temp1);
                cost = cost + amtToAdd;
                roomcount++;
            }
        }



            /// LEFT
        else if (direction == 1) {

            if (temp.y - 1 >= 0 && maze[temp.x][temp.y - 1] == 0 && visited[temp.x][temp.y - 1] == true) {

                Coordinates temp1(temp.x, temp.y - 1);  //new location
                visited[temp.x][temp.y - 1] = false;      //false == visited

                int amtToAdd = 1;

                s.push(temp1);
                cost = cost + amtToAdd;
                roomcount++;
            }
        }




            /// DOWN
        else if (direction == 2) {

            if (temp.x + 1 < n && maze[temp.x + 1][temp.y] == 0 && visited[temp.x + 1][temp.y] == true) {

                Coordinates temp1(temp.x + 1, temp.y);  //new location
                visited[temp.x + 1][temp.y] = false;      //false == visited

                int amtToAdd = 1;

                s.push(temp1);
                cost = cost + amtToAdd;
                roomcount++;
            }
        }


            /// RIGHT
        else if (direction == 3) {

            if (temp.y + 1 < m && maze[temp.x][temp.y + 1] == 0 && visited[temp.x][temp.y + 1] == true) {

                Coordinates temp1(temp.x, temp.y + 1);  //new location
                visited[temp.x][temp.y + 1] = false;      //false == visited

                int amtToAdd = 1;

                s.push(temp1);
                cost = cost + amtToAdd;
                roomcount++;
            }
        }


            // else...go back to where you came from
            // and pop
        else {
            visited[temp.x][temp.y] = true;
            s.pop();
            cost--;
            roomcount--;
        }
    }

    //if the stack is empty then just return an empty stack
    DSStack<Coordinates> falso;
    return falso;
}

//This one just returns the whole stack without popping
//The idea is to go through the whole maze and ignore portals
DSStack<Coordinates> MazeWork::NoPortalsNoPop(DSVector<DSVector<int>> maze, int n, int m,int startx, int starty, int fx, int fy, DSVector<DSVector<bool>> visited, DSVector<DSVector<Coordinates>> portals, DSVector<int> lifePoints, DSVector<bool> portalDone) {

    DSStack<Coordinates> kian;
    DSStack<Coordinates> s;
    Coordinates temp(startx, starty);

    int cost = 0;
    s.push(temp);

    while (!s.empty()) {

        //Set top of stack as temp and put it to work but also
        //Pop top coordinates and then look at all sides using if statements
        //...else go back

        temp = s.top();
        int direction = temp.dir;

        // Increment the direction and
        // push the Coordinates in the DSStack again.

        // Direction = integer
        // 0 = up
        // 1 = left
        // 2 = down
        // 3 = right
        temp.dir++;

        s.pop();
        s.push(temp);



        // If coordinates == end coordinates
        // ...return stack
        if (temp.x == fx && temp.y == fy) {
            setCost(cost);              //Life Points
            setRoomCount(roomcount);    //Room Count
            return kian;
        }


        //// All if statments are about the same...
        //// checks if there's a location above, below, or to the side of current location depending on direction
        //// if the location being checked is not a wall
        //// and if it has not been visited yet

        /// UP
        if (direction == 0) {

            if (temp.x - 1 >= 0 && maze[temp.x - 1][temp.y] == 0 && visited[temp.x - 1][temp.y] == true) {

                Coordinates temp1(temp.x - 1, temp.y);  //New location
                visited[temp.x - 1][temp.y] = false;      //false == visited

                int amtToAdd = 1;

                s.push(temp1);
                cost = cost + amtToAdd;
                roomcount++;

                kian.push(temp1);
            }
        }



            /// LEFT
        else if (direction == 1) {

            if (temp.y - 1 >= 0 && maze[temp.x][temp.y - 1] == 0 && visited[temp.x][temp.y - 1] == true) {

                Coordinates temp1(temp.x, temp.y - 1);  //new location
                visited[temp.x][temp.y - 1] = false;      //false == visited

                int amtToAdd = 1;

                s.push(temp1);
                cost = cost + amtToAdd;
                roomcount++;
                kian.push(temp1);
            }
        }




            /// DOWN
        else if (direction == 2) {

            if (temp.x + 1 < n && maze[temp.x + 1][temp.y] == 0 && visited[temp.x + 1][temp.y] == true) {

                Coordinates temp1(temp.x + 1, temp.y);  //new location
                visited[temp.x + 1][temp.y] = false;      //false == visited

                int amtToAdd = 1;

                s.push(temp1);
                cost = cost + amtToAdd;
                roomcount++;
                kian.push(temp1);
            }
        }


            /// RIGHT
        else if (direction == 3) {

            if (temp.y + 1 < m && maze[temp.x][temp.y + 1] == 0 && visited[temp.x][temp.y + 1] == true) {

                Coordinates temp1(temp.x, temp.y + 1);  //new location
                visited[temp.x][temp.y + 1] = false;      //false == visited

                int amtToAdd = 1;

                s.push(temp1);
                cost = cost + amtToAdd;
                roomcount++;
                kian.push(temp1);
            }
        }

            // else...go back to where you came from
            // no pop
        else {
            s.pop();
            visited[temp.x][temp.y] = true;
            // kian.pop();
        }
    }

    //if the stack is empty then just return an empty stack
    DSStack<Coordinates> falso;
    return falso;
}


DSStack<Coordinates> MazeWork::YesPortalsNoPop(DSVector<DSVector<int>> maze, int n, int m,int startx, int starty, int fx, int fy, DSVector<DSVector<bool>> visited, DSVector<DSVector<Coordinates>> portals, DSVector<int> lifePoints, DSVector<bool> portalDone) {

    DSStack<Coordinates> kian;
    DSStack<Coordinates> s;
    Coordinates temp(startx, starty);

  //  int cost = 0;
    s.push(temp);

    DSStack<Coordinates> returning;
    returning.push(temp);

    while (!s.empty()) {

        //Set top of stack as temp and put it to work but also
        //Pop top coordinates and then look at all sides using if statements
        //...else go back

        temp = s.top();
        int direction = temp.dir;

        // Increment the direction and
        // push the Coordinates in the DSStack again.

        // Direction = integer
        // 0 = up
        // 1 = left
        // 2 = down
        // 3 = right
        temp.dir++;

        s.pop();
        s.push(temp);


        // If coordinates == end coordinates
        // ...return stack
        if (temp.x == fx && temp.y == fy) {

            //kian = s;
            //cout << "cost  ===== " << cost << endl;
            setCost(cost);
            setRoomCount(roomcount);
            return kian;
        }

        //// All if statments are about the same...
        //// checks if there's a location above, below, or to the side of current location depending on direction
        //// if the location being checked is not a wall
        //// and if it has not been visited yet

        int amtToAdd = 1;

        /// UP
        if (direction == 0) {

            if (temp.x - 1 >= 0 && maze[temp.x - 1][temp.y] == 0 && visited[temp.x - 1][temp.y] ) {

                Coordinates temp1(temp.x - 1, temp.y);  //new location
                visited[temp.x - 1][temp.y] = false;      //false == visited

                /// Since this function is checking for portals...
                /// if the new location == enter portal location...
                /// set the location == to destination portal location

        //        int amtToAdd = 1;
                for(int i = 0; i < portals.size(); i++) {
                    if( (portals[i][0].x == temp1.x) && (portals[i][0].y == temp1.y) && (portalDone[i] != true) ) {
                        temp1.x = portals[i][1].x;
                        temp1.y = portals[i][1].y;
                        temp1.dir = 0;

                        amtToAdd = lifePoints[i];
                        portalDone[i] = true;
                    }
                }
                s.push(temp1);
                cost = cost + amtToAdd;
                roomcount++;
                kian.push(temp1);
            }
        }



            /// LEFT
        else if (direction == 1) {

            if (temp.y - 1 >= 0 && maze[temp.x][temp.y - 1] == 0 && visited[temp.x][temp.y - 1]) {

                Coordinates temp1(temp.x, temp.y - 1); //new location
                visited[temp.x][temp.y - 1] = false;     //false == visited

                /// Since this function is checking for portals...
                /// if the new location == enter portal location...
                /// set the location == to destination portal location

         //       int amtToAdd = 1;
                for(int i = 0; i < portals.size(); i++) {
                    if( (portals[i][0].x == temp1.x) && (portals[i][0].y == temp1.y) && (portalDone[i] != true) ) {
                        temp1.x = portals[i][1].x;
                        temp1.y = portals[i][1].y;
                        temp1.dir = 0;

                        amtToAdd = lifePoints[i];
                        portalDone[i] = true;
                    }
                }
                s.push(temp1);
                cost = cost + amtToAdd;
                roomcount++;
                kian.push(temp1);
            }
        }




            /// DOWN
        else if (direction == 2) {

            if (temp.x + 1 < n && maze[temp.x + 1][temp.y] == 0 && visited[temp.x + 1][temp.y]) {

                Coordinates temp1(temp.x + 1, temp.y);  //new location
                visited[temp.x + 1][temp.y] = false;      //visited == false

                /// Since this function is checking for portals...
                /// if the new location == enter portal location...
                /// set the location == to destination portal location

         //       int amtToAdd = 1;
                for(int i = 0; i < portals.size(); i++) {
                    if( (portals[i][0].x == temp1.x) && (portals[i][0].y == temp1.y) && (portalDone[i] != true) ) {
                        temp1.x = portals[i][1].x;
                        temp1.y = portals[i][1].y;
                        temp1.dir = 0;

                        amtToAdd = lifePoints[i];
                        portalDone[i] = true;
                    }
                }
                s.push(temp1);
                cost = cost + amtToAdd;
                roomcount++;
                kian.push(temp1);
            }
        }


            /// RIGHT
        else if (direction == 3) {

            if (temp.y + 1 < m && maze[temp.x][temp.y + 1] == 0 && visited[temp.x][temp.y + 1]) {

                Coordinates temp1(temp.x, temp.y + 1);  //new location
                visited[temp.x][temp.y + 1] = false;      //visited == false

                /// Since this function is checking for portals...
                /// if the new location == enter portal location...
                /// set the location == to destination portal location

        //        int amtToAdd = 1;
                for(int i = 0; i < portals.size(); i++) {
                    if( (portals[i][0].x == temp1.x) && (portals[i][0].y == temp1.y) && (portalDone[i] != true) ) {
                        temp1.x = portals[i][1].x;
                        temp1.y = portals[i][1].y;
                        temp1.dir = 0;

                        amtToAdd = lifePoints[i];
                        portalDone[i] = true;
                    }
                }
                s.push(temp1);
                cost = cost + amtToAdd;
                roomcount++;
                kian.push(temp1);
            }
        }

            // else...go back to where you came from
            // no pop
        else {
            s.pop();
            visited[temp.x][temp.y] = true;
            // kian.pop();
        }
    }

    //if the stack is empty then just return an empty stack
    DSStack<Coordinates> falso;
    return falso;
}

DSStack<Coordinates> MazeWork::YesPortalsYesPop(DSVector<DSVector<int>> maze, int n, int m,int startx, int starty, int fx, int fy, DSVector<DSVector<bool>> visited, DSVector<DSVector<Coordinates>> portals, DSVector<int> lifePoints, DSVector<bool> portalDone) {

    DSStack<Coordinates> kian;
    DSStack<Coordinates> s;
    Coordinates temp(startx, starty);

   // int cost = 0;
    s.push(temp);

    while (!s.empty()) {

        //Set top of stack as temp and put it to work but also
        //Pop top coordinates and then look at all sides using if statements
        //...else go back

        temp = s.top();
        int direction = temp.dir;

        // Increment the direction and
        // push the Coordinates in the DSStack again.

        // Direction = integer
        // 0 = up
        // 1 = left
        // 2 = down
        // 3 = right
        temp.dir++;

        s.pop();
        s.push(temp);




        // If coordinates == end coordinates
        // ...return stack
        if (temp.x == fx && temp.y == fy) {

            kian = s;
            //cout << "cost  ===== " << cost << endl;
            setCost(cost);
            setRoomCount(roomcount);
            return kian;
        }

        //// All if statments are about the same...
        //// checks if there's a location above, below, or to the side of current location depending on direction
        //// if the location being checked is not a wall
        //// and if it has not been visited yet

        int amtToAdd = 1;

        /// UP
        if (direction == 0) {

            if (temp.x - 1 >= 0 && maze[temp.x - 1][temp.y] == 0 && visited[temp.x - 1][temp.y] == true) {

                Coordinates temp1(temp.x - 1, temp.y);  //new location
                visited[temp.x - 1][temp.y] = false;      //false == visited

                /// Since this function is checking for portals...
                /// if the new location == enter portal location...
                /// set the location == to destination portal location

            //    int amtToAdd = 1;
                for(int i = 0; i < portals.size(); i++) {
                    if( (portals[i][0].x == temp1.x) && (portals[i][0].y == temp1.y) && (portalDone[i] != true) ) {
                        temp1.x = portals[i][1].x;
                        temp1.y = portals[i][1].y;
                        temp1.dir = 0;

                        amtToAdd = lifePoints[i];
                        portalDone[i] = true;
                    }
                }
                s.push(temp1);
                cost = cost + amtToAdd;
                roomcount++;
            }
        }

            /// LEFT
        else if (direction == 1) {

            if (temp.y - 1 >= 0 && maze[temp.x][temp.y - 1] == 0 && visited[temp.x][temp.y - 1] == true) {

                Coordinates temp1(temp.x, temp.y - 1);  //new location
                visited[temp.x][temp.y - 1] = false;      //visited == false

                /// Since this function is checking for portals...
                /// if the new location == enter portal location...
                /// set the location == to destination portal location

            //    int amtToAdd = 1;
                for(int i = 0; i < portals.size(); i++) {
                    if( (portals[i][0].x == temp1.x) && (portals[i][0].y == temp1.y) && (portalDone[i] != true) ) {
                        temp1.x = portals[i][1].x;
                        temp1.y = portals[i][1].y;
                        temp1.dir = 0;

                        amtToAdd = lifePoints[i];
                        portalDone[i] = true;
                    }
                }
                s.push(temp1);
                cost = cost + amtToAdd;
                roomcount++;
            }
        }




            /// DOWN
        else if (direction == 2) {

            if (temp.x + 1 < n && maze[temp.x + 1][temp.y] == 0 && visited[temp.x + 1][temp.y] == true) {

                Coordinates temp1(temp.x + 1, temp.y);  //new location
                visited[temp.x + 1][temp.y] = false;      //false == visited

                /// Since this function is checking for portals...
                /// if the new location == enter portal location...
                /// set the location == to destination portal location

             //   int amtToAdd = 1;
                for(int i = 0; i < portals.size(); i++) {
                    if( (portals[i][0].x == temp1.x) && (portals[i][0].y == temp1.y) && (portalDone[i] != true) ) {
                        temp1.x = portals[i][1].x;
                        temp1.y = portals[i][1].y;
                        temp1.dir = 0;

                        amtToAdd = lifePoints[i];
                        portalDone[i] = true;
                    }
                }
                s.push(temp1);
                cost = cost + amtToAdd;
                roomcount++;
            }
        }


            /// RIGHT
        else if (direction == 3) {

            if (temp.y + 1 < m && maze[temp.x][temp.y + 1] == 0 && visited[temp.x][temp.y + 1] == true) {

                Coordinates temp1(temp.x, temp.y + 1);  //new location
                visited[temp.x][temp.y + 1] = false;      //false == visited

                /// Since this function is checking for portals...
                /// if the new location == enter portal location...
                /// set the location == to destination portal location

            //    int amtToAdd = 1;
                for(int i = 0; i < portals.size(); i++) {
                    if( (portals[i][0].x == temp1.x) && (portals[i][0].y == temp1.y) && (portalDone[i] != true) ) {
                        temp1.x = portals[i][1].x;
                        temp1.y = portals[i][1].y;
                        temp1.dir = 0;

                        amtToAdd = lifePoints[i];
                        portalDone[i] = true;
                    }
                }
                s.push(temp1);
                cost = cost + amtToAdd;
                roomcount++;
            }
        }

            // else...go back to where you came from
            // and pop
        else {
            visited[temp.x][temp.y] = true;
            s.pop();
            cost = cost - amtToAdd;
            roomcount--;
        }
    }

    //if the stack is empty then just return an empty stack
    DSStack<Coordinates> falso;
    return falso;
}


void MazeWork::setCost(int num) {
    cost = num;
}
int MazeWork::getCost() {
    return cost;
}
void MazeWork::setRoomCount(int num) {
    roomcount = num;
}
int MazeWork::getRoomCount() {
    return roomcount;
}


void MazeWork::outputShortest(char *filename, DSVector<DSVector<Coordinates>> comparisons, DSVector<MazeWork> mazePaths, DSVector<DSVector<Coordinates>> portals,  DSVector<int> lifePoints) {
    DSVector<Coordinates> temp = comparisons[0];

    ofstream shortest(filename);

    DSList<int> costers;
    int tempo;
    for(int i = 0; i < mazePaths.size(); i++) {
        costers.push_back(mazePaths[i].getCost());
    }
    for(int i = 0; i < comparisons.size(); i++){
        if(comparisons[i].size() > 0) {
            tempo = i;
            break;
        }
    }

    for(int i = 0; i < costers.getSize(); i++) {
        if(costers[i] == costers[tempo]) {
            if(comparisons[i].size() < comparisons[tempo].size())
                tempo = i;
        }
        else if(costers[i] < costers[tempo] && comparisons[i].size() != 0)
            tempo = i;
    }

    //tempo = 3;
    temp = comparisons[tempo];
    bool usesPortals = false;
    if(tempo > 1)
        usesPortals = true;


    //////////////// SHORTEST PATH ///////////////////
    shortest << costers[tempo] <<  endl;
    shortest << comparisons[tempo].size() << endl;


    //output path

    for(int j = 0; j < temp.size(); j++) {
        Coordinates temp1(temp[j].x, temp[j].y);

        int roomCost = 1;
        for(int i = 0; i < portals.size(); i++) {
            if( (portals[i][1].x == temp1.x) && (portals[i][1].y == temp1.y) && (usesPortals == true)) {
                roomCost = lifePoints[i];
            }
        }
        shortest << temp[j].x +1 << ", " << temp[j].y +1 << ", " << roomCost << endl;
    }

}


void MazeWork::outputLongest(char *filename, DSVector<DSVector<Coordinates>> comparisons, DSVector<MazeWork> mazePaths, DSVector<DSVector<Coordinates>> portals, DSVector<int> lifePoints) {
    DSVector<Coordinates> temp = comparisons[0];

    ofstream longest(filename);

    //if temp > size then that is temp

    DSList<int> costers;
    int tempo;
    for(int i = 0; i < mazePaths.size(); i++) {
        costers.push_back(mazePaths[i].getCost());
    }
    for(int i = 0; i < comparisons.size(); i++){
        if(comparisons[i].size() > 0) {
            tempo = i;
            break;
        }
    }

    for(int i = 0; i < costers.getSize(); i++) {
        if(costers[i] == costers[tempo]) {
            if(comparisons[i].size() > comparisons[tempo].size())
                tempo = i;

        }
        else if(costers[i] > costers[tempo] && comparisons[i].size() != 0)
            tempo = i;
    }

    //tempo = 3;
    temp = comparisons[tempo];
    bool usesPortals = false;
    if(tempo > 1)
        usesPortals = true;

    //////////////// LONGEST PATH ///////////////////
    longest << costers[tempo] << endl;
    longest << comparisons[tempo].size() << endl;



    for(int j = 0; j < temp.size(); j++) {
        Coordinates temp1(temp[j].x, temp[j].y);

        int roomCost = 1;
        for(int i = 0; i < portals.size(); i++) {
            if( (portals[i][1].x == temp1.x) && (portals[i][1].y == temp1.y) && (usesPortals == true)) {
                roomCost = lifePoints[i];
            }
        }
        longest << temp[j].x +1 << ", " << temp[j].y +1 << ", " << roomCost << endl;
    }

}

void MazeWork::ReadInFile(char *filename, char* output1, char* output2) {
    ifstream file(filename);

    //get first line
    char firstline[100];
    file.getline(firstline, '\n');

    //get rows and cols
    char *pch;
    pch = strtok(firstline, " ");
    int rows = atoi(pch);
    pch = strtok(NULL, "\n");
    int cols = atoi(pch);



    // create map

    for (int i = 0; i < rows; i++) {
        DSVector<int> line;

        char buffer[100];
        file.getline(buffer, 100, '\n');
        for (int j = 0; j < cols; j++) {
            line.push_back(buffer[j] - '0');
        }
        graph.push_back(line);
    }


    //get portals

    char portalLine[100];
    file.getline(portalLine, 100, '\n');
    char* pch2;
    pch2 = strtok(portalLine, " ");
    int portalCount = atoi(pch2);

    for(int i = 0; i < portalCount; i++) {
        char buffer[100];
        file.getline(buffer, 100, '\n');


        char *pch;
        pch = strtok(buffer, " ");
        int portalstartx = atoi(pch);
        pch = strtok(NULL, " ");
        int portalstarty = atoi(pch);

        Coordinates source(portalstartx -1, portalstarty-1);

        pch = strtok(NULL, " ");
        int portalendx = atoi(pch);
        pch = strtok(NULL, " ");
        int portalendy = atoi(pch);
        pch = strtok(NULL, "\n");
        int lifepointers = atoi(pch);

        Coordinates destination(portalendx-1, portalendy-1);

        DSVector<Coordinates> temp;
        temp.push_back(source);
        temp.push_back(destination);

        portals.push_back(temp);
        lifePoints.push_back(lifepointers);
        portalDone.push_back(false);

    }

    //get start location

    char startline[100];
    file.getline(startline, 100, '\n');

    char *starlinepch;
    starlinepch = strtok(startline, " ");
    //char *startletter = starlinepch;
    starlinepch = strtok(NULL, " ");
    int startx = atoi(starlinepch);
    starlinepch = strtok(NULL, "\n");
    int starty = atoi(starlinepch);


    //get end location

    char endline[100];
    file.getline(endline, 100, '\n');

    char *endlinepch;
    endlinepch = strtok(endline, " ");
    // char *endletter = endlinepch;
    endlinepch = strtok(NULL, " ");
    int endx = atoi(endlinepch);
    endlinepch = strtok(NULL, "\n");
    int endy = atoi(endlinepch);


    // create 2d bool vector for checking if i have been to a location or not
    // same size as maze

    for (int i = 0; i < rows; i++) {
        DSVector<bool> temp;
        for (int j = 0; j < cols; j++) {
            temp.push_back(true);
        }
        visitedd.push_back(temp);
    }



    MazeWork NoPortalNoPop;
    DSStack<Coordinates> allChances = NoPortalNoPop.NoPortalsNoPop(graph, rows, cols, startx-1, starty-1, endx-1, endy-1, visitedd, portals, lifePoints, portalDone);
    DSVector<Coordinates> noPortNoPopList = allChances.getList();

    MazeWork NoPortalYesPop;
    DSStack<Coordinates> noPort = NoPortalYesPop.NoPortalsYesPop(graph, rows, cols, startx-1, starty-1, endx-1, endy-1, visitedd, portals, lifePoints, portalDone);
    DSVector<Coordinates> noPortListYesPop = noPort.getList();

    MazeWork yesPortalNoPop;
    DSStack<Coordinates> allChancesWithPortals = yesPortalNoPop.YesPortalsNoPop(graph, rows, cols, startx-1, starty-1, endx-1, endy-1, visitedd, portals, lifePoints, portalDone);
    DSVector<Coordinates> yesPortNoPopList = allChancesWithPortals.getList();

    MazeWork yesPortalyesPop;
    DSStack<Coordinates> yesPort = yesPortalyesPop.YesPortalsYesPop(graph, rows, cols, startx-1, starty-1, endx-1, endy-1, visitedd, portals, lifePoints, portalDone);
    DSVector<Coordinates> yesPortListYesPop = yesPort.getList();


    // vector and temp for checking shortest and longest paths

    DSVector<MazeWork> mazePaths;
    mazePaths.push_back(NoPortalYesPop);
    mazePaths.push_back(NoPortalNoPop);
    mazePaths.push_back(yesPortalNoPop);
    mazePaths.push_back(yesPortalyesPop);

    DSVector<DSVector<Coordinates>> comparisons;
    comparisons.push_back(noPortListYesPop);
    comparisons.push_back(noPortNoPopList);
    comparisons.push_back(yesPortNoPopList);
    comparisons.push_back(yesPortListYesPop);


    MazeWork final;
    final.outputShortest(output1, comparisons, mazePaths, portals, lifePoints);
    final.outputLongest(output2, comparisons, mazePaths, portals, lifePoints);

}