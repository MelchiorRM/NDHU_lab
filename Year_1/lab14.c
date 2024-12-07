#include<stdio.h>
int prime(int n){
    if(n<2){
        return 0;
    }
    else{
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                return  0;

            }
        }
        return 1;
    }
}
int main(){
    int n,count;
    while(1){
        scanf("%d",&n);
        if(n>=10 &&  n<=32766){
            break;
        }
    }
    count=0;
    for(int i=2;i<=n/2;i++){
        if(prime(i) && prime(n-i)){
            count++;
        }
    }
    printf("%d", count);
    return 0;
}