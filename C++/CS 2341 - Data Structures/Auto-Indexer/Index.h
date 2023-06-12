//
// Created by kianr on 3/5/2021.
//

#ifndef INC_21S_PA02_INDEX_H
#define INC_21S_PA02_INDEX_H

#include "DSString.h"
#include "DSVector.h"
#include "Words.h"

class Index {
public:
    DSVector<DSString> takeInKeyWords(char * in);
    DSVector<Words> takeInBook(char* in, DSVector<DSString> &keywordVector);
    DSVector<Words> finalVersion(DSVector<Words>& list, DSVector<DSString>& keywordVector);
    DSVector<Words> finalitoo(DSVector<Words> finalV);

    void output(char* in, DSVector<Words> finalito);
};


#endif //INC_21S_PA02_INDEX_H
