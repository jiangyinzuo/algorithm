//
// Created by Jiang Yinzuo on 2020/7/17.
//

#include <cstdio>
#include <algorithm>
#include <cstring>

const int MOD = 100000007;
long long dp[1001][1001];
int arr[1001];
int gcd[1001][1001] = {0};

void get_gcd(int n, int m) {
    for (int i = 1; i <= 1000; ++i) {
        for (int j = 1; j <= 1000; ++j) {
            if (!gcd[i][j]) {
                for (int k = 1; k * i <= n && k * j <= m; ++k) {
                    gcd[k * i][k * j] = k;
                }
            }
        }
    }
}

void solve(int n, int max_gcd) {
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; ++i) {
        dp[i][arr[i]] = 1;
        for (int j = 1; j <= max_gcd; ++j) {
            dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
            dp[i][gcd[arr[i]][j]] = (dp[i][gcd[arr[i]][j]] + dp[i - 1][j]) % MOD;
        }
    }

    long long answer = 0;
    for (int i = 1; i <= max_gcd; ++i) {
        answer = (answer + dp[n][i] * i) % MOD;
    }
    printf("%lld\n", answer);
}

int main() {
    get_gcd(1000, 1000);
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int max_gcd = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", arr + i);
            max_gcd = std::max(max_gcd, arr[i]);
        }
        solve(n, max_gcd);
    }
    return 0;
}
