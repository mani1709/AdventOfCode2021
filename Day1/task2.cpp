#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream inFile;
    inFile.open("C:\\Users\\User\\OneDrive\\Desktop\\AdventOfCode\\Day1\\input.txt");

    int prevNumber = 0;
    int currNumber = 0;
    int nextNumber = 0;
    int combinedNumber = INT_MAX;
    int timesIncreased = 0;

    inFile >> prevNumber;
    inFile >> currNumber;

    while (inFile >> nextNumber) {
        if(prevNumber + currNumber + nextNumber > combinedNumber) {
            timesIncreased++;
        }
        combinedNumber = prevNumber + currNumber + nextNumber;
        prevNumber = currNumber;
        currNumber = nextNumber;
    }

    cout << timesIncreased;

    return 0;
}