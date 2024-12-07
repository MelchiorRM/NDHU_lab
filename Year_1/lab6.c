#include <stdio.h>
int main(){
    int number, number_reverse=0;
     while (1) {
        scanf("%d",  &number);
        if (number >= 1000 && number <= 9999) {
            break; 
        }
     }
    while (number > 0) {
        number_reverse = number_reverse * 10 + number % 10;
        number /= 10;
    }
    printf("%04d",  number_reverse);
    return 0;
}