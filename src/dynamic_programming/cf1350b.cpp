//
// Created by Jiang Yinzuo on 2020/8/11.
//

#include <cstdio>
#include <array>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        std::array<int, 100003> arr{}, dp{0, 1};
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &arr[i]);
        }
        for (int i = 2; i <= n; ++i) {
            dp[i] = 1;
            for (int j = 1; j * j <= i; ++j) {
                if (i % j == 0) {
                    if (arr[i] > arr[j])
                        dp[i] = std::max(dp[i], dp[j] + 1);
                    if (arr[i] > arr[i/j] && j != 1)
                        dp[i] = std::max(dp[i], dp[i/j] + 1);
                }
            }
        }
        int ans = dp[1];
        for (int i = 2; i <= n; ++i) ans = std::max(ans, dp[i]);
        printf("%d\n", ans);
    }
}