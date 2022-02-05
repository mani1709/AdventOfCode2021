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

    string oxygenGeneratorRatingString;
    string coTwoScrubberRatingString;

    vector<string> filtered = textLines;
    for(int i = 0; i < stringLength; i++) {
        int amountZeros = 0;
        int amountOnes = 0;

        for(int j = 0; j < filtered.size(); j++) {
            filtered.at(j)[i] == '0' ? amountZeros++ : amountOnes++;
        }
        
        if(amountZeros > amountOnes) {
            for(int j = 0; j < filtered.size(); j++) {
                if(filtered.at(j)[i] == '1') {
                    filtered.erase(filtered.begin()+j);
                    j--;
                }
            }
        } else {
            for(int j = 0; j < filtered.size(); j++) {
                if(filtered.at(j)[i] == '0') {
                    filtered.erase(filtered.begin()+j);
                    j--;
                }
            }
        }
        
        if(filtered.size() == 1) {
            oxygenGeneratorRatingString = filtered.at(0);
            break;
        }
    }

    filtered = textLines;
    for(int i = 0; i < stringLength; i++) {
        int amountZeros = 0;
        int amountOnes = 0;

        for(int j = 0; j < filtered.size(); j++) {
            filtered.at(j)[i] == '0' ? amountZeros++ : amountOnes++;
        }
        
        if(amountZeros > amountOnes) {
            for(int j = 0; j < filtered.size(); j++) {
                if(filtered.at(j)[i] == '0') {
                    filtered.erase(filtered.begin()+j);
                    j--;
                }
            }
        } else {
            for(int j = 0; j < filtered.size(); j++) {
                if(filtered.at(j)[i] == '1') {
                    filtered.erase(filtered.begin()+j);
                    j--;
                }
            }
        }

        if(filtered.size() == 1) {
            coTwoScrubberRatingString = filtered.at(0);
            break;
        }
    }

    cout << oxygenGeneratorRatingString << " " << coTwoScrubberRatingString << endl;

    int oxygenGeneratorRating = 0;
    int coTwoScrubberRating = 0;

    for(int i = 0; i < stringLength; i++) {
        oxygenGeneratorRating += ((int) oxygenGeneratorRatingString[i] - 48) * pow(2, stringLength-1-i);
        coTwoScrubberRating += ((int) coTwoScrubberRatingString[i] - 48) * pow(2, stringLength-1-i);
    }

    cout << oxygenGeneratorRating << " " << coTwoScrubberRating << endl;

    cout << "Life support rating: " << oxygenGeneratorRating * coTwoScrubberRating;

    return 0;
}