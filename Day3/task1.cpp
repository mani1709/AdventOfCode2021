#include <iostream>
#include <fstream>
#include <vector>
#include <math.h> 
#include <string>

using namespace std;

int main() {
    ifstream inFile;
    inFile.open("input.txt");

    vector<string> textLines;

    string nextString;
    while (inFile >> nextString) {
        textLines.push_back(nextString);
    }

    int stringLength = textLines[0].size();

    string gammaRateString;
    string epsilonRateString;

    for(int i = 0; i < stringLength; i++) {
        int amountBitZero = 0;
        int amountBitOne = 0;
        for(int j = 0; j < textLines.size(); j++) {
            if(textLines[j][i] == '0') {
                amountBitZero++;
            } else {
                amountBitOne++;
            }
        }

        cout << amountBitZero << " " << amountBitOne << endl;

        if(amountBitZero < amountBitOne) {
            gammaRateString += "0";
            epsilonRateString += "1";
        } else {
            gammaRateString += "1";
            epsilonRateString += "0";
        }
    }

    int gammaRate = 0;
    int epsilonRate = 0;

    for(int i = 0; i < stringLength; i++) {
        gammaRate += ((int) gammaRateString[i] - 48) * pow(2, stringLength-1-i);
        epsilonRate += ((int) epsilonRateString[i] - 48) * pow(2, stringLength-1-i);
    }

    cout << "Power consumption: " << gammaRate * epsilonRate;

    return 0;
}