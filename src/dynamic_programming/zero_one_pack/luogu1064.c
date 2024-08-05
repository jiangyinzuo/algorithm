#include <stdio.h>
#include <string.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int capacity, m;
    scanf("%d %d", &capacity, &m);

    int value[560];
    int weight[560];
    int type[560];
    int temp_value;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &weight[i], &temp_value, &type[i]);
        value[i] = weight[i] * temp_value;
        if (type[i] == 1) {
            ++m;
            value[i+1] = value[i];
            weight[i+1] = weight[i];
            type[i+1] = type[i];
            ++i;
        }
    }

    int dp[32002];
    short buy_main_component[30002] = {0};
    for (int i = 0; i < m; ++i) {
        
        // zero one pack
        if (type[i] == 0) {
            memset(buy_main_component, 0, sizeof(buy_main_component));
            for (int j = capacity; j >= capacity - weight[i]; --j) {
                if (dp[j] <= dp[j - weight[i]] + value[i]) {
                    dp[j] = dp[j - weight[i]] + value[i];
                    buy_main_component[j] = 1;
                }
            }
        }
        else {
            for (int j = capacity; j >= capacity - weight[i]; --j) {
                if (buy_main_component[j - weight[i]] && dp[j] <= dp[j - weight[i]] + value[i]) {
                    dp[j] = dp[j - weight[i]] + value[i];
                }
            }
        }
    }
    printf("%d\n", dp[capacity]);
    return 0;
}