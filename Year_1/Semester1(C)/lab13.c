#include <stdio.h>
int main(){
    int NumberOfData,Data;
    float  Sum, Average;
    scanf("%d ", &NumberOfData);
    Sum=0;
    for (int i=0;i<NumberOfData;i++){
        scanf("%d ",&Data);
        Sum+=Data;
    }
    Average=Sum/NumberOfData;
    printf("%.0f %.2f",Sum,Average);
}