#include <stdio.h>
#include <math.h>

#define SIZE 10000

int is_prime(int n);
void sort(int *arr, int n);
int main()
{
    int n = 0, i = 0, arr[SIZE] = {0};
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    sort(arr, n);
    for (i = 0; i < n - 1; i++)
        printf("%d ", arr[i]);
    printf("%d", arr[i]);
        
    return 0;
}

int is_prime(int n)
{
    if (n < 2)
        return 0;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

void sort(int *arr, int n)
{
    int prime[SIZE], non_prime[SIZE];
    int prime_count = 0, non_prime_count = 0;
    for (int i = 0; i < n; i++) {
        if (is_prime(arr[i]))
            prime[prime_count++] = arr[i];
        else
            non_prime[non_prime_count++] = arr[i];
    }
    for (int i = 0; i < prime_count - 1; i++) {
        for (int j = i + 1; j < prime_count; j++) {
            if (prime[i] < prime[j]) {
                int temp = prime[i];
                prime[i] = prime[j];
                prime[j] = temp;
            }
        }
    }
    for (int i = 0; i < non_prime_count - 1; i++) {
        for (int j = i + 1; j < non_prime_count; j++) {
            if (non_prime[i] > non_prime[j]) {
                int temp = non_prime[i];
                non_prime[i] = non_prime[j];
                non_prime[j] = temp;
            }
        }
    }
    int index = 0;
    for (int i = 0; i < prime_count; i++)
        arr[index++] = prime[i];
    for (int i = 0; i < non_prime_count; i++)
        arr[index++] = non_prime[i];
}