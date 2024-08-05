// Copyright (c) 2021, Jiang Yinzuo. All rights reserved.
#include <vector>
class Solution {
public:
    int superEggDrop(int k, int n) {
        if (k == 1 || n == 1) return n;
        std::vector<std::vector<int>> dp(n+1, std::vector<int>(k+1));
        for (int _k = 1; _k <= k; ++_k)
            dp[1][_k] = 1;
        for (int t = 1; t <= n; ++t)
            dp[t][1] = t;
        for (int t = 2; t <= n; ++t) {
            for (int _k = 2; _k <= k; ++_k) {
                dp[t][_k] = 1 + dp[t-1][_k] + dp[t-1][_k-1];
                if (dp[t][_k] >= n) {
                    return t;
                }
            }
        }
        return -1;
    }
};