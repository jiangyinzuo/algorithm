//
// Created by Jiang Yinzuo on 2020/5/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

static int a[100005];
static int s[100005][7];
static int idx[100005];
static long long dp[100005][(1 << 7) + 3];

int cmp(const void *n1, const void *n2) {
    return a[*(int *) n2] - a[*(int *) n1];
}

int main() {
    int n, p, k;
    scanf("%d %d %d", &n, &p, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
        idx[i] = i;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < p; ++j) {
            scanf("%d", &s[i][j]);
        }
    }

    qsort(idx + 1, n, sizeof(int), cmp);
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int mask = 0; mask < (1 << p); ++mask) {
            int count = 0;
            int tmp_mask = mask;
            while (tmp_mask) {
                if (tmp_mask & 1) ++count;
                tmp_mask >>= 1;
            }
            if (i - 1 - count >= k) {
                if (dp[i - 1][mask] != -1)
                    dp[i][mask] = max(dp[i][mask], dp[i - 1][mask]);
            } else {
                if (dp[i - 1][mask] != -1)
                    dp[i][mask] = max(dp[i][mask], dp[i - 1][mask] + a[idx[i]]);
            }
            for (int j = 0; j < p; ++j) {
                if ((mask & (1 << j)) && dp[i - 1][mask ^ (1 << j)] != -1) {
                    dp[i][mask] = max(dp[i][mask], dp[i - 1][mask ^ (1 << j)] + s[idx[i]][j]);
                }
            }
        }
    }
    printf("%lld\n", dp[n][(1 << p) - 1]);
    return 0;
}