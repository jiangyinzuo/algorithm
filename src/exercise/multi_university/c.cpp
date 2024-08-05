//
// Created by Jiang Yinzuo on 2020/7/27.
//

#include <cstdio>

int mat[202][202] = {0};
int prefix_mat[202][202] = {0};

#define max(a, b) ((a) > (b) ? (a) : (b))

void solve(int n, int m) {
    double answer = 0;
    double total;
    for (int j = 1; j <= m; ++j) {
        for (int start_i = 1; start_i <= n; ++start_i) {
            for (int end_i = start_i; end_i <= n; ++end_i) {
                total = prefix_mat[end_i][j] - prefix_mat[start_i-1][j];
                answer = max(answer, total / mat[end_i][j]);
            }
        }
    }
    printf("%.10lf\n", answer);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                scanf("%d", &mat[i][j]);
                prefix_mat[i][j] = mat[i][j] + prefix_mat[i - 1][j];
            }
        }
        solve(n, m);
    }
    return 0;
}
