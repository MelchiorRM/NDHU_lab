#include <stdio.h>
int main(){
    int a,b,c;
    float sum,average;
    scanf("%d ", &a);
    scanf("%d ", &b);
    scanf("%d ", &c);
    sum = a+b+c;
    average = sum/3;
    printf("%f", average);
    return 0;
}