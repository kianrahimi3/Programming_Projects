//
// Created by kianr on 2/24/2021.
//

#include "Words.h"

Words::Words() {
    word = "";
}

Words::Words(const Words &copyWord) {
    word = copyWord.word;
    pageNos = copyWord.pageNos;
}

Words::Words(const DSString &copyWord) {
    //pages stay the same
    word = copyWord;
}

void Words::setWord(const DSString &newWord) {
    word = newWord;
}
DSString Words::getWord() {
    return word;
}

void Words::setPageNo(const DSString &page) {
    pageNos.push_back(page);
}
DSVector<DSString> Words::getPageNo() {
    return pageNos;
}

//not sure why i need this
bool Words::operator==(const Words &newWord) const {
    {
        bool maybe = false;
        if(word == newWord.word)
            maybe = true;
        return maybe;
    }
}