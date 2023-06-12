
#include "catch.h"

#include <cstring>
#include "DSString.h"
#include "DSVector.h"


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


