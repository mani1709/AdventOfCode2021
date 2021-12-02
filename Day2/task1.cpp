#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream inFile;
    inFile.open("C:\\Users\\User\\OneDrive\\Desktop\\AdventOfCode\\Day2\\input.txt");

    int horizontalPos = 0;
    int verticalPos = 0;

    string currInput;
    int nextNumber;

    while (inFile >> currInput) {
        if(currInput.find("forward") != string::npos) {
            inFile >> nextNumber;
            horizontalPos += nextNumber;
        } else if(currInput.find("down") != string::npos) {
            inFile >> nextNumber;
            verticalPos += nextNumber;
        } else if(currInput.find("up") != string::npos) {
            inFile >> nextNumber;
            verticalPos -= nextNumber;
        }
    }

    cout << horizontalPos * verticalPos;

    return 0;
}