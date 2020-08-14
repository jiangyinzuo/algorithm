# 数位DP

## 例题

### hdu2089 区间内不能出现4和62的数字个数

```c++
//
// Created by Jiang Yinzuo on 2020/4/8.
//

#include <cstdio>
#include <cstring>

int dp[8][2];

// 数位数组，高位和数字的高位对应，最低位下标为1
int digit[8];

/**
 * 从最高位往下搜索，如果遍历时最高不受限制，则将搜索结果存入dp数组。
 *
 * @param place 当前搜索到第几位
 * @param pre_is_six 该数字高位是不是6
 * @param is_highest 当前位遍历时是否受到上限限制
 */
int dfs(int place, bool pre_is_six, bool is_highest) {
    if (place == 0) return 1;
    
    // 先前搜索过，直接返回
    if (!is_highest && dp[place][pre_is_six] != -1)
        return dp[place][pre_is_six];
    
    // 枚举该位数字的上限
    int limit = is_highest ? digit[place] : 9;
    int result = 0;
    for (int num = 0; num <= limit; ++num) {
        if (num == 4 || (pre_is_six && num == 2)) continue;
        
        // 只有当前位搜索上限受到限制，且当前位枚举到最高位时，下一位的上限才受到限制
        result += dfs(place - 1, num == 6, is_highest && num == limit);
    }
    if (!is_highest)
        dp[place][pre_is_six] = result;
    return result;
}

int solve(int num) {
    int i = 0;
    while (num) {
        digit[++i] = num % 10;
        num /= 10;
    }
    return dfs(i, false, true);
}

int main() {
    int a, b;
    memset(dp, -1, sizeof(dp));
    while (scanf("%d%d", &a, &b), a || b) {
        printf("%d\n", solve(b) - solve(a - 1));
    }
    return 0;
}
```

### hdu3555 区间内出现49的数字个数

```c++
//
// Created by Jiang Yinzuo on 2020/4/8.
//

#include <iostream>
#include <cstring>

long long dp[64][2];
int digit[64];

long long dfs(int place, bool pre_is_four, bool is_limited) {
    if (place == 0) return 1;
    if (!is_limited && dp[place][pre_is_four] != -1) return dp[place][pre_is_four];

    long long result = 0;
    int limit = is_limited ? digit[place] : 9;
    for (int i = 0; i <= limit; ++i) {
        if (pre_is_four && i == 9) continue;
        result += dfs(place - 1, i == 4, is_limited && i == limit);
    }

    if (!is_limited) dp[place][pre_is_four] = result;
    return result;
}

long long solve(long long num) {
    long long tempNum = num;
    int i = 0;
    while (tempNum) {
        digit[++i] = tempNum % 10;
        tempNum /= 10;
    }
    return num + 1 - dfs(i, false, true);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    memset(dp, -1, sizeof(dp));
    int t;
    std::cin >> t;

    long long n;
    while (t--) {
        std::cin >> n;
        std::cout << solve(n) << std::endl;
    }
    return 0;
}
```