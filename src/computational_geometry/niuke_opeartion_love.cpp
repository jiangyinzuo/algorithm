//
// Created by Jiang Yinzuo on 2020/7/18.
//

#include <cstdio>
#include <cmath>
#include <set>

const double EPSILON = 1e-3;

struct Point {
    double x, y;
};

struct Vector {
    double x, y;

    double cross_prod(Vector &v) const {
        return this->x * v.y - this->y * v.x;
    }
};

inline double calc_dis_square(Point &p1, Point &p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

int main() {
    int t;
    scanf("%d", &t);
    Point points[20];

    while (t--) {
        int first_idx, second_idx, last_idx;
        for (int i = 0; i <= 19; ++i) {
            scanf("%lf %lf", &points[i].x, &points[i].y);
        }
        std::set<int> long_v, short_v;
        for (int i = 0; i <= 19; ++i) {
            double dis = calc_dis_square(points[i], points[(20 + i - 1) % 20]);
            if (fabs(dis - 81) <= EPSILON) {
                long_v.insert(i);
                long_v.insert((20 + i - 1) % 20);
            } else if (fabs(dis - 64) <= EPSILON) {
                short_v.insert(i);
                short_v.insert((20 + i - 1) % 20);
            }
        }
        for (auto &i : long_v) {
            for (auto &j : short_v) {
                if (i == j) {
                    second_idx = i;
                }
            }
        }
        for (auto &i : long_v) {
            if (i != second_idx) first_idx = i;
        }
        for (auto &j : short_v)
            if (j != second_idx) last_idx = j;
        Vector v1 = {points[second_idx].x - points[first_idx].x, points[second_idx].y - points[first_idx].y};
        Vector v2 = {points[last_idx].x - points[second_idx].x, points[last_idx].y - points[second_idx].y};
        if (v1.cross_prod(v2) > 0) {
            puts("right");
        } else {
            puts("left");
        }
    }
    return 0;
}