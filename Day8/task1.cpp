#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <regex>
#include <numeric>

using namespace std;

int main() {
    ifstream inFile;
    inFile.open("input.txt");

    vector<string> numberStrings;

    string nextString;
    while (inFile >> nextString) {
        numberStrings.push_back(nextString);
    }

    const int numberOfElements = 15;

    int amountOnesFoursSevenEights = 0;

    vector<string> decodedValues;
    string decodedValue;

    for(int i = 0; i < numberStrings.size(); i++) {
        int currElement = i % numberOfElements;
        if(currElement > 10) {
            string currString = numberStrings.at(i);
            if(currString.size() == 2) {
                amountOnesFoursSevenEights++;
            } else if(currString.size() == 3) {
                amountOnesFoursSevenEights++;
            } else if(currString.size() == 4) {
                amountOnesFoursSevenEights++;
            } else if(currString.size() == 5) {
                //2, 3, 5
            } else if(currString.size() == 6) {
                //0, 6, 9
            } else if(currString.size() == 7) {
                amountOnesFoursSevenEights++;
            }
        } else {
            decodedValue += '|';
        }
        if(currElement == 14) {
            decodedValues.push_back(decodedValue);
            decodedValue = "";
        }
    }

    cout << amountOnesFoursSevenEights;

    return 0;
}