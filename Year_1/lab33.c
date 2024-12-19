#include <stdio.h>
#include <stdlib.h>
int main(){
    typedef struct {
        int row;
        int column;
        int value;
    } Matrix;
    Matrix original_matrix;
    scanf("%d %d %d", &original_matrix.row, &original_matrix.column, &original_matrix.value);

    Matrix values[original_matrix.value];
    for(int i=0;i<original_matrix.value;i++){
        scanf("%d %d %d", &values[i].row, &values[i].column, &values[i].value);
    }
    int copy_matrix[original_matrix.row][original_matrix.column];
    for (int i=0;i<original_matrix.row;i++){
        for (int j=0;j<original_matrix.column;j++){
            copy_matrix[i][j]=0;
        }
    }
    for (int i=0;i<original_matrix.value;i++){
        copy_matrix[values[i].row][values[i].column]=values[i].value;
    }
    for (int i=0;i<original_matrix.row;i++){
        for (int j=0;j<original_matrix.column;j++){
            printf("%d ", copy_matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}