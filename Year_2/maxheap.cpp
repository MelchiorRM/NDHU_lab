#include <iostream>
#include <vector>

using namespace std;

vector<int> heap;

void siftUp(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[index] > heap[parent]) {
            swap(heap[index], heap[parent]);
            index = parent;
        } else {
            break;
        }
    }
}

void push(int val) {
    heap.push_back(val);
    siftUp(heap.size() - 1);
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        push(val);
    }

    for (int i = 0; i < heap.size(); ++i) {
        cout << heap[i] << " ";
    }
    cout << endl;

    return 0;
}
