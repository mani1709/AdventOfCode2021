#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <regex>
#include <numeric>
#include <algorithm>

using namespace std;

enum Positions{
    topCenter,
    topRight,
    topLeft,
    middleCenter,
    bottomRight,
    bottomLeft,
    bottomCenter,
    notDefined
};

class Row{
    vector<string> numbers;
    vector<string> code;
    map<char, vector<Positions>> possibleChars;
    map<char, Positions> correctPosition;
public:
    Row(vector<string> numbers, vector<string> code): numbers{numbers}, code{code} {
        vector<Positions> allChars{topCenter, topRight, topLeft, middleCenter, bottomRight, bottomLeft, bottomCenter};
        possibleChars.insert({'a', allChars});
        possibleChars.insert({'b', allChars});
        possibleChars.insert({'c', allChars});
        possibleChars.insert({'d', allChars});
        possibleChars.insert({'e', allChars});
        possibleChars.insert({'f', allChars});
        possibleChars.insert({'g', allChars});

        correctPosition.insert({'a', notDefined});
        correctPosition.insert({'b', notDefined});
        correctPosition.insert({'c', notDefined});
        correctPosition.insert({'d', notDefined});
        correctPosition.insert({'e', notDefined});
        correctPosition.insert({'f', notDefined});
        correctPosition.insert({'g', notDefined});
    }

    void addOne() {
        string stringOne;
        for(int i = 0; i < numbers.size(); i++) {
            if(numbers.at(i).size() == 2) stringOne = numbers.at(i);
        }
        for(int i = 0; i < stringOne.size(); i++) {
            auto pos = possibleChars.find(stringOne.at(i));
            pos->second.erase(remove(pos->second.begin(), pos->second.end(), Positions::topCenter));
            pos->second.erase(remove(pos->second.begin(), pos->second.end(), Positions::topLeft));
            pos->second.erase(remove(pos->second.begin(), pos->second.end(), Positions::middleCenter));
            pos->second.erase(remove(pos->second.begin(), pos->second.end(), Positions::bottomLeft));
            pos->second.erase(remove(pos->second.begin(), pos->second.end(), Positions::bottomCenter));
        }
    }

    void addFour() {
        string stringOne;
        for(int i = 0; i < numbers.size(); i++) {
            if(numbers.at(i).size() == 4) stringOne = numbers.at(i);
        }
        for(int i = 0; i < stringOne.size(); i++) {
            auto pos = possibleChars.find(stringOne.at(i));
            pos->second.erase(remove(pos->second.begin(), pos->second.end(), Positions::topCenter));
            pos->second.erase(remove(pos->second.begin(), pos->second.end(), Positions::bottomLeft));
            pos->second.erase(remove(pos->second.begin(), pos->second.end(), Positions::bottomCenter));
        }
    }

    void addSeven() {
        string stringOne;
        for(int i = 0; i < numbers.size(); i++) {
            if(numbers.at(i).size() == 3) stringOne = numbers.at(i);
        }
        for(int i = 0; i < stringOne.size(); i++) {
            auto pos = possibleChars.find(stringOne.at(i));
            pos->second.erase(remove(pos->second.begin(), pos->second.end(), Positions::topLeft));
            pos->second.erase(remove(pos->second.begin(), pos->second.end(), Positions::middleCenter));
            pos->second.erase(remove(pos->second.begin(), pos->second.end(), Positions::bottomLeft));
            pos->second.erase(remove(pos->second.begin(), pos->second.end(), Positions::bottomCenter));
        }
    }

    friend ostream& operator<<(ostream& cout, const Row& line);
};

ostream& operator<<(ostream& cout, const Row& row) {
    cout << "RowNumbers: ";
    for(int i = 0; i < 10; i++) {
        cout << row.numbers.at(i) << " ";
    }
    cout << "RowCode: ";
    for(int i = 0; i < 4; i++) {
        cout << row.code.at(i) << " ";
    }
    cout << "possibleChars:";
    for(int i = 0; i < row.possibleChars.size(); i++) {
        cout << row.possibleChars.at(i).size();
    }
    return cout;
}

int main() {
    ifstream inFile;
    inFile.open("test.txt");

    vector<Row> rows;

    const int numberOfElements = 15;
    int currElement = 0;
    vector<string> rowNumbers;
    vector<string> rowCode;

    string nextString;
    while (inFile >> nextString) {
        currElement++;
        if(currElement < 11) {
            rowNumbers.push_back(nextString);
        } else if(currElement > 11) {
            rowCode.push_back(nextString);
            if(currElement == 15) {
                rows.push_back(Row{rowNumbers, rowCode});

                currElement = 0;
                rowNumbers.clear();
                rowCode.clear();
            }
        }
    }

cout << rows.size();

    for (size_t i = 0; i < rows.size(); i++) {
        rows.at(i).addOne();
        rows.at(i).addFour();
        rows.at(i).addSeven();
    }

    cout << rows.size();

    for (size_t i = 0; i < rows.size(); i++) {
        cout << rows.size();
        cout << rows.at(i);
    }

    return 0;
}