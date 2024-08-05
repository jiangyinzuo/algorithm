//
// Created by Jiang Yinzuo on 2020/12/9.
//

#include <cstdio>
#include <vector>

void input_arr(int k, int id, std::vector<int> &problem) {
    int pid;
    for (int i = 0; i < k; ++i) {
        scanf("%d", &pid);
        problem[pid] = id;
    }
}

int main() {
    int k1, k2, k3;
    scanf("%d %d %d", &k1, &k2, &k3);
    int n = k1 + k2 + k3;

    std::vector<int> problem(n + 1);
    input_arr(k1, 0, problem);
    input_arr(k2, 1, problem);
    input_arr(k3, 2, problem);

    std::vector<int> dp[3]{std::vector<int>(n + 1),
                           std::vector<int>(n + 1),
                           std::vector<int>(n + 1)};
    for (int i = 1; i <= n; ++i) {
        dp[0][i] = dp[0][i - 1] + (problem[i] != 0);
        int min_01 = std::min(dp[0][i-1], dp[1][i-1]);
        dp[1][i] = min_01 + (problem[i] != 1);
        dp[2][i] = std::min(min_01, dp[2][i-1]) + (problem[i] != 2);
    }

    printf("%d\n", std::min(std::min(dp[0][n], dp[1][n]), dp[2][n]));
    return 0;
}