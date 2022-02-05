#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <regex>
#include <numeric>

using namespace std;

void printVector(vector<int> values) {
    for(size_t i = 0; i < values.size(); i++) {
        cout << values.at(i) << " ";
    }
    cout << "\n";
}

vector<int> extractAllIntegersFromString(string str) {
    vector<int> out;
    
    string currNumber = "";

    for(size_t i = 0; i < str.size(); i++) {
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

int calculateExtraFuel(int n) {
    return (n == 1 || n == 0) ? 1 : calculateExtraFuel(n - 1) + n;
}

int median(vector<int> values) {
    sort(values.begin(), values.end());
    int medianPos = (int) ((values.size() / 2.0) - 1.0);
    return values.at(medianPos);
}

int main() {
    ifstream inFile;
    inFile.open("input.txt");

    string input;
    inFile >> input;
    vector<int> positions = extractAllIntegersFromString(input);

    int fuel = INT_MAX;

    int center = median(positions);

    bool bFuelGetsLess = true;

    while(bFuelGetsLess) {
        int currFuel = 0;
        for(size_t i = 0; i < positions.size(); i++) {
            currFuel += calculateExtraFuel(abs(positions.at(i) - center));
        }

        if(currFuel <= fuel) {
            fuel = currFuel;
            center++;
        } else {
            bFuelGetsLess = false;
        }
    }

    cout << fuel;

    return 0;
}