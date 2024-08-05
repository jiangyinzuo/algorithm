//
// Created by Jiang Yinzuo on 2020/7/28.
//

#include <cstdio>
#include <algorithm>
#include <ctime>

struct Coin {
    int weight;
    int value;
} coins[505];

void solve(int n, int capacity) {
    if (capacity == 0) {
        puts("The minimum amount of money in the piggy-bank is 0.");
        return;
    }

    static int dp[100001];
    dp[0] = 0;
    for (int i = 1; i <= capacity; ++i)
        dp[i] = 500000009;
    for (int i = 0; i < n; ++i) {
        for (int j = coins[i].weight; j <= capacity; j++) {
            if (dp[j - coins[i].weight] < 500000009)
                dp[j] = std::min(dp[j], dp[j - coins[i].weight] + coins[i].value);
        }
    }
    if (dp[capacity] < 500000009)
        printf("The minimum amount of money in the piggy-bank is %d.\n", dp[capacity]);
    else
        puts("This is impossible.");
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int e, f;
        scanf("%d %d", &e, &f);
        f -= e;
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d %d", &coins[i].value, &coins[i].weight);
        }
        solve(n, f);
    }
    return 0;
}