#include <string.h>

int main() 
{
  	init();
  	char *str = s1;
	char *key = s2;
	int l1 = strlen(str), l2 = strlen(key);
	int i, j, count = 0;
  
	for (i = 0; *(str + i) != 0 && i <= l1 - l2; i++)
	{
		for (j = 0; *(key + j) != 0; j++)
		{
			if(*(key + j) != *(str + i + j))
				break;
		}

		count = (!(*(key + j))) ? count + 1: count;
	}

	printf("%d", count);

	return 0;

}