#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

// Class to represent a license plate
class LicensePlate {
private:
    string letters;
    int number;

public:
    LicensePlate(const string& plate) {
        letters = plate.substr(0, 3);
        number = stoi(plate.substr(4, 4)); // skip the hyphen
    }

    // Convert the first part (letters) into a base-26 value
    int getLetterValue() const {
        int value = 0;
        value += (letters[0] - 'A') * 26 * 26;
        value += (letters[1] - 'A') * 26;
        value += (letters[2] - 'A');
        return value;
    }

    // Determine if the plate is "nice"
    bool isNice() const {
        int diff = abs(getLetterValue() - number);
        return diff <= 100;
    }
};

// Class to process multiple license plates
class LicenseChecker {
private:
    vector<LicensePlate> plates;

public:
    void readInput() {
        int n;
        cin >> n;
        string plate;
        for (int i = 0; i < n; ++i) {
            cin >> plate;
            plates.push_back(LicensePlate(plate));
        }
    }

    void printResults() const {
        for (const auto& plate : plates) {
            cout << (plate.isNice() ? "nice" : "not nice") << endl;
        }
    }
};

int main() {
    LicenseChecker checker;
    checker.readInput();
    checker.printResults();
    return 0;
}
