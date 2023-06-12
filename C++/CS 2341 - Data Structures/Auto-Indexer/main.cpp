#define CATCH_CONFIG_RUNNER
#include "catch.h"

#include <fstream>
#include <iostream>

#include "DSString.h"
#include "DSVector.h"
#include "Words.h"
#include "Index.h"

using namespace std;




int main(int argc, char** argv) {

    if (argc == 1)
        Catch::Session().run();
    else {

        Index index;

        // TAKE IN KEYWORDS
        DSVector<DSString> keywordVector = index.takeInKeyWords(argv[2]);

        //READ IN FILE
        DSVector<Words> list = index.takeInBook(argv[1], keywordVector);

        //LOOK THROUGH VECTORS AND FIND THE ORIGINAL
        DSVector<Words> finalV = index.finalVersion(list, keywordVector);

        //GET LAST VECTOR FOR OUPUT
        DSVector<Words> finalito = index.finalitoo(finalV);

        //OUTPUT
        index.output(argv[3], finalito);


        return 0;

    }
}
