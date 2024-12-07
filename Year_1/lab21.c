#include <stdio.h>
char *roman_arr[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
int roman_val[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
void roman(int value) {
    for (int i = 0; i < 13; i++) {
        while (value >= roman_val[i]) {
            printf("%s", roman_arr[i]);
            value -= roman_val[i];
        }
    }
    printf("\n");
}
int main() {
    int num;
    scanf("%d", &num);
    roman(num);
    return 0;
}