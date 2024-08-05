//
// Created by Jiang Yinzuo on 2020/4/8.
//

#include <cstdio>
#include <algorithm>

int a[2001];
int dp[2001][2001]{0};

void solve(int n, int h, int l, int r) {
    int left_j = 0, right_j = 0;
    for (int i = 1; i <= n; ++i) {
        left_j = (left_j + a[i] - 1) % h;
        right_j = (right_j + a[i]) % h;

        for (int j = 0; j <= h; ++j) {
            dp[i][j] = std::max(dp[i - 1][(j - a[i] + h) % h], dp[i - 1][(j - (a[i] - 1) + h) % h]);
            if (l <= j && j <= r) {
                if (i >= h) dp[i][j]++;
                else if (left_j <= right_j) {
                    if (left_j <= j && j <= right_j)
                        dp[i][j]++;
                } else {
                    if (left_j <= j && j <= right_j + h || left_j - h <= j && j <= right_j)
                        dp[i][j]++;
                }
            }
        }
    }
    int answer = dp[n][0];
    for (int i = 1; i < h; ++i) {
        answer = answer > dp[n][i] ? answer : dp[n][i];
    }
    printf("%d\n", answer);
}

int main() {
    int n, h, l, r;
    scanf("%d %d %d %d", &n, &h, &l, &r);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    solve(n, h, l, r);
    return 0;
}
