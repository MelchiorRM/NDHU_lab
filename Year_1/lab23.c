#include <stdio.h>
#include <string.h>
int current_position[25];
int stack[25][25];
int top[25];        
int temp_array[25];       
void reset(int a) {
    int id = current_position[a];
    while (stack[id][top[id]] != a) {
        int x = stack[id][top[id]--];
        current_position[x] = x;
        stack[x][++top[x]] = x;
    }
}
void pile(int a, int b) {
    int id_a = current_position[a];
    int id_b = current_position[b];
    int y = -1;
    while (stack[id_a][top[id_a]] != a) {
        temp_array[++y] = stack[id_a][top[id_a]--];
    }
    temp_array[++y] = stack[id_a][top[id_a]--];
    while (y >= 0) {
        int block = temp_array[y--];
        current_position[block] = id_b;
        stack[id_b][++top[id_b]] = block;
    }
}
int main() {
    int n, a, b;
    char operation[5], type[5];
    while (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) {
            stack[i][0] = i;
            current_position[i] = i;
            top[i] = 0;
        }
        while (scanf("%s", operation) && operation[0] != 'q') {
            scanf("%d %s %d", &a, type, &b);
            if (a == b || current_position[a] == current_position[b]) continue;
            if (operation[0] == 'm') reset(a);
            if (type[1] == 'n') reset(b);
            pile(a, b);
        }
        for (int i = 0; i < n; i++) {
            printf("%d:", i);
            for (int j = 0; j <= top[i]; j++) {
                printf(" %d", stack[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}