#include <stdio.h>
int bubbleSort(int arr[], int n) {
    int swaps = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps++;
            }
        }
    }
    return swaps;
}
int main() {
    int testCases;
    scanf("%d", &testCases);
    while (testCases--) {
        int L;
        scanf("%d", &L);
        int train[L];
        for (int i = 0; i < L; i++) {
            scanf("%d", &train[i]);
        }
        int swapCount = bubbleSort(train, L);
        printf("Optimal train swapping takes %d swaps.\n", swapCount);
    }
    return 0;
}
