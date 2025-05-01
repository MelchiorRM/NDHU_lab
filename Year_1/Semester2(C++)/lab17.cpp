#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class PalindromeSolver {
public:
    bool isPalindrome(unsigned long long num) {
        string s = to_string(num);
        string rev = s;
        reverse(rev.begin(), rev.end());
        return s == rev;
    }
    unsigned long long reverseNumber(unsigned long long num) {
        string s = to_string(num);
        reverse(s.begin(), s.end());
        return stoull(s);
    }
    pair<int, unsigned long long> reverseAndAdd(unsigned long long num) {
        int count = 0;
        while (count < 1000) {
            unsigned long long reversed = reverseNumber(num);
            num += reversed;
            count++;
            if (isPalindrome(num)) {
                break;
            }
        }
        return make_pair(count, num);
    }
};

int main() {
    int N;
    cin >> N;
    PalindromeSolver solver;
    while (N--) {
        unsigned long long num;
        cin >> num;
        pair<int, unsigned long long> result = solver.reverseAndAdd(num);
        cout << result.first << " " << result.second << endl;
    }
    return 0;
}
