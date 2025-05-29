#include <iostream>
#include <string>
#include <vector>
#include <bitset>

using namespace std;

// Class to compute and display binary parity
class BinaryParity {
private:
    int number;
    string binary;
    int parity;

public:
    BinaryParity(int num) : number(num) {
        binary = toBinary(num);
        parity = countOnes(binary);
    }

    // Convert to binary string (without leading 0s)
    string toBinary(int n) {
        string result = "";
        while (n > 0) {
            result = (n % 2 == 0 ? "0" : "1") + result;
            n /= 2;
        }
        return result.empty() ? "0" : result;
    }

    // Count the number of 1s in binary string
    int countOnes(const string& bin) {
        int count = 0;
        for (char c : bin) {
            if (c == '1') ++count;
        }
        return count;
    }

    // Output formatted result
    void printResult() const {
        cout << "The parity of " << binary << " is " << parity << " (mod 2)." << endl;
    }
};

int main() {
    int n;
    while (cin >> n && n != 0) {
        BinaryParity bp(n);
        bp.printResult();
    }
    return 0;
}
