#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <regex>

using namespace std;

class Lanternfish {
    int daysUntilNewFish = 0;
public:
    Lanternfish(int daysUntilNewFish): daysUntilNewFish{daysUntilNewFish} {}

    int getDaysUntilNewFish() {
        return daysUntilNewFish;
    }

    void startNextDay(vector<Lanternfish> &lanternFishes) {
        daysUntilNewFish--;
        if (daysUntilNewFish < 0) {
            daysUntilNewFish = 6;
            lanternFishes.push_back(Lanternfish{8});
        }
    }
};

vector<int> extractAllIntegersFromString(string str) {
    vector<int> out;
    
    string currNumber = "";

    for(int i = 0; i < str.size(); i++) {
        string currChar = string{str.at(i)};
        if(regex_match(currChar, regex("[0-9]+"))){
            currNumber += str.at(i);
        }
        if(currNumber.size() != 0) {
            out.push_back(stoi(currNumber));
            currNumber = "";
        }
    }

    return out;
}

int main() {
    ifstream inFile;
    inFile.open("input.txt");

    vector<Lanternfish> lanternFishes;

    string fishes;
    inFile >> fishes;
    vector<int> ages = extractAllIntegersFromString(fishes);

    for(int i = 0; i < ages.size(); i++) {
        lanternFishes.push_back(Lanternfish{ages.at(i)});
    }

    int day = 0;
    const int maxDays = 80;

    while (day++ < maxDays) {
        int lanternfishesAtBegin = lanternFishes.size();
        for(int i = 0; i < lanternfishesAtBegin; i++) {
            lanternFishes.at(i).startNextDay(lanternFishes);
        }
    }

    cout << "There are " << lanternFishes.size() << " Fishes.";
    

    return 0;
}