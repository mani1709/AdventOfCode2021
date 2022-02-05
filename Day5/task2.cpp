#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Line{
    int x1;
    int y1;
    int x2;
    int y2;
public:
    Line(int x1, int y1, int x2, int y2): x1{x1}, y1{y1}, x2{x2}, y2{y2} {}

    int getMaxX() {
        return x1 > x2 ? x1 : x2;
    }

    int getMaxY() {
        return y1 > y2 ? y1 : y2;
    }

    bool isStraightLine() {
        return (x1 == x2 || y1 == y2);
    }

    bool isDiagonalLine() {
        return (abs(x1 - x2) - abs(y1 - y2)) == 0;
    }

    void addLineToMapStraight(vector<vector<int>> &ventMap) {
        int currX = x1;
        int currY = y1;

        do {
            ventMap.at(currY).at(currX)++;

            if(currX < x2) {
                currX++;
            } else if(currX > x2) {
                currX--;
            }

            if(currY < y2) {
                currY++;
            } else if(currY > y2) {
                currY--;
            }
        } while(!((currX == x2) && (currY == y2)));

        ventMap.at(currY).at(currX)++;
    }

    void addLineToMapDiagonal(vector<vector<int>> &ventMap) {
        int currX = x1;
        int currY = y1;

        do {
            ventMap.at(currY).at(currX)++;

            if(currX < x2) {
                currX++;
            } else if(currX > x2) {
                currX--;
            }

            if(currY < y2) {
                currY++;
            } else if(currY > y2) {
                currY--;
            }
        } while(!((currX == x2) && (currY == y2)));
        
        ventMap.at(currY).at(currX)++;
    }

    friend ostream& operator<<(ostream& cout, const Line& line);
};

ostream& operator<<(ostream& cout, const Line& line) {
    cout << "Start: " << line.x1 << " " << line.y1 << ", End: " << line.x2 << " " << line.y2 << "\n";
    return cout;
}

int main() {
    ifstream inFile;
    inFile.open("input.txt");

    vector<Line> lines;

    string a, b;
    string unused;

    while (inFile >> a >> unused >> b) {
        int x1 = stoi(a.substr(0, a.find(',')));
        int y1 = stoi(a.substr(a.find(',')+1));
        int x2 = stoi(b.substr(0, b.find(',')));
        int y2 = stoi(b.substr(b.find(',')+1));
        lines.push_back(Line{x1, y1, x2, y2});
    }

    int maxX = 0;
    int maxY = 0;

    for(auto it = begin(lines); it != end(lines); ++it) {
        int currMaxX = it->getMaxX();
        int currMaxY = it->getMaxY();
        if(currMaxX > maxX) maxX = currMaxX;
        if(currMaxY > maxY) maxY = currMaxY;
    }

    vector<vector<int>> ventMap;

    for(int y = 0; y < maxY+1; y++) {
        vector<int> row;
        for(int x = 0; x < maxX+1; x++) {
            row.push_back(0);
        }
        ventMap.push_back(row);
    }

    for(auto it = begin(lines); it != end(lines); ++it) {
        if(it->isStraightLine()) it->addLineToMapStraight(ventMap);
        if(it->isDiagonalLine()) it->addLineToMapDiagonal(ventMap);
    }

    int numberOfValuesGreaterTwo = 0;

    for(int y = 0; y < ventMap.size(); y++) {
        for(int x = 0; x < ventMap.at(y).size(); x++) {
            if(ventMap.at(y).at(x) > 1) numberOfValuesGreaterTwo++;
        }
    }

    cout << numberOfValuesGreaterTwo;

    return 0;
}