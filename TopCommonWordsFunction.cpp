//
// Created by Tobin Joseph on 2019-04-25.
//
#include "TopCommonWords.h"
#include <iostream>
#include<random>
#include<cstdlib>
#include<algorithm>
#include <cctype>
#include <string>
#include <string.h>
#include <fstream>
#include <vector>
#include <map>
#include <set>
using namespace std;


string removeWhiteSpaces(string str) {
    int position;
    position = str.find_first_not_of(": ,.:;\"|\\!@#$%^&*()_+-=[]{}<>?/~`'");
    str.erase(0, position);

    position = str.find_last_not_of(": ,.:;\"|\\!@#$%^&*()_+-=[]{}<>?/~`'");
    if (string::npos != position)
        str.erase(position+1);
    return str;
}

void countWords(istream& is, strIntMap& words) {
    string str;

    while (is >> str) {
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        str = removeWhiteSpaces(str);
        //remove_if (str.begin(), str.end(), has_chars);


        if (!str.empty())   //str.at(0) != '\0' checking the first charecter of string in end of string char
            ++words[str];   //or use  str != ""
    }

}

void removeWords(strIntMap& words) {

    strIntMap::iterator iter;

    iter = words.find("a");
    if (iter != words.end()) {
        words.erase("a");
    }

    iter = words.find("an");
    if (iter != words.end()) {
        words.erase("an");
    }

    iter = words.find("and");
    if (iter != words.end()) {
        words.erase("and");
    }
    iter = words.find("in");
    if (iter != words.end()) {
        words.erase("in");
    }
    iter = words.find("is");
    if (iter != words.end()) {
        words.erase("is");
    }
    iter = words.find("it");
    if (iter != words.end()) {
        words.erase("it");
    }
    iter = words.find("the");
    if (iter != words.end()) {
        words.erase("the");
    }


}

void sortwordFrequencyVec(vector<strIntPair>& wordsAndCount) {
    for (int i=0; i < wordsAndCount.size()-1 ; i++) {

        strIntPair &current = wordsAndCount[i];

        for (int j=i+1; j< wordsAndCount.size(); j++ ) {

            strIntPair &next = wordsAndCount[j];
            strIntPair temp;

            if (current.second < next.second) {
                temp = next;
                next = current;
                current = temp;
                continue;

            }

            if (current.second == next.second) {
                if (strcmp (current.first.c_str() , next.first.c_str()) > 0 ) {
                    temp = next;
                    next = current;
                    current = temp;
                    continue;
                }

            }



        }

    }
}