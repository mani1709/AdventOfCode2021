#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <regex>
#include <numeric>

using namespace std;

vector<int> extractAllIntegersFromString(string str) {
    vector<int> out;
    
    string currNumber = "";

    for(int i = 0; i < str.size(); i++) {
        string currChar = string{str.at(i)};
        if(regex_match(currChar, regex("[0-9]+"))){
            currNumber += str.at(i);
        } else {
            if(currNumber.size() != 0) {
                out.push_back(stoi(currNumber));
                currNumber = "";
            }
        }
    }

    if(currNumber.size() != 0) {
        out.push_back(stoi(currNumber));
        currNumber = "";
    }

    return out;
}

int main() {
    ifstream inFile;
    inFile.open("input.txt");

    string input;
    inFile >> input;
    vector<int> positions = extractAllIntegersFromString(input);

    int fuel = INT_MAX;

    int center = 0;
    
    bool bFuelGetsLess = true;

    while(bFuelGetsLess) {
        int currFuel = 0;
        for(int i = 0; i < positions.size(); i++) {
            currFuel += abs(positions.at(i) - center);
        }
        if(currFuel < fuel) {
            fuel = currFuel;
            center++;
        } else {
            bFuelGetsLess = false;
        }
    }

    cout << fuel;

    return 0;
}