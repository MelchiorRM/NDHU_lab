#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

const int MAX = 1000000;

// prime checking and classification
class EmirpChecker {
private:
    vector<bool> isPrimeSieve;

    // Sieve of Eratosthenes to precompute prime status
    void generatePrimes() {
        isPrimeSieve.assign(MAX + 1, true);
        isPrimeSieve[0] = isPrimeSieve[1] = false;

        for (int i = 2; i * i <= MAX; ++i) {
            if (isPrimeSieve[i]) {
                for (int j = i * i; j <= MAX; j += i) {
                    isPrimeSieve[j] = false;
                }
            }
        }
    }

    int reverseNumber(int n) {
        int reversed = 0;
        while (n > 0) {
            reversed = reversed * 10 + (n % 10);
            n /= 10;
        }
        return reversed;
    }

public:
    EmirpChecker() {
        generatePrimes();
    }

    // number is prime using the sieve
    bool isPrime(int n) {
        return isPrimeSieve[n];
    }

    string classify(int n) {
        if (!isPrime(n)) {
            return to_string(n) + " is not prime.";
        }

        int reversed = reverseNumber(n);
        if (reversed != n && isPrime(reversed)) {
            return to_string(n) + " is emirp.";
        } else {
            return to_string(n) + " is prime.";
        }
    }
};

int main() {
    EmirpChecker checker;
    string line;
    while (getline(cin, line)) {
        if (line.empty()) continue;
        int n;
        stringstream ss(line);
        ss >> n;
        cout << checker.classify(n) << endl;
    }
    return 0;
}
