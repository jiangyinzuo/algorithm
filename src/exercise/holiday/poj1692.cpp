//
// Created by 江胤佐-2018112664
//

#include <cstdio>
#include <cstring>
#include <algorithm>

int line1[104], line2[104];
int dp[104][104];
int last_a[104];

void solve(int n1, int n2) {
    memset(dp, 0, sizeof(dp));
    memset(last_a, 0, sizeof(last_a));

    for (int i = 1; i <= n1; ++i) {
        int last_b = 0;
        for (int j = 1; j <= n2; ++j) {
            dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            if (line1[i] == line2[j]) {
                last_b = j;
            } else if (last_a[line2[j]] && last_b) {
                dp[i][j] = std::max(dp[i][j], dp[last_a[line2[j]] - 1][last_b - 1] + 2);
            }
        }
        last_a[line1[i]] = i;
    }
    printf("%d\n", dp[n1][n2]);
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n1, n2;
        scanf("%d %d", &n1, &n2);

        for (int i = 1; i <= n1; ++i) scanf("%d", line1 + i);
        for (int i = 1; i <= n2; ++i) scanf("%d", line2 + i);

        solve(n1, n2);
    }
    return 0;
}
