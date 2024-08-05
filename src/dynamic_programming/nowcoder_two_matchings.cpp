//
// Created by Jiang Yinzuo on 2020/7/18.
//

#include <cstdio>
#include <algorithm>

int arr[200005];

long long solve(int n) {
    static long long dp[100005] = {0};

    std::sort(arr, arr + n);
    long long answer = 0;
    for (int i = 1; i <= (n >> 1); ++i) {
        answer += arr[i * 2 - 1] - arr[i * 2 - 2];
    }
#define FOUR(i) (arr[i*2-1] - arr[i*2-3]) + (arr[i*2-2]-arr[i*2-4])
#define SIX(i) (arr[i*2-1] - arr[i*2-3]) + (arr[i*2-2] - arr[i*2-5]) + (arr[i*2-4] - arr[i*2-6])
    dp[2] = FOUR(2);
    if (n == 4) return answer + dp[2];
    dp[3] = SIX(3);
    if (n == 6) return answer + dp[3];
    dp[4] = FOUR(4) + dp[2];
    if (n == 8) return answer + dp[4];
    for (int i = 5; i <= (n >> 1); ++i) {
        dp[i] = std::min(FOUR(i) + dp[i - 2], SIX(i) + dp[i - 3]);
    }
    return answer + dp[n >> 1];
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%d", arr + i);
        printf("%lld\n", solve(n));
    }
    return 0;
}