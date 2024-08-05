//
// Created by jiang on 2020/8/12.
//

#include <cstdio>
#include <algorithm>

int mat1[1001][1001] = {0}, mat2[1001][1001] = {0};

struct DP {
    int width, height;
} dp[1001][1001] = {{0, 0}};

struct Pair {
    int first, second;
} points2[1000001] = {{0, 0}};

void get_mat(int mat[][1001], int n, int m) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            scanf("%d", &mat[i][j]);
        }
    }
}

void solve(int n, int m) {
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            points2[mat2[i][j]] = {i, j};

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            auto &p2 = points2[mat1[i][j]];
            dp[i][j] = {1, 1};
            if (p2.first >= 2 && i >= 2 && mat1[i - 1][j] == mat2[p2.first - 1][p2.second]) {
                dp[i][j].height += dp[i - 1][j].height;
            }

            if (p2.second >= 2 && j >= 2 && mat1[i][j - 1] == mat2[p2.first][p2.second - 1]) {
                dp[i][j].width += dp[i][j - 1].width;
            }
        }
    }
    int answer = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            answer = std::max(answer, dp[i][j].width * dp[i][j].height);
        }
    }
    printf("%d\n", answer);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    get_mat(mat1, n, m);
    get_mat(mat2, n, m);

    solve(n, m);
    return 0;
}