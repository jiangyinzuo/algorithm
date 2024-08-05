# dp例题

## 普通dp

### HDU1421

现有序列a1, a2, ..., an。需要从中任意选出2*k个数，然后将这2*k个数两两配对。x和y配对的代价是(x-y)^2，比如2和5配对的代价就是9。求最终这k个数对的代价和的最小值。

- 题解 \
序列排序后，设dp\[i]\[j] 为前i个元素中选j对数的最小代价。 \
dp\[i]\[j] = min(dp\[i-2]\[j-1] + (a\[i] - a\[i-1])^2, dp\[i-1]\[j]) \
j = 2 * i时，dp\[i]\[j] = dp\[i-2]\[j-1] + (a\[i] - a\[i-1])^2

```c++
#include <cstdio>
#include <algorithm>
#include <cstring>

static int sum1[2002];
static int dp[2002][1002] = {0};

int main() {
    int n, k;

    while(~scanf("%d %d", &n, &k)) {
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; ++i) {
            scanf("%d", &sum1[i]);
        }
        std::sort(sum1, sum1 + n);
        dp[1][1] = (sum1[0] - sum1[1]) * (sum1[0] - sum1[1]);
        for (int i = 2; i < n; ++i) {
            for (int j = 1; j <= k && j * 2 <= i + 1; ++j) {
                if (j * 2 == i + 1) dp[i][j] = dp[i - 2][j - 1] + (sum1[i] - sum1[i - 1]) * (sum1[i] - sum1[i - 1]);
                else
                    dp[i][j] = std::min(dp[i - 1][j], dp[i - 2][j - 1] + (sum1[i] - sum1[i - 1]) * (sum1[i] - sum1[i - 1]));
            }
        }
        printf("%d\n", dp[n - 1][k]);
    }
    return 0;
}
```