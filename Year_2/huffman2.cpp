#include <iostream>
#include <vector>
#include <queue>

using namespace std;

long long calculateWPL(vector<int>& freqs) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int f : freqs) {
        pq.push(f);
    }

    long long totalWPL = 0;

    while (pq.size() > 1) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        
        int sum = a + b;
        totalWPL += sum; 
        pq.push(sum);
    }
    
    return totalWPL;
}

int main() {
    int n;
    cin >> n;
    vector<int> freqs(n);
    for (int i = 0; i < n; ++i) {
        cin >> freqs[i];
    }

    cout << calculateWPL(freqs) << endl;

    return 0;
}
