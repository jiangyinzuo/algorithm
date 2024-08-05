//
// Created by 江胤佐-2018112664 on 2020/7/2.
//

#include <cstdio>
#include <cstring>

int topics[1004];
int dp[1004];
int min_kls[1004];

const int INF = 0x7fffffff;

inline int calc_dissatisfaction(int c, int remain_time) {
    if (remain_time == 0) return 0;
    if (remain_time <= 10) return -c;
    return (remain_time - 10) * (remain_time - 10);
}

void solve(int n, int l, int c) {
    memset(dp, 0, sizeof(dp));
    memset(min_kls, 0, sizeof(min_kls));

    for (int i = 1; i <= n; ++i) {
        min_kls[i] = INF;
        int total = 0;
        for (int j = i - 1; j >= 0; --j) {
            total += topics[j + 1];
            if (total > l) break;

            int cost = dp[j] + calc_dissatisfaction(c, l - total);
            if (min_kls[i] == min_kls[j] + 1 && cost >= dp[i]) continue;
            min_kls[i] = min_kls[j] + 1;
            dp[i] = cost;

        }
    }
    printf("Minimum number of lectures: %d\n", min_kls[n]);
    printf("Total dissatisfaction index: %d\n\n", dp[n]);
}

int main() {
    int n;
    int case_count = 0;
    while (scanf("%d", &n) != EOF && n) {
        case_count++;

        int l, c;
        scanf("%d %d", &l, &c);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", topics + i);
        }
        printf("Case %d:\n\n", case_count);
        solve(n, l, c);

    }
    return 0;
}