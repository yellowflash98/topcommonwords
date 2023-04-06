//
// Created by Tobin Joseph on 2019-04-14.
//


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
#include "TopCommonWords.h"


using namespace std;


typedef map<string, int> strIntMap;
typedef pair<string,int> strIntPair;
//typedef set<string> strSet;
using namespace std;

int main(int argc, char** argv) {
    if (argc < 2)
        return(-1);

    ifstream shakeItOffFile(argv[1]);


    if (!shakeItOffFile)
        return(-2);;

    strIntMap wordFrequencyMap;
    countWords(shakeItOffFile, wordFrequencyMap);
    removeWords(wordFrequencyMap);


    // create a empty vector of pairs
    vector<strIntPair> wordFrequencyVec;

    // copy key-value pairs from the map to the vector
    copy(wordFrequencyMap.begin(),
         wordFrequencyMap.end(),
         back_inserter<vector<strIntPair> >(wordFrequencyVec));
    //wordFrequencyMap.clear();
    // sort the vector by increasing order of its pair's second value
    // if second value are equal, order by the pair's first value
    sortwordFrequencyVec(wordFrequencyVec);

    // print the vector
    string prevPairFirst = "";
    int prevPairSecond = -1;
    string commaSpace = ", ";
    int uniqueFreqCounter = 0;

    int topN = 10;
    if (argc >= 3 )
        topN = stoi(argv[2]);

    for (int i=0; i < wordFrequencyVec.size(); i++) {
        strIntPair &current = wordFrequencyVec[i];

        if (current.second == prevPairSecond) {
            if (prevPairFirst == "" ) {
                prevPairFirst = current.first;
            }
            else {
                prevPairFirst = prevPairFirst + commaSpace + current.first;
            }

        }
        else {
            if (prevPairSecond != -1) {
                uniqueFreqCounter = uniqueFreqCounter + 1;
                if  (uniqueFreqCounter <= topN)
                    cout << uniqueFreqCounter << ".)  These words appeared " << prevPairSecond << " times: {" << prevPairFirst << '}' << endl;
            }

            prevPairSecond = current.second;
            prevPairFirst = current.first;

        }
        if (i == wordFrequencyVec.size() - 1 ){
            uniqueFreqCounter = uniqueFreqCounter + 1;
            if  (uniqueFreqCounter <= topN)
                cout << uniqueFreqCounter << ".)  These words appeared " << prevPairSecond << " times: {" << prevPairFirst << '}' << endl;
        }
    }
}



