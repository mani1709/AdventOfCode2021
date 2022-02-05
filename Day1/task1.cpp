#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream inFile;
    inFile.open("input.txt");

    int currNumber = 0;
    int nextNumber = 0;
    int timesIncreased = 0;

    inFile >> currNumber;

    while (inFile >> nextNumber) {
        if(nextNumber > currNumber) {
            timesIncreased++;
        }
        currNumber = nextNumber;
    }

    cout << timesIncreased;

    return 0;
}