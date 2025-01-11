#include <stdio.h>
#include <limits.h>
#define SIZE 10001
int main(){
    int right_side = 0, left_side = INT_MAX;
    int left = 0, height = 0, right = 0;
    int ans[SIZE]={0};
    while(scanf("%d %d %d", &left, &height, &right) == 3 && left !=0){
        if (right > right_side) right_side = right;
        if (left < left_side) left_side = left;
        for (int i = left; i < right; i++){
            if (ans[i] < height) ans[i] = height;
        }
    }
    for (int i = left_side; i < right_side; i++){
        if (ans[i] != ans[i-1]){
            if (ans[i]== 0){
                printf("%d 0 ", i);
            }
            else printf("%d %d ", i, ans[i]);
        }
    }
    printf("%d 0", right_side);
    return 0;
}