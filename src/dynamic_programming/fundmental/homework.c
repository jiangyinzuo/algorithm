#include <stdio.h>

int solve(int n) {
    // dp[i][j]表示总共i个积木，最小的台阶小于等于j的条件下有几种情况

    int dp[100][100] = {0};
    for (int i = 1; i <= 4; ++i) dp[i][i] = 1;
    for (int i = 5; i <= n; ++i) {
        for (int j = 2; j <= (i - 1) / 2; ++j)
            dp[i][j] = dp[i][j - 1] + dp[i - j][i - j] - dp[i - j][j];
        for (int j = (i - 1) / 2 + 1; j < i; ++j)
            dp[i][j] = dp[i][j-1];
        dp[i][i] = dp[i][i - 1] + 1;
    }
    return dp[n][n];
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", solve(n));
    return 0;
}
