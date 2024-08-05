#include <stdio.h>

int dp[30003];
int value[26];
int weight[26];

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int capacity, n;
    int temp_weight, temp_value;
    scanf("%d %d", &capacity, &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &temp_weight, &temp_value);
        value[i] = temp_weight * temp_value;
        weight[i] = temp_weight;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = capacity; j >= weight[i]; --j) {
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
    printf("%d\n", dp[capacity]);
    return 0;
}