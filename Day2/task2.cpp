#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream inFile;
    inFile.open("input.txt");

    int horizontalPos = 0;
    int verticalPos = 0;
    int aim = 0;

    string currInput;
    int nextNumber;

    while (inFile >> currInput) {
        if(currInput.find("forward") != string::npos) {
            inFile >> nextNumber;
            horizontalPos += nextNumber;
            verticalPos += aim * nextNumber;
        } else if(currInput.find("down") != string::npos) {
            inFile >> nextNumber;
            aim += nextNumber;
        } else if(currInput.find("up") != string::npos) {
            inFile >> nextNumber;
            aim -= nextNumber;
        }
    }

    cout << horizontalPos * verticalPos;

    return 0;
}