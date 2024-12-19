#include <stdio.h>

void spiral(int row, int column, int matrix[row][column]){
    int up,down,left,right;
    up = 0; down = row - 1;
    left = 0; right = column - 1;
    while(up<=down && left<=right){
        for(int i=left;i<=right;i++){
            printf("%d ",matrix[up][i]);
        }
        up++;
        for(int i=up;i<=down;i++){
            printf("%d ",matrix[i][right]);
        }
        right--;
        if(up<=down){
            for(int i=right;i>=left;i--){
                printf("%d ",matrix[down][i]);
            }
            down--;
        }
        if(left<=right){
            for(int i=down;i>=up;i--){
                printf("%d ",matrix[i][left]);
            }
            left++;
        }
    }
}
int main(){
    int r,c;
    scanf("%d %d", &r, &c);
    int matrix[r][c];
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            scanf("%d",&matrix[i][j]);
        }
    }
    spiral(r,c,matrix);
    return 0;
    return 0;
}