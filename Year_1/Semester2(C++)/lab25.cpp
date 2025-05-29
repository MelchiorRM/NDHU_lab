#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Class to represent a DNA string and its sortedness (inversion count)
class DNAString {
public:
    string sequence;
    int inversionCount;
    int originalIndex;

    DNAString(string seq, int idx) {
        sequence = seq;
        originalIndex = idx;
        inversionCount = countInversions();
    }

    // count inversions in the sequence
    int countInversions() {
        int inv = 0;
        for (size_t i = 0; i < sequence.size(); ++i) {
            for (size_t j = i + 1; j < sequence.size(); ++j) {
                if (sequence[i] > sequence[j]) {
                    ++inv;
                }
            }
        }
        return inv;
    }

    // Comparator : first by inversion count, then by original index
    bool operator<(const DNAString& other) const {
        if (inversionCount != other.inversionCount)
            return inversionCount < other.inversionCount;
        return originalIndex < other.originalIndex;
    }
};

// Class to hold a dataset of DNA strings
class Dataset {
public:
    int n, m;
    vector<DNAString> dnaStrings;

    Dataset(int len, int count) : n(len), m(count) {}

    void addDNAString(const string& seq, int idx) {
        dnaStrings.push_back(DNAString(seq, idx));
    }

    void sortBySortedness() {
        stable_sort(dnaStrings.begin(), dnaStrings.end());
    }

    void print() {
        for (const auto& dna : dnaStrings) {
            cout << dna.sequence << endl;
        }
    }
};

int main() {
    int M;
    cin >> M;
    string d;
    getline(cin, d);
    getline(cin, d);

    for (int datasetNum = 0; datasetNum < M; ++datasetNum) {
        int n, m;
        cin >> n >> m;
        getline(cin, d);

        Dataset dataset(n, m);

        for (int i = 0; i < m; ++i) {
            string seq;
            getline(cin, seq);
            dataset.addDNAString(seq, i);
        }

        dataset.sortBySortedness();
        dataset.print();

        if (datasetNum != M - 1) {
            cout << endl;
            getline(cin, d); // skip blank line
        }
    }

    return 0;
}
