#define CATCH_CONFIG_RUNNER
#include "catch.h"

#include <iostream>
#include "MazeWork.h"


using namespace std;


int main(int argc, char** argv) {

    if (argc == 1) {
        Catch::Session().run();
    }
    else {
        MazeWork final;
        final.ReadInFile(argv[1], argv[2], argv[3]);
    }
    return 0;
} 
 