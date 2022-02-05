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

    vector<vector<int>> numberStrings;

    string nextString;
    while (inFile >> nextString) {
        numberStrings.push_back(nextString);
    }

    return 0;
}