#include <stdio.h>
int main(){
    int a,b,c,i;
    scanf("%d %d", &a,  &b);
    if(a>b){
        c=a;
        a=b;
        b=c;
    }
    i=a;
    while (i<b){
        if((i%3==2)&&(i%7==5)&&(i%11==7))
        {
            printf("%d " ,i);

        }
        i++;
    }
    return 0;
}