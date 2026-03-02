#include <iostream>
using namespace std;

void findChildren(int index, int size, int& left, int& right) {
    left = index * 2 + 1;
    right = index * 2 + 2;

    if (left >= size) {
        left = -1;
    }
    if (right >= size) {
        right = -1;
    }
}

int main() {
    int size = 10;
    int indices[] = {2, 3, 4};
    for (int index : indices) {
        int left, right;
        findChildren(index, size, left, right);
        cout << left << " " << right << endl;
    }
    
    return 0;
}
