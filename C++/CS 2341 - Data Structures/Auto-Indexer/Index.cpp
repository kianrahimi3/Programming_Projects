//
// Created by kianr on 3/5/2021.
//

#include "Index.h"
#include "DSString.h"
#include <fstream>
#include <sstream>


DSVector<DSString> Index::takeInKeyWords(char* in) {

    ifstream keywordFile(in);

    DSVector<DSString> keywordVector;

    char keyWordBuffer[50000];
    while(keywordFile.getline(keyWordBuffer, 50000, '\n')) {
        for(int i = 0; i < 50000; i++) {
            keyWordBuffer[i] = tolower(keyWordBuffer[i]);
        }
        keywordVector.push_back(keyWordBuffer);
    }

    return keywordVector;
}



DSVector<Words> Index::takeInBook(char* in, DSVector<DSString> &keywordVector) {
    ifstream input(in);
    char buffer[50000];

    DSString pageString;

    //put all lines into one string
    DSString large("");
    while (input >> buffer) {
        DSString stringBuffer(buffer);
        DSString stringSpace(" ");

        // DSString large will hold the whole file in one string
        large = large + stringBuffer;
        large = large + stringSpace;
    }



    //take in every word of large string
    stringstream ss(large);
    ss << large;

    DSVector<Words> list;

    char newBuffer[800];
    //every time it hits a new page no...new line
    while (ss.getline(newBuffer, 800, '<')) {
        stringstream pageNo;
        pageNo << newBuffer;


        //set the page no
        char page[5];
        //if i do this..it removes the page number from list of words
        //...leaves blank
        pageNo.getline(page, 5, '>');
        if (strcmp(page, "-1") == 0)
            break;

        //save pages for later
        pageString = page;

        // cout << pageString << endl;


        //now go word by word
        //this loop runs per page
        char test[80];
        while (pageNo.getline(test, 80, ' ')) {

            DSString newWord;

            for(int i = 0; i < 50000; i++) {
                test[i] = tolower(test[i]);
            }

            DSString string1(test);
            // cout << test << endl;
            newWord = string1;
            //  cout << newWord << endl;

            //     }


            //if these punctuations exist, take them out
            if(newWord[newWord.getLength()-1] == '.') {
                newWord[newWord.getLength()-1] = '\0';
            }
            else if(newWord[newWord.getLength()-1] == ',') {
                newWord[newWord.getLength()-1] = '\0';
            }

            Words word(newWord);
            word.setPageNo(pageString);


            bool exists = false;

            for(int i = 0; i < list.size(); i++) {
                if(strcmp(list[i].getWord().c_str(), word.getWord().c_str()) == 0) {
                    bool pageExists = false;
                    for(int j = 0; j < list[i].getPageNo().size(); j++) {
                        if(list[i].getPageNo()[j] == pageString)
                            pageExists = true;
                    }
                    if(pageExists == false)
                        list[i].setPageNo(pageString);
                    exists = true;
                }
            }
            //create the list of words
            if(exists == false)
                list.push_back(word);
        }
    }



    // for phrases
    for(int i = 0; i < keywordVector.size(); i++) {
        DSString keywordTemp(keywordVector[i]);
        DSString space(" ");

        for(int j = 0; j < list.size(); j++) {
            DSString listTemp1(list[j].getWord());
            DSString listTemp2;

            //if the word ahead does not exist due to size...leave it blank
            if(j+1 >= list.size()) {
                listTemp2 = "";

                //else set it to the future word
            } else
                listTemp2 = list[j+1].getWord();


            if(keywordTemp[keywordTemp.getLength()-1] == '\r' ) {
                keywordTemp[keywordTemp.getLength()-1] = '\0';
            }


            //current word + space + future word
            DSString temp = listTemp1 + space + listTemp2;
            Words word(temp);



            if(keywordTemp == temp) {
                //  cout << keywordTemp << " == " << temp << endl;

                for(int b = 0; b < list[j].getPageNo().size(); b++) {
                    word.setPageNo(list[j].getPageNo()[b]);
                }
                //   cout << temp << ": ";
                for(int b = 0; b < word.getPageNo().size(); b++) {
                    //  cout << word.getPageNo()[b] << " ";
                }
                //   cout << endl;

                list.push_back(word);
            }

        }
    }

    return list;
}

