#include <stdio.h>
int cycle(int a) {
    int count = 1;
    while (a != 1) {
        if (a % 2 == 0) {
            a = a / 2;
        } else {
            a = 3 * a + 1;
        }
        count++;
    }
    return count;
}
int main() {
    int a, b, c, maxl;
    while (scanf("%d %d", &a, &b) == 2) {
        maxl = 0; 
        int start = (a < b) ? a : b;
        int end = (a > b) ? a : b;
        for (int i = start; i <= end; i++) {
            c = cycle(i);
            if (c > maxl) {
                maxl = c;
            }
        }
        printf("%d %d %d\n", a, b, maxl);
    }
    return 0;
}