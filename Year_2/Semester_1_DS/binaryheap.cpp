#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class MaxHeap {
private:
    vector<int> heap;

    // ========== SIFT UP ==========
    void siftUp(int idx) {
        while (idx > 0) {
            int parent = (idx - 1) / 2;
            if (heap[idx] <= heap[parent]) break;
            swap(heap[idx], heap[parent]);
            idx = parent;
        }
    }

    // ========== SIFT DOWN ==========
    void siftDown(int idx) {
        int n = heap.size();
        while (2 * idx + 1 < n) {
            int left = 2 * idx + 1;
            int right = 2 * idx + 2;
            int largest = left;

            if (right < n && heap[right] > heap[left])
                largest = right;

            if (heap[idx] >= heap[largest]) break;

            swap(heap[idx], heap[largest]);
            idx = largest;
        }
    }

public:
    // ========== INSERT ==========
    void push(int val) {
        heap.push_back(val);
        siftUp(heap.size() - 1);
    }

    // ========== GET MAX ==========
    int top() {
        if (heap.empty()) 
            throw runtime_error("Heap is empty!");
        return heap[0];
    }

    // ========== REMOVE MAX ==========
    void pop() {
        if (heap.empty()) return;
        swap(heap[0], heap.back());
        heap.pop_back();
        if (!heap.empty()) siftDown(0);
    }

    // ========== BUILD HEAP FROM ARRAY ==========
    void buildHeap(const vector<int>& arr) {
        heap = arr;
        for (int i = heap.size() / 2 - 1; i >= 0; i--)
            siftDown(i);
    }

    // ========== SIZE & EMPTY ==========
    bool empty() { return heap.empty(); }
    int size() { return heap.size(); }

    // ========== PRINT THE HEAP ARRAY ==========
    void printHeap() {
        cout << "Heap Array: ";
        for (int x : heap) cout << x << " ";
        cout << "\n";
    }
};



// ==========================================================
// ========================= MAIN ============================
// ==========================================================

int main() {
    MaxHeap h;

    cout << "=== Testing Push ===\n";
    h.push(10);
    h.push(40);
    h.push(20);
    h.push(60);
    h.push(15);

    h.printHeap();
    cout << "Top element (max): " << h.top() << "\n\n";

    cout << "=== Testing Pop ===\n";
    h.pop();
    h.printHeap();
    cout << "Top element: " << h.top() << "\n\n";

    cout << "=== Testing buildHeap() ===\n";
    vector<int> arr = {3, 8, 1, 10, 6, 5};
    h.buildHeap(arr);

    h.printHeap();
    cout << "Top element: " << h.top() << "\n\n";

    cout << "=== Removing all elements ===\n";
    while (!h.empty()) {
        cout << "Pop: " << h.top() << "\n";
        h.pop();
    }

    return 0;
}
