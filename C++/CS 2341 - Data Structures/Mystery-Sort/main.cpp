#include <iostream>
#include <chrono>
#include "include/sorting_library.h"

#include "Sorts.h"

using namespace std;

int main() {




    ////////////////////////////////////////
    //make some data to sort
    int data[50];
    for (int i = 0; i < 50; i++)
        data[i] = i;


    int hundred[300];
    for (int i = 1; i <= 300; i++)
        hundred[i] = i;

    int hundredreverse[300];
    for(int i = 0; i < 300; i++)
        hundredreverse[i] = 300-i;

    int hundredrand[300];
    srand(time(0)); //got this from online
    for(int i = 0; i < 300; i++) {
        hundredrand[i] = rand()%300+1;
    }



    //must copy the pre-existing arrays to other arrays to keep the same elements and prevent from using same array

    ////////////////////////////////////////////////////////////////////////////

    Sorts sorted;

    /////////////// SORTED //////////////

    //mystery 1-5
    sorted.sortManager(10, hundred, 300);

    int hundred2[300];
    copy(begin(hundred), end(hundred), begin(hundred2));
    sorted.sortManager(11, hundred2, 300);

    int hundred3[300];
    copy(begin(hundred), end(hundred3), begin(hundred3));

    int hundred4[300];
    copy(begin(hundred), end(hundred), begin(hundred4));
    sorted.sortManager(12, hundred4, 300);

    int hundred5[300];
    copy(begin(hundred), end(hundred), begin(hundred5));
    sorted.sortManager(13, hundred5, 300);

    int hundred6[300];
    copy(begin(hundred), end(hundred), begin(hundred6));
    sorted.sortManager(14, hundred6, 300);


    cout << endl << endl;
    cout << "SORTED PRINT FUNCTION" << endl;
    sorted.printTimings();
    cout << endl;



    /////////////// REVERSE /////////////

    Sorts reverse;


    int hundredreverse2[300];
    copy(begin(hundredreverse), end(hundredreverse), begin(hundredreverse2));
    reverse.sortManager(10, hundredreverse2, 300);

    int hundredreverse3[300];
    copy(begin(hundredreverse), end(hundredreverse), begin(hundredreverse3));
    reverse.sortManager(11, hundredreverse3, 300);

    int hundredreverse4[300];
    copy(begin(hundredreverse), end(hundredreverse), begin(hundredreverse4));
    reverse.sortManager(12, hundredreverse4, 300);

    int hundredreverse5[300];
    copy(begin(hundredreverse), end(hundredreverse), begin(hundredreverse5));
    reverse.sortManager(13, hundredreverse5, 300);

    int hundredreverse6[300];
    copy(begin(hundredreverse), end(hundredreverse), begin(hundredreverse6));
    reverse.sortManager(14, hundredreverse6, 300);


    cout << endl << endl;
    cout << "REVERSE PRINT FUNCTION" << endl;
    reverse.printTimings();
    cout << endl;



    /////////////// RANDOM /////////////

    Sorts random;


    int hundredrandom2[300];
    copy(begin(hundredrand), end(hundredrand), begin(hundredrandom2));
    random.sortManager(10, hundredrandom2, 300);

    int hundredrandom3[300];
    copy(begin(hundredrand), end(hundredrand), begin(hundredrandom3));
    random.sortManager(11, hundredrandom3, 300);

    int hundredrandom4[300];
    copy(begin(hundredrand), end(hundredrand), begin(hundredrandom4));
    random.sortManager(12, hundredrandom4, 300);

    int hundredrandom5[300];
    copy(begin(hundredrand), end(hundredrand), begin(hundredrandom5));
    random.sortManager(13, hundredrandom5, 300);

    int hundredrandom6[300];
    copy(begin(hundredrand), end(hundredrand), begin(hundredrandom6));
    random.sortManager(14, hundredrandom6, 300);


    cout << endl << endl;
    cout << "RANDOM PRINT FUNCTION" << endl;
    random.printTimings();
    cout << endl;


    ///////////////////////////////////////////////////




    return 0;
}
