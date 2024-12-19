#include <stdio.h>

int main() 
{
    int *p;
    init(&p);    
  	int value1 = *(p + 0 * 7 + 4);
    int value2 = *(p + 4 * 7 + 3);

    printf("%d, %d", value1, value2);
    
    return 0;
}