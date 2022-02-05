#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <regex>

using namespace std;

class Node {
public:
    int val;
    bool marked = false;

    Node(int val): val(val){}
};

class BingoField {
public:
    vector<vector<Node>> field;
    bool bingoFieldFinished = false;

    BingoField(vector<vector<Node>> field): field(field) {}

    bool tryNewNumber(int number, int& score) {
        for(int i = 0; i < field.size(); i++) {
            for(int j = 0; j < field.at(i).size(); j++) {
                if(number == field.at(i).at(j).val) {
                    field.at(i).at(j).marked = true;
                }
            }
        }
        
        bool finished = false;

        for(int i = 0; i < field.size(); i++) {
            if(field.at(i).at(0).marked && field.at(i).at(1).marked && field.at(i).at(2).marked && field.at(i).at(3).marked && field.at(i).at(4).marked) {
                finished = true;
            }
            if(field.at(0).at(i).marked && field.at(1).at(i).marked && field.at(2).at(i).marked && field.at(3).at(i).marked && field.at(4).at(i).marked) {
                finished = true;
            }
        }

        bingoFieldFinished = finished;

        if(finished == true) {
            int sumUnmarked = 0;

            for(int i = 0; i < field.size(); i++) {
                for(int j = 0; j < field.at(i).size(); j++) {
                    if(field.at(i).at(j).marked == false) {
                        sumUnmarked += field.at(i).at(j).val;
                    }
                }
            }

            score = number * sumUnmarked;
        }

        return finished;
    }

    friend ostream& operator<<(ostream& cout, const BingoField &b ) {
        for(int i = 0; i < b.field.size(); i++) {
            for(int j = 0; j < b.field.at(i).size(); j++) {
                cout << b.field.at(i).at(j).val;
                if(b.field.at(i).at(j).marked == true) {
                    cout << "t ";
                } else {
                    cout << "f ";
                }
            }
            cout << endl;
        }
        return cout;
    }
};

int main() {
    ifstream inFile;
    inFile.open("input.txt");

    vector<string> textLines;

    string nextString;
    inFile >> nextString;

    // from https://www.softwaretestinghelp.com/regex-in-cpp/
    vector<int> bingoNumbers;

    while(nextString.size() > 0) {
        //find number
        regex str_expr ("[0-9]+");
        smatch m;
        regex_search(nextString, m, str_expr); 

        //add it
        bingoNumbers.push_back(stoi(m.str()));

        //delete number and comma
        nextString.erase(0,m.str().size()+1);
    }

    static int bingoBoardsCount = 100;
    int currBoardCount = 0;
    vector<BingoField> bingoFields;

    while(currBoardCount < bingoBoardsCount) {
        vector<vector<Node>> board;
        for(int i = 0; i < 5; i++) {
            vector<Node> row;
            for(int j = 0; j < 5; j++) {
                inFile >> nextString;
                Node node = Node(stoi(nextString));
                row.push_back(node);
            }
            board.push_back(row);
        }
        currBoardCount++;
        bingoFields.push_back(BingoField(board));
    }

    int out = 0;

    int bingoFieldsFinishedCount = 0;

    for(int i = 0; i < bingoNumbers.size(); i++) {
        for(int j = 0; j < bingoFields.size(); j++) {
            if(bingoFields.at(j).bingoFieldFinished == false) {
                int score = 0;
                bool finished = bingoFields.at(j).tryNewNumber(bingoNumbers.at(i), score);
                if(finished) {
                    bingoFieldsFinishedCount++;
                    out = score;
                }
            }
        }
    }

    cout << out;

    return 0;
}