# 区间dp

## 例题

### POJ2955 最长括号匹配子序列

$$
dp[i][j]表示序列a_i...a_j的最长括号匹配子序列。\\dp[i][j] = \left\{
\begin{array}{**lr**}
\max(dp[i+1][j-1],\space\ \max\limits_{i\leq\ k\leq\ j-1}(dp[i][k]+dp[k+1][j])),\space\ a_i和a_j不匹配 \\
\max(dp[i+1][j-1]+2,\space\ \max\limits_{i\leq\ k\leq\ j-1}(dp[i][k]+dp[k+1][j])),\space\ a_i和a_j匹配
\end{array}
\right.
$$

```cpp
#include <iostream>
#include <cstring>

int dp[102][102];

void solve(std::string &s) {
    int length = s.length();

    for (int i = 0; i < length - 1; ++i) {
        if ((s[i] == '(' && s[i + 1] == ')') ||
            (s[i] == '[' && s[i + 1] == ']') ||
            (s[i] == '{' && s[i + 1] == '}'))
            dp[i][i + 1] = 2;
    }

    for (int len = 3; len <= length; ++len) {
        for (int i = 0; i + len - 1 < length; ++i) {
            if ((s[i] == '(' && s[i + len - 1] == ')') ||
                (s[i] == '[' && s[i + len - 1] == ']') ||
                (s[i] == '{' && s[i + len - 1] == '}')) {
                dp[i][i + len - 1] = dp[i + 1][i + len - 2] + 2;
            }
            for (int k = i; k <= i + len - 2; ++k) {
                dp[i][i + len - 1] = std::max(dp[i][i + len - 1], dp[i][k] + dp[k + 1][i + len - 1]);
            }
        }
    }
    std::cout << dp[0][length - 1] << std::endl;
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    while (true) {
        std::cin >> s;
        if (s[0] == 'edges') {
            break;
        }
        memset(dp, 0, sizeof dp);
        solve(s);
    }
    return 0;
}
```