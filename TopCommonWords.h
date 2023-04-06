//
// Created by Tobin Joseph on 2019-04-14.
//

#ifndef TOPCOMMONWORDS_TOPCOMMONWORDS_H
#define TOPCOMMONWORDS_TOPCOMMONWORDS_H


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
typedef map<string, int> strIntMap;
typedef pair<string,int> strIntPair;

string removeWhiteSpaces(string str);
void countWords(istream& is, strIntMap& words);
void removeWords(strIntMap& words);
void sortwordFrequencyVec(vector<strIntPair>& wordsAndCount);


#endif //TOPCOMMONWORDS_TOPCOMMONWORDS_H
