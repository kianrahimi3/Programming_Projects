//
// Created by kianr on 10/1/2021.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <list>

#include "Vector.h"
#include "AVLTree.h"
#include "Algos.cpp"
#include "DSList.h"



using namespace std;
int main() {

    int sizes[] = {1000, 10000, 100000, 500000, 1000000, 2000000};
    map<string, chrono::duration<double>> sorts;
    int size = sizeof(sizes) / sizeof(sizes[0]);

    for(int i = 0; i < size; i++) {
        Vector<int> quickNoDupe;
        Vector<int> quickNoDupeASC;
        Vector<int> quickNoDupeDSC;
        Vector<int> quick20Dupe;
        Vector<int> quick40Dupe;

        quickNoDupe = randomNumberGen(sizes[i], quickNoDupe, 0, 0);
        chrono::duration<double> quickNoDupe_time_in_seconds = quickSortRun(quickNoDupe);
        string title1 = to_string(sizes[i]) + " quick 0% int random sort";
        sorts.insert(pair<string, chrono::duration<double>>(title1, quickNoDupe_time_in_seconds));

    //    // << "quickNoDupe DONE " << sizes[i] << endl;
    //    for(auto x = quickNoDupe.random_begin(); x != quickNoDupe.random_end(); x++)
    //        // << *x << " ";
        // << "quickNoDupe DONE " << sizes[i];
        // << endl;

        quickNoDupeASC = randomNumberGen(sizes[i], quickNoDupeASC, 0, 1, 0);
        chrono::duration<double> quickNoDupeASC_time_in_seconds = quickSortRun(quickNoDupeASC);
        string title4 = to_string(sizes[i]) +" quickNoDupeASC 0% int random sort";
        sorts.insert(pair<string, chrono::duration<double>>(title4, quickNoDupeASC_time_in_seconds));

        // << "quickNoDupeASC DONE " << sizes[i] << endl;


        quickNoDupeDSC = randomNumberGen(sizes[i], quickNoDupeDSC, 0, 1, 1);
        chrono::duration<double> quickNoDupeDSC_time_in_seconds = quickSortRun(quickNoDupeDSC);
        string title5 = to_string(sizes[i]) +" quickNoDupeDSC 0% int random sort";
        sorts.insert(pair<string, chrono::duration<double>>(title5, quickNoDupeDSC_time_in_seconds));

        // << "quickNoDupeDSC DONE " << sizes[i] << endl;

        quick20Dupe = randomNumberGen(sizes[i], quick20Dupe, 20, 0);
        chrono::duration<double> quick20Dupe_time_in_seconds = quickSortRun(quick20Dupe);
        string title2 = to_string(sizes[i]) +" quick 20% int random sort";
        sorts.insert(pair<string, chrono::duration<double>>(title2, quick20Dupe_time_in_seconds));

        // << "quick20Dupe DONE " << sizes[i] << endl;

        quick40Dupe = randomNumberGen(sizes[i], quick40Dupe, 40, 0);
        chrono::duration<double> quick40Dupe_time_in_seconds = quickSortRun(quick40Dupe);
        string title3 = to_string(sizes[i]) +" quick 40% int random sort";
        sorts.insert(pair<string, chrono::duration<double>>(title3, quick40Dupe_time_in_seconds));

        // << "quick40Dupe DONE " << sizes[i] << endl;

    }





    for(int i = 0; i < size; i++) {
        Vector<string> quickNoDupe;
        Vector<string> quickNoDupeASC;
        Vector<string> quickNoDupeDSC;
        Vector<string> quick20Dupe;
        Vector<string> quick40Dupe;

        quickNoDupe = randomStringGen(sizes[i], quickNoDupe, 0, 0);
        chrono::duration<double> quickNoDupe_time_in_seconds = quickSortRun(quickNoDupe);
        string title1 = to_string(sizes[i]) + " quick 0% string random sort";
        sorts.insert(pair<string, chrono::duration<double>>(title1, quickNoDupe_time_in_seconds));

        // << "string quickNoDupe DONE " << sizes[i] << endl;

        quickNoDupeASC = randomStringGen(sizes[i], quickNoDupeASC, 0, 1, 0);
        chrono::duration<double> quickNoDupeASC_time_in_seconds = quickSortRun(quickNoDupeASC);
        string title4 = to_string(sizes[i]) +" quickNoDupeASC 0% string random sort";
        sorts.insert(pair<string, chrono::duration<double>>(title4, quickNoDupeASC_time_in_seconds));

        // << "string quickNoDupeASC DONE " << sizes[i] << endl;

        quickNoDupeDSC = randomStringGen(sizes[i], quickNoDupeDSC, 0, 1, 1);
        chrono::duration<double> quickNoDupeDSC_time_in_seconds = quickSortRun(quickNoDupeDSC);
        string title5 = to_string(sizes[i]) +" quickNoDupeDSC 0% string random sort";
        sorts.insert(pair<string, chrono::duration<double>>(title5, quickNoDupeDSC_time_in_seconds));

        // << "string quickNoDupeDSC DONE " << sizes[i] << endl;

        quick20Dupe = randomStringGen(sizes[i], quick20Dupe, 20, 0);
        chrono::duration<double> quick20Dupe_time_in_seconds = quickSortRun(quick20Dupe);
        string title2 = to_string(sizes[i]) +" quick 20% string random sort";
        sorts.insert(pair<string, chrono::duration<double>>(title2, quick20Dupe_time_in_seconds));

        // << "string quick20Dupe DONE " << sizes[i] << endl;

        quick40Dupe = randomStringGen(sizes[i], quick40Dupe, 40, 0);
        chrono::duration<double> quick40Dupe_time_in_seconds = quickSortRun(quick40Dupe);
        string title3 = to_string(sizes[i]) +" quick 40% string random sort";
        sorts.insert(pair<string, chrono::duration<double>>(title3, quick40Dupe_time_in_seconds));

        // << "string quick40Dupe DONE " << sizes[i] << endl;


    }




    for(int i = 0; i < size; i++) {
        Vector<int> heapNoDupe;
        Vector<int> heapNoDupeASC;
        Vector<int> heapNoDupeDSC;
        Vector<int> heap20Dupe;
        Vector<int> heap40Dupe;

        heapNoDupe = randomNumberGen(sizes[i], heapNoDupe, 0, 0);
        chrono::duration<double> heapNoDupe_time_in_seconds = quickSortRun(heapNoDupe);
        string title1 = to_string(sizes[i]) +" heap 0% int random sort" ;
        sorts.insert(pair<string, chrono::duration<double>>(title1, heapNoDupe_time_in_seconds));

        // << "heapNoDupe DONE " << sizes[i] << endl;

        heapNoDupeASC = randomNumberGen(sizes[i], heapNoDupeASC, 0, 1, 0);
        chrono::duration<double> heapNoDupeASC_time_in_seconds = heapSortRun(heapNoDupeASC);
        string title4 = to_string(sizes[i]) +" heapNoDupeASC int 0% random sort";
        sorts.insert(pair<string, chrono::duration<double>>(title4, heapNoDupeASC_time_in_seconds));

        // << "heapNoDupeASC DONE " << sizes[i] << endl;

        heapNoDupeDSC = randomNumberGen(sizes[i], heapNoDupeDSC, 0, 1, 1);
        chrono::duration<double> heapNoDupeDSC_time_in_seconds = heapSortRun(heapNoDupeDSC);
        string title5 = to_string(sizes[i]) +" heapNoDupeDSC 0% int random sort" ;
        sorts.insert(pair<string, chrono::duration<double>>(title5, heapNoDupeDSC_time_in_seconds));

        // << "heapNoDupeDSC DONE " << sizes[i] << endl;

        heap20Dupe = randomNumberGen(sizes[i], heap20Dupe, 20, 0);
        chrono::duration<double> heap20Dupe_time_in_seconds = quickSortRun(heap20Dupe);
        string title2 = to_string(sizes[i]) +" heap 20% int random sort";
        sorts.insert(pair<string, chrono::duration<double>>(title2, heap20Dupe_time_in_seconds));

        // << "heap20Dupe DONE " << sizes[i] << endl;

        heap40Dupe = randomNumberGen(sizes[i], heap40Dupe, 40, 0);
        chrono::duration<double> heap40Dupe_time_in_seconds = quickSortRun(heap40Dupe);
        string title3 = to_string(sizes[i]) +" heap 40% int random sort" ;
        sorts.insert(pair<string, chrono::duration<double>>(title3, heap40Dupe_time_in_seconds));

        // << "heap40Dupe DONE " << sizes[i] << endl;

    }



    for(int i = 0; i < size; i++) {
        Vector<string> heapNoDupe;
        Vector<string> heapNoDupeASC;
        Vector<string> heapNoDupeDSC;
        Vector<string> heap20Dupe;
        Vector<string> heap40Dupe;

        heapNoDupe = randomStringGen(sizes[i], heapNoDupe, 0, 0);

        chrono::duration<double> quickNoDupe_time_in_seconds = heapSortRun(heapNoDupe);
        string title1 = to_string(sizes[i]) + " heap 0% string random sort";
        sorts.insert(pair<string, chrono::duration<double>>(title1, quickNoDupe_time_in_seconds));

        // << "string heapNoDupe DONE " << sizes[i] << endl;

        heapNoDupeASC = randomStringGen(sizes[i], heapNoDupeASC, 0, 1, 0);
        chrono::duration<double> heapNoDupeASC_time_in_seconds = heapSortRun(heapNoDupeASC);
        string title4 = to_string(sizes[i]) +" heapNoDupeASC 0% string random sort";
        sorts.insert(pair<string, chrono::duration<double>>(title4, heapNoDupeASC_time_in_seconds));

        // << "string heapNoDupeASC DONE " << sizes[i] << endl;

        heapNoDupeDSC = randomStringGen(sizes[i], heapNoDupeDSC, 0, 1, 1);
        chrono::duration<double> heapNoDupeDSC_time_in_seconds = heapSortRun(heapNoDupeDSC);
        string title5 = to_string(sizes[i]) +" heapNoDupeDSC 0% string random sort";
        sorts.insert(pair<string, chrono::duration<double>>(title5, heapNoDupeDSC_time_in_seconds));

        // << "string heapNoDupeDSC DONE " << sizes[i] << endl;

        heap20Dupe = randomStringGen(sizes[i], heap20Dupe, 20, 0);
        chrono::duration<double> heap20Dupe_time_in_seconds = heapSortRun(heap20Dupe);
        string title2 = to_string(sizes[i]) +" heap 20% string random sort";
        sorts.insert(pair<string, chrono::duration<double>>(title2, heap20Dupe_time_in_seconds));

        // << "string heap20Dupe DONE " << sizes[i] << endl;

        heap40Dupe = randomStringGen(sizes[i], heap40Dupe, 40, 0);
        chrono::duration<double> heap40Dupe_time_in_seconds = heapSortRun(heap40Dupe);
        string title3 = to_string(sizes[i]) +" heap 40% string random sort";
        sorts.insert(pair<string, chrono::duration<double>>(title3, heap40Dupe_time_in_seconds));

        // << "string heap40Dupe DONE " << sizes[i] << endl;
    }




    for(int i = 0; i < size; i++) {
        Vector<int> insertNoDupe;
        Vector<int> insertNoDupeASC;
        Vector<int> insertNoDupeDSC;
        Vector<int> insert20Dupe;
        Vector<int> insert40Dupe;

        insertNoDupe = randomNumberGen(sizes[i], insertNoDupe, 0, 0);
        chrono::duration<double> insertNoDupe_time_in_seconds = insertSortRun(insertNoDupe);
        string title1 = to_string(sizes[i]) +" insertNoDupe 0% int random sort";
        sorts.insert(pair<string, chrono::duration<double>>(title1, insertNoDupe_time_in_seconds));

        // << "insertNoDupe DONE " << sizes[i] << endl;

        insertNoDupeASC = randomNumberGen(sizes[i], insertNoDupeASC, 0, 1, 0);
        chrono::duration<double> insertNoDupeASC_time_in_seconds = insertSortRun(insertNoDupeASC);
        string title4 = to_string(sizes[i]) +" insertNoDupeASC 0% int random sort";
        sorts.insert(pair<string, chrono::duration<double>>(title4, insertNoDupeASC_time_in_seconds));

        // << "insertNoDupeASC DONE " << sizes[i] << endl;

        insertNoDupeDSC = randomNumberGen(sizes[i], insertNoDupeDSC, 0, 1, 1);
        chrono::duration<double> insertNoDupeDSC_time_in_seconds = insertSortRun(insertNoDupeDSC);
        string title5 = to_string(sizes[i]) +" insertNoDupeDSC 0% int random sort" ;
        sorts.insert(pair<string, chrono::duration<double>>(title5, insertNoDupeDSC_time_in_seconds));

        // << "insertNoDupeDSC DONE " << sizes[i] << endl;

        insert20Dupe = randomNumberGen(sizes[i], insert20Dupe, 20, 0);
        chrono::duration<double> insert20Dupe_time_in_seconds = insertSortRun(insert20Dupe);
        string title2 = to_string(sizes[i]) +" insert 20% int random sort" ;
        sorts.insert(pair<string, chrono::duration<double>>(title2, insert20Dupe_time_in_seconds));

      //  // << "insert20Dupe DONE " << sizes[i] << endl;

        insert40Dupe = randomNumberGen(sizes[i], insert40Dupe, 40, 0);
        chrono::duration<double> insert40Dupe_time_in_seconds = insertSortRun(insert40Dupe);
        string title3 = to_string(sizes[i]) +" insert 40% int random sort" ;
        sorts.insert(pair<string, chrono::duration<double>>(title3, insert40Dupe_time_in_seconds));

       // << "insert40Dupe DONE " << sizes[i] << endl;
    }


    for(int i = 0; i < size; i++) {
        Vector<string> insertNoDupe;
        Vector<string> insertNoDupeASC;
        Vector<string> insertNoDupeDSC;
        Vector<string> insert20Dupe;
        Vector<string> insert40Dupe;

        insertNoDupe = randomStringGen(sizes[i], insertNoDupe, 0, 0);
        chrono::duration<double> insertNoDupe_time_in_seconds = heapSortRun(insertNoDupe);
        string title1 = to_string(sizes[i]) + " insert 0% string random sort";
        sorts.insert(pair<string, chrono::duration<double>>(title1, insertNoDupe_time_in_seconds));

       // << "string insertNoDupe DONE " << sizes[i] << endl;

        insertNoDupeASC = randomStringGen(sizes[i], insertNoDupeASC, 0, 1, 0);
        chrono::duration<double> insertNoDupeASC_time_in_seconds = heapSortRun(insertNoDupeASC);
        string title4 = to_string(sizes[i]) +" insertNoDupeASC 0% string random sort";
        sorts.insert(pair<string, chrono::duration<double>>(title4, insertNoDupeASC_time_in_seconds));

       // << "string insertNoDupeASC DONE " << sizes[i] << endl;

        insertNoDupeDSC = randomStringGen(sizes[i], insertNoDupeDSC, 0, 1, 1);
        chrono::duration<double> insertNoDupeDSC_time_in_seconds = heapSortRun(insertNoDupeDSC);
        string title5 = to_string(sizes[i]) +" insertNoDupeDSC 0% string random sort";
        sorts.insert(pair<string, chrono::duration<double>>(title5, insertNoDupeDSC_time_in_seconds));

       // << "string insertNoDupeDSC DONE " << sizes[i] << endl;

        insert20Dupe = randomStringGen(sizes[i], insert20Dupe, 20, 0);
        chrono::duration<double> insert20Dupe_time_in_seconds = heapSortRun(insert20Dupe);
        string title2 = to_string(sizes[i]) +" insert 20% string random sort";
        sorts.insert(pair<string, chrono::duration<double>>(title2, insert20Dupe_time_in_seconds));

       // << "string insert20Dupe DONE " << sizes[i] << endl;

        insert40Dupe = randomStringGen(sizes[i], insert40Dupe, 40, 0);
        chrono::duration<double> insert40Dupe_time_in_seconds = heapSortRun(insert40Dupe);
        string title3 = to_string(sizes[i]) +" insert 40% string random sort";
        sorts.insert(pair<string, chrono::duration<double>>(title3, insert40Dupe_time_in_seconds));

       // << "string insert40Dupe DONE " << sizes[i] << endl;

    }

    ofstream myFile;
    myFile.open("../src/performances.csv");
    myFile.clear();
    myFile << "Sort Method" << "," << "Time in seconds" << endl;
    for(auto it = sorts.begin(); it != sorts.end(); it++) {
        myFile << it->first << "," << fixed << it->second.count() << endl;
    }
}
