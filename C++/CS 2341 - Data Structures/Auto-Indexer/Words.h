//
// Created by kianr on 2/24/2021.
//

#ifndef INC_21S_PA02_WORDS_H
#define INC_21S_PA02_WORDS_H

#include "DSString.h"
#include "DSVector.h"




class Words {
private:

    DSString word;
    DSVector<DSString> pageNos;

public:
    Words();
    Words(const Words &copyWord);
    Words(const DSString &copyWord);

    void setWord(const DSString& newWord);
    DSString getWord();
    void setPageNo(const DSString& page);
    DSVector<DSString> getPageNo();

    bool operator==(const Words& newWord) const;
};


#endif //INC_21S_PA02_WORDS_H