DSVector<Words> Index::finalVersion(DSVector<Words>& list, DSVector<DSString>& keywordVector) {
    DSVector<Words> finalV;

    for(int i = 0; i < keywordVector.size(); i++) {
        DSString str1(keywordVector[i]);
        for(int j = 0; j < list.size(); j++) {

            // /r was being pulled for some reason
            // cut it short if so
            DSString str3("");
            if(str1[str1.getLength()-1] == '\r' ) {
                //str1[str1.getLength()-1] = '\0';
                for(int i = 0; i < str1.getLength()-1; i++) {
                    str3[i] = str1[i];
                }
                str3[str1.getLength()-1] = '\0';
            }
            else {
                for(int i = 0; i < str1.getLength(); i++) {
                    str3[i] = str1[i];
                }
                str3[str1.getLength()] = '\0';
            }

            DSString str2 (list[j].getWord());


            //check if string3 and string2 are equal
            //...if so, put in new final vector...with pages
            if(str2 == str3 ) {
                Words word(list[j].getWord());

                for(int n = 0; n < list[j].getPageNo().size(); n++) {
                    word.setPageNo(list[j].getPageNo()[n]);
                }
                finalV.push_back(word);
                //cout << str2 << " == " << str1 << endl;
                // finalV.push_back(cleaned[j]);
            }
        }
    }

    //sort list
    for(int i = 0; i < list.size() - 1; i++) {
        for(int j = i+1; j < list.size(); j++) {

            if(strcmp(list[i].getWord().c_str(), list[j].getWord().c_str()) > 0) {
                Words temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }


    //sort list
    for(int i = 0; i < finalV.size() - 1; i++) {
        for(int j = i+1; j < finalV.size(); j++) {

            if(strcmp(finalV[i].getWord().c_str(), finalV[j].getWord().c_str()) > 0) {
                Words temp = finalV[i];
                finalV[i] = finalV[j];
                finalV[j] = temp;
            }
        }
    }


    return finalV;
}


DSVector<Words> Index::finalitoo(DSVector<Words> finalV) {
    DSVector<Words> finalito;

    for(int i = 0; i < finalV.size(); i++) {
        DSString temp(finalV[i].getWord());

        Words word(temp);

        if(i+1 >= finalV.size() || i == 0) {
            //word = finalV[i];

            for(int z = 0; z < finalV[i].getPageNo().size(); z++) {
                word.setPageNo(finalV[i].getPageNo()[z]);
            }

            finalito.push_back(word);
        }


        else {
            DSString test1(finalV[i].getWord().c_str());
            DSString test2(finalV[i+1].getWord().c_str());

            //check if equal...if so push it back to final
            if(strcmp(test1.c_str(), test2.c_str()) == 0) {
                //  word = finalV[i];


                for(int z = 0; z < finalV[i+1].getPageNo().size(); z++) {
                    word.setPageNo(finalV[i+1].getPageNo()[z]);
                }


                finalito.push_back(word);
            }

            //or else....
            else {
                DSString test3(finalV[i].getWord().c_str());
                DSString test4(finalV[i-1].getWord().c_str());

                //if i == i-1 then nothing
                if(strcmp(test3.c_str(), test4.c_str()) == 0) {
                    //nothing

                    //else push it to final
                } else {
                    //word = finalV[i];

                    for(int c = 0; c < finalV[i].getPageNo().size(); c++) {
                        word.setPageNo(finalV[i].getPageNo()[c]);
                    }

                    finalito.push_back(word);
                }
            }
        }
    }



    //sort list
    for(int i = 0; i < finalito.size() - 1; i++) {
        for(int j = i+1; j < finalito.size(); j++) {

            if(strcmp(finalito[i].getWord().c_str(), finalito[j].getWord().c_str()) > 0) {
                Words temp = finalito[i];
                finalito[i] = finalito[j];
                finalito[j] = temp;
            }
        }
    }



    //trying something for pages idk
    for(int i = 0; i < finalito.size(); i++) {
        for(int j = 0; j < finalito[i].getPageNo().size(); j++) {
            for(int k = j+1; k < finalito[i].getPageNo().size(); k++) {
                if((finalito[i].getPageNo()[j].c_str() > finalito[i].getPageNo()[k].c_str()) ) {
                    DSString temp = finalito[i].getPageNo()[j];
                    finalito[i].getPageNo()[j] = finalito[i].getPageNo()[k];
                    finalito[i].getPageNo()[k] = temp;
                }
            }
        }
    }
    return finalito;
}


void Index::output(char* in, DSVector<Words> finalito) {
    ofstream output(in);

    char curr;
    char prev;

    // cout << endl << endl;

    for (int i = 0; i < finalito.size(); i++) {
        DSString temp = finalito[i].getWord();
        curr = toupper(temp[0]);

        if (i >= 1) {
            DSString checkPrev = finalito[i - 1].getWord();
            prev = toupper(checkPrev[0]);
        }

        if (curr != prev)
            output << "[" << curr << "]" << endl;

        output << finalito[i].getWord() << ": ";

        for(int j = 0; j < finalito[i].getPageNo().size(); j++) {
            output << finalito[i].getPageNo()[j] << " ";
        }

        output << endl;

    }
}