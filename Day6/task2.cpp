#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <regex>

using namespace std;

vector<int> extractAllIntegersFromString(string str) {
    vector<int> out;
    
    string currNumber = "";

    for(int i = 0; i < str.size(); i++) {
        string currChar = string{str.at(i)};
        if(regex_match(currChar, regex("[0-9]+"))){
            currNumber += str.at(i);
        }
        if(currNumber.size() != 0) {
            out.push_back(stoi(currNumber));
            currNumber = "";
        }
    }

    return out;
}

int main() {
    ifstream inFile;
    inFile.open("input.txt");

    map<int, uint64_t> populationAtSpecificTime{{0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}, {7, 0}, {8, 0}};

    string fishes;
    inFile >> fishes;
    vector<int> ages = extractAllIntegersFromString(fishes);

    for(int i = 0; i < ages.size(); i++) {
        populationAtSpecificTime.find(ages.at(i))->second++;
    }

    int currDay = 0;
    const int maxDays = 256;

    while (currDay < maxDays) {
        uint64_t toAdd = populationAtSpecificTime.find(0)->second;

        for(auto it = populationAtSpecificTime.begin(); it != populationAtSpecificTime.end(); ++it) {
            if(it->first == 0) it->second = populationAtSpecificTime.find(1)->second;
            if(it->first == 1) it->second = populationAtSpecificTime.find(2)->second;
            if(it->first == 2) it->second = populationAtSpecificTime.find(3)->second;
            if(it->first == 3) it->second = populationAtSpecificTime.find(4)->second;
            if(it->first == 4) it->second = populationAtSpecificTime.find(5)->second;
            if(it->first == 5) it->second = populationAtSpecificTime.find(6)->second;
            if(it->first == 6) it->second = populationAtSpecificTime.find(7)->second + toAdd;
            if(it->first == 7) it->second = populationAtSpecificTime.find(8)->second;
            if(it->first == 8) it->second = toAdd;
        }
        currDay++;
    }

    uint64_t amountFishes = 0;

    for(auto it = populationAtSpecificTime.begin(); it != populationAtSpecificTime.end(); ++it) {
        cout << it->first << " " << it->second << "\n";
        amountFishes += it->second;
    }

    cout << "There are " << amountFishes << " Fishes.";
    

    return 0;
}