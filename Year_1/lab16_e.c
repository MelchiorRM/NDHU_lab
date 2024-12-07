#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
    int a,b;
    while(1){
        scanf("%d %d",&a,&b);
        if(a==0  && b==0){
        break;
        }
        int tab[a];
        for(int i=0;i<a;i++){
            scanf("%d",&tab[i]);
        }   
int temp;
for (int i = 0; i < a-1; i++) {
    for (int j = 0; j < a-i-1; j++) {
        int mod_j = (int) sqrt(tab[j] * tab[j]) % b;
        int mod_j1 = (int) sqrt(tab[j + 1] * tab[j + 1]) % b;
        if (mod_j > mod_j1) {
            temp = tab[j];
            tab[j] = tab[j+1];
            tab[j+1] = temp;
            }
        else if(mod_j  == mod_j1){
            if(tab[j]%2 == 0 && tab[j+1]%2 != 0){
                temp = tab[j];
                tab[j] = tab[j+1];
                tab[j+1] = temp;
            }
            else if(tab[j]%2 != 0 && tab[j+1]%2 != 0){
                if(tab[j]>tab[j+1]){
                    temp = tab[j];
                    tab[j] = tab[j+1];
                    tab[j+1] = temp;
                }
            }
            else if(tab[j]%2 ==0  && tab[j+1]%2 ==0){
                if(tab[j]<tab[j+1]){
                    temp = tab[j];
                    tab[j] = tab[j+1];
                    tab[j+1] = temp;
                }
             }
        }
    }
}
printf("%d %d\n", a, b);
for(int i=0;i<a;i++){
    printf("%d\n",tab[i]);
    }
}
printf("0 0");
    return 0;
}