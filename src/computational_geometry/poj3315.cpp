// 江胤佐 2018112664
#include <cstdio>
#include <vector>

const double INF = 1000000.0;

double x[100], y[100], one_board[100][100];

inline bool lh_angle(int p0, int p1, int p2) {
    return (y[p1] - y[p0]) / (x[p1] - x[p0]) < (y[p2] - y[p1]) / (x[p2] - x[p1]);
}

std::vector<int> vec;

void mark_convex_hull(int n) {
    vec.clear();
    vec.push_back(0);
    if (n < 3 || !lh_angle(0, 1, 2))
        vec.push_back(1);
    vec.push_back(2);
    for (int i = 3; i < n; i++) {
        while (vec.size() >= 2 && lh_angle(vec[vec.size() - 2], vec[vec.size() - 1], i))
            vec.pop_back();
        vec.push_back(i);
    }
}

void calc_one_board(int a, int b) {
    double best = INF, slope, intercept, Max;
    for (int i = 0; i < vec.size() - 1 && vec[i + 1] <= b; ++i) {
        slope = (y[vec[i + 1]] - y[vec[i]]) / (x[vec[i + 1]] - x[vec[i]]);
        intercept = y[vec[i]] - slope * x[vec[i]];
        Max = 0.0;
        for (int k = a; k <= b; ++k)
            Max = std::max(Max, slope * x[k] + intercept - y[k]);
        best = std::min(best, Max);
    }
    one_board[a][b] = best;
}

void calc_best(int n, int b) {
    double dp[100][100], maxi;
    for (int i = 1; i < n; i++)
        dp[1][i] = one_board[0][i];

    for (int k = 2; k <= b; k++)
        for (int i = k; i < n; i++) {
            dp[k][i] = INF;
            for (int j = 1; j < i; j++)
                if (dp[k - 1][j] < INF && one_board[j + 1][i] < INF) {
                    maxi = std::max(dp[k - 1][j], one_board[j + 1][i]);
                    dp[k][i] = std::min(dp[k][i], maxi);
                }
        }
    printf("%.3lf\n", dp[b][n - 1]);
}

int main() {
    int n, b;
    while (scanf("%d %d", &n, &b) && n) {
        for (int i = 0; i < n; i++)
            scanf("%lf %lf", &x[i], &y[i]);
        mark_convex_hull(n);
        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++)
                calc_one_board(i, j);
        calc_best(n, b);
    }
    return 0;
}