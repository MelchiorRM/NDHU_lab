#include <stdio.h>
int main() {
    int n, input;
    while (1) {
        scanf("%d", &n);
        if (n == 0) {
            break;
        }
        if (n <= 1000) {
            input = n;
            printf("%d = ", input);
            if (n <= 1) {
                printf("%d", n);
            } else {
                while (n % 2 == 0) {
                    printf("2");
                    n /= 2;
                    if (n > 1) {
                        printf(" * ");
                    }
                }
                for (int i = 3; i * i <= n; i += 2) {
                    while (n % i == 0) {
                        printf("%d", i);
                        n /= i;
                        if (n > 1) {
                            printf(" * ");
                        }
                    }
                }
                if (n > 1) {
                    printf("%d", n);
                }
            }
            printf("\n");
        }
    }
    return 0;
}