#include "catch.h"

#include <cstring>
#include "DSString.h"
#include "DSVector.h"
#include "DSList.h"
#include "DSStack.h"


TEST_CASE("String class", "[DSString]"){

DSString s[10];
s[0] = DSString("Kian");
s[1] = DSString("Rahimi");
s[2] = DSString("");
s[3] = DSString("SMU");
s[4] = DSString("Mustangs");
s[5] = DSString("\n");
s[6] = DSString("Kian");


SECTION("Equality operators"){
REQUIRE(s[0] == DSString("Kian"));
REQUIRE(s[0] == s[6]);
REQUIRE(s[2] == "");
REQUIRE(s[1] == "Rahimi");
REQUIRE(!(s[3] == s[4]));
}

SECTION("Assignment operators"){
DSString str;
str = "Rahimi";
REQUIRE(str == s[1]);
str = DSString("Kian");
REQUIRE(str == s[0]);
str = "";
REQUIRE(str == s[2]);
str = DSString("\n");
REQUIRE(str == s[5]);
}

SECTION("Addition operator"){
REQUIRE(DSString("KianRahimi") == s[0]+s[1]);
REQUIRE(s[2] + s[2] == "");
REQUIRE(s[5] + s[2] == DSString("\n"));
REQUIRE(s[0] + s[1] + s[6] == "KianRahimiKian");
}


SECTION("Greater than operator"){
REQUIRE(s[0] < s[1]);
REQUIRE(s[4] < s[3]);
REQUIRE(s[1] > s[6]);
REQUIRE(s[3] > s[1]);
}


SECTION("[] Operator"){
REQUIRE(s[0][1] == 'i');
REQUIRE(s[4][4] == 'a');
REQUIRE(s[6][0] == 'K');
}


SECTION("getLength function"){
REQUIRE(s[0].getLength() == 4);
REQUIRE(s[2].getLength() == 0);
REQUIRE(s[1].getLength() == 6);
REQUIRE(s[4].getLength() == 8);
}


SECTION("Substring function"){
REQUIRE(s[0].substring(0, 4) == "Kian");
REQUIRE(s[4].substring(1, 2) == "us");
REQUIRE(s[4].substring(1, 3) == "ust");
}

SECTION("c_str function"){
REQUIRE(strcmp(s[0].c_str(), "Kian") == 0);
REQUIRE(strcmp(s[0].c_str(), s[6].c_str()) == 0);
REQUIRE(strcmp(s[2].c_str(), "") == 0);
}

}
TEST_CASE("Vector class", "[DSVector]") {

DSVector<int> vec1;
DSVector<DSString> vec2;

SECTION("size function") {
REQUIRE(vec1.size() == 0);
REQUIRE(vec2.size() == 0);

vec1.push_back(1);
vec1.push_back(2);
vec1.push_back(3);
vec1.push_back(4);
vec1.push_back(5);

REQUIRE(vec1.size() == 5);

vec2.push_back("one");
vec2.push_back("two");
vec2.push_back("three");
vec2.push_back("four");
vec2.push_back("five");

REQUIRE(vec2.size() == 5);
}

SECTION("capsize function") {
vec1.push_back(1);
vec1.push_back(2);
vec1.push_back(3);
vec1.push_back(4);
vec1.push_back(5);
vec1.push_back(1);
vec1.push_back(2);
vec1.push_back(3);
vec1.push_back(4);

REQUIRE(vec1.capsize() == 10);

vec1.push_back(5);

REQUIRE(vec1.capsize() == 20);
}

SECTION("[] operator") {
vec1.push_back(1);
vec1.push_back(2);
vec1.push_back(3);
vec1.push_back(4);
vec1.push_back(5);

REQUIRE(vec1[0] == 1);
REQUIRE(vec1[1] == 2);
REQUIRE(vec1[2] == 3);
REQUIRE(vec1[3] == 4);
REQUIRE(vec1[4] == 5);

vec2.push_back("one");
vec2.push_back("two");
vec2.push_back("three");
vec2.push_back("four");
vec2.push_back("five");

REQUIRE(vec2[0] == "one");
REQUIRE(vec2[1] == "two");
REQUIRE(vec2[2] == "three");
REQUIRE(vec2[3] == "four");
REQUIRE(vec2[4] == "five");
}

SECTION("= Operator") {
vec1.push_back(1);
vec1.push_back(2);
vec1.push_back(3);
vec1.push_back(4);
vec1.push_back(5);

DSVector<int> tempVector;
tempVector = vec1;

REQUIRE(tempVector[0] == 1);
REQUIRE(tempVector[1] == 2);
REQUIRE(tempVector[2] == 3);
REQUIRE(tempVector[3] == 4);
REQUIRE(tempVector[4] == 5);

DSVector<DSString> vectorTemp;
vectorTemp.push_back("This is a test");

vec2 = vectorTemp;

REQUIRE(vec2[0] == "This is a test");
}

SECTION("pop_back function"){
vec1.push_back(1);
vec1.push_back(2);
vec1.push_back(3);

vec1.pop_back();

REQUIRE(vec1.size() == 2);

vec2.push_back("one");
vec2.push_back("two");
vec2.push_back("three");
vec2.push_back("four");
vec2.push_back("five");

vec2.pop_back();

REQUIRE(vec2.size() == 4);

vec2.pop_back();

REQUIRE(vec2.size() == 3);

}


}

    TEST_CASE("Linked List class", "[DSList]") {
    DSList<int> test;
    test.push_back(1);
    test.push_back(2);
    test.push_back(3);
    test.push_back(4);
    test.push_back(5);

    REQUIRE(test[0] == 1);
    REQUIRE(test[1] == 2);
    REQUIRE(test[2] == 3);
    REQUIRE(test[3] == 4);
    REQUIRE(test[4] == 5);


    DSList<DSString> stringtest;
    stringtest.push_back("Kian");
    stringtest.push_back("Rahimi");
    stringtest.push_back("SMU");
    stringtest.push_back("Mustangs");
    stringtest.push_back("Perunas");

    REQUIRE(stringtest[0] == "Kian");
    REQUIRE(stringtest[1] == "Rahimi");
    REQUIRE(stringtest[2] == "SMU");
    REQUIRE(stringtest[3] == "Mustangs");
    REQUIRE(stringtest[4] == "Perunas");


    SECTION("= operator") {

    }

    SECTION("Push_back") {
        DSList<char> charList;
        REQUIRE(charList.getSize() == 0);

        charList.push_back('a');
        charList.push_back('b');
        charList.push_back('c');

        REQUIRE(charList.getSize() == 3);
        REQUIRE(charList[0] == 'a');
        REQUIRE(charList[1] == 'b');
        REQUIRE(charList[2] == 'c');

        stringtest.push_back("My name is Kian Rahimi");
        REQUIRE(stringtest[5] == "My name is Kian Rahimi");
        REQUIRE(stringtest.getSize() == 6);
    }

    SECTION("Pop") {
        DSList<char> charList;

        charList.push_back('a');
        charList.push_back('b');
        charList.push_back('c');

        charList.pop();
        REQUIRE(charList.getSize() == 2);
        charList.pop();
        REQUIRE(charList.getSize() == 1);
        charList.pop();
        REQUIRE(charList.getSize() == 0);

        stringtest.pop();
        REQUIRE(stringtest.getSize() == 4);
    }

    SECTION("[] Operator") {
        DSList<int> listo;

        listo.push_back(1);
        listo.push_back(2);
        listo.push_back(3);
        listo.push_back(4);
        listo.push_back(5);

        REQUIRE(listo[0] == 1);
        REQUIRE(listo[1] == 2);
        REQUIRE(listo[2] == 3);
        REQUIRE(listo[3] == 4);
        REQUIRE(listo[4] == 5);

    }

}

TEST_CASE("Stack Class" "[DSStack]") {
    DSStack<int> stacko;


    DSStack<DSString> stackstring;


    SECTION("Push") {
        stacko.push(1);
        stacko.push(2);
        stacko.push(3);
        stacko.push(4);
        stacko.push(5);

        REQUIRE(stacko.size() == 5);


        stackstring.push("Kian");
        stackstring.push("Rahimi");
        stackstring.push("SMU");
        stackstring.push("Mustangs");
        stackstring.push("Kian Rahimi");

        REQUIRE(stackstring.size() == 5);
        stackstring.push("test");
        REQUIRE(stackstring.size() == 6);
    }

    SECTION("Empty") {
        REQUIRE(stacko.empty() == true);
        stacko.push(1);
        REQUIRE(stacko.empty() == false);

        REQUIRE(stackstring.empty() == true);
        stackstring.push("Kian");
        REQUIRE(stackstring.empty() == false);
    }

    SECTION("Pop") {
        stacko.push(1);
        stacko.push(2);
        stacko.push(3);
        stacko.push(4);
        stacko.push(5);

        stacko.pop();
        REQUIRE(stacko.size() == 4);
        stacko.pop();
        REQUIRE(stacko.size() == 3);
        stacko.pop();
        REQUIRE(stacko.size() == 2);
        stacko.pop();
        REQUIRE(stacko.size() == 1);
        stacko.pop();
        REQUIRE(stacko.size() == 0);


        stackstring.push("Kian");
        stackstring.push("Rahimi");
        stackstring.push("SMU");
        stackstring.push("Mustangs");
        stackstring.push("Kian Rahimi");


        stackstring.pop();
        REQUIRE(stackstring.size() == 4);
        stackstring.pop();
        REQUIRE(stackstring.size() == 3);
        stackstring.pop();
        REQUIRE(stackstring.size() == 2);
        stackstring.pop();
        REQUIRE(stackstring.size() == 1);
        stackstring.pop();
        REQUIRE(stackstring.size() == 0);
    }

    SECTION("Top") {
        stacko.push(1);
        REQUIRE(stacko.top() == 1);
        stacko.push(2);
        REQUIRE(stacko.top() == 2);
        stacko.push(3);
        REQUIRE(stacko.top() == 3);
        stacko.push(4);
        REQUIRE(stacko.top() == 4);
        stacko.push(5);
        REQUIRE(stacko.top() == 5);


        stackstring.push("Kian");
        REQUIRE(stackstring.top() == "Kian");
        stackstring.push("Rahimi");
        REQUIRE(stackstring.top() == "Rahimi");
        stackstring.push("SMU");
        REQUIRE(stackstring.top() == "SMU");
        stackstring.push("Mustangs");
        REQUIRE(stackstring.top() == "Mustangs");
        stackstring.push("Kian Rahimi");
        REQUIRE(stackstring.top() == "Kian Rahimi");
    }

    SECTION("Get List") {
        stacko.push(1);
        stacko.push(2);
        stacko.push(3);
        stacko.push(4);
        stacko.push(5);


        DSVector<int> tempo;
        REQUIRE(tempo.size() == 0);
        tempo = stacko.getList();
        REQUIRE(tempo.size() == 5);

        REQUIRE(tempo[0] == 1);
        REQUIRE(tempo[1] == 2);
        REQUIRE(tempo[2] == 3);
        REQUIRE(tempo[3] == 4);
        REQUIRE(tempo[4] == 5);


        stackstring.push("Kian");
        stackstring.push("Rahimi");
        stackstring.push("SMU");
        stackstring.push("Mustangs");
        stackstring.push("Kian Rahimi");

        DSVector<DSString> tempostring;
        REQUIRE(tempostring.size() == 0);
        tempostring = stackstring.getList();
        REQUIRE(tempostring.size() == 5);

        REQUIRE(tempostring[0] == "Kian");
        REQUIRE(tempostring[1] == "Rahimi");
        REQUIRE(tempostring[2] == "SMU");
        REQUIRE(tempostring[3] == "Mustangs");
        REQUIRE(tempostring[4] == "Kian Rahimi");
    }
}