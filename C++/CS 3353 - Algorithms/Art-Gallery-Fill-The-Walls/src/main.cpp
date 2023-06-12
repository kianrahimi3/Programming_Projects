#include <iostream>
#include <fstream>
#include <vector>

#include "BruteForce.h"
#include "MostExpensive.h"
#include "ByShortest.h"

using namespace std;
int main(int argc, char* argv[]) {
    if (argc == 2) {

        ifstream myFile(argv[1]);
        if(myFile.bad()) {
            ofstream output1("testing-bruteforce.txt");
            ofstream output2("testing-mostexpensive.txt");
            ofstream output3("testing-shortest.txt");

            output1 << "File has issues" << endl;
            output2 << "File has issues" << endl;
            output3 << "File has issues" << endl;

            return 0;
        }

        int rows;
        int cols;
        myFile >> rows;
        myFile >> cols;

        int noPaintings = 0;
        myFile >> noPaintings;
        vector<vector<int>> paintings;

        for (int i = 0; i < noPaintings; i++) {
            int id;
            int price;
            int row1;
            int col1;

            myFile >> id >> price >> row1 >> col1;

            vector<int> painting;
            painting.push_back(id);
            painting.push_back(price);
            painting.push_back(row1);
            painting.push_back(col1);
            paintings.push_back(painting);
        }

        BruteForce bf;
        bf.setPaintings(paintings);
        bf.Brute(bf.getPaintings(), rows, cols);

        MostExpensive me;
        me.setPaintings(paintings);
        vector<vector<int>> vec = me.Expensive(me.getPaintings(), rows, cols);

        ByShortest shorts;
        shorts.setPaintings(paintings);
        vector<vector<int>> vec2 = shorts.Shortest(shorts.getPaintings(), rows, cols);



    }
    else if(argc > 1)
        cout << "Too many arguments...Please try again" << endl;
    else
        cout << "Too little arguments...Please try again" << endl;
}
