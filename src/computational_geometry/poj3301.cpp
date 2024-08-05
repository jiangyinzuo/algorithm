//
// Created by 江胤佐_2018112664 on 2020/7/28.
//

#include <cstdio>
#include <cmath>
#include <algorithm>

struct Point {
    int x, y;
} points[31];

const double EPS = 1e-8;
const int INF = 5000;

double get_len(int n, double angle) {
    double x1, y1;
    double max_x1 = -INF, max_y1 = -INF, min_x1 = INF, min_y1 = INF;
    for (int i = 0; i < n; ++i) {
        x1 = cos(angle) * points[i].x - sin(angle) * points[i].y;
        y1 = sin(angle) * points[i].x + cos(angle) * points[i].y;
        max_x1 = std::max(max_x1, x1);
        max_y1 = std::max(max_y1, y1);
        min_x1 = std::min(min_x1, x1);
        min_y1 = std::min(min_y1, y1);
    }
    return std::max(max_x1 - min_x1, max_y1 - min_y1);
}

void solve(int n) {
    double l = 0, r = 3.14159265358979323846;
    while (l + EPS <= r) {
        double mid1 = (l + r) / 2;
        double mid2 = (mid1 + r) / 2;
        double res_1 = get_len(n, mid1);
        double res_2 = get_len(n, mid2);
        if (res_1 > res_2)
            l = mid1;
        else
            r = mid2;
    }
    double res = get_len(n, l);
    printf("%.2lf\n", res * res);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%d %d", &points[i].x, &points[i].y);
        solve(n);
    }
    return 0;
}