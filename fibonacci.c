#include <stdio.h>

int fib(int n, int memo[])
{
    if (n <= 1)
        return n;
    if (memo[n] != 0)
        return memo[n];
    memo[n] = fib(n - 1, memo) + fib(n - 2, memo);
    return memo[n];
}

int main()
{
    int n;
    printf("Enter the limit: ");
    scanf("%d", &n);
    int memo[n];

    for (int i = 0; i < n; i++)
    {
        memo[i] = 0;
        printf("%d ", fib(i, memo));
    }
    return 0;
}