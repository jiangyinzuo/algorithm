//
// Created by jiang on 2020/10/18.
//

#include <cstdio>
#include <vector>
#include <algorithm>

struct Point {
    double x, y;
};
double a[100005], b[100005];

double w, h, x, y;

Point get_inter_point(double x_obj, double y_obj) {
    if (x_obj == 0 || x_obj == h || y_obj == 0 || y_obj == w) {
        return {x_obj, y_obj};
    }
    if (x_obj < x) {
        // left up
        if (y_obj < y) {
            // (y - y_obj) / (x - x_obj) == (y_obj - 0) / (x_obj - xt)
            double xt = x_obj - (y_obj * (x - x_obj) / (y - y_obj));
            if (xt >= 0.) {
                return {xt, 0.};
            }
            // (y - y_obj) / (x - x_obj) == (y_obj - yt) / (x_obj - 0)
            double yt = y_obj - ((y - y_obj) / (x - x_obj) * x_obj);
            return {0, yt};
        } else if (y_obj > y) { // right up
            // (y - y_obj) / (x - x_obj) == (y_obj - w) / (x_obj - xt)
            double xt = x_obj - ((y_obj - w) * (x - x_obj) / (y - y_obj));
            if (xt >= 0.) {
                return {xt, w};
            }
            // (y - y_obj) / (x - x_obj) == (y_obj - yt) / (x_obj - 0)
            double yt = y_obj - ((y - y_obj) / (x - x_obj) * (x_obj - 0));
            return {0, yt};
        } else {
            return {0, y};
        }
    } else if (x_obj > x) {
        // left down
        if (y_obj < y) {
            // (y - y_obj) / (x - x_obj) == (y_obj - 0) / (x_obj - xt)
            double xt = x_obj - (y_obj * (x - x_obj) / (y - y_obj));
            if (xt <= h) {
                return {xt, 0.};
            }
            // (y - y_obj) / (x - x_obj) == (y_obj - yt) / (x_obj - h)
            double yt = y_obj - ((y - y_obj) / (x - x_obj)) * (x_obj - h);
            return {h, yt};
        } else if (y_obj > y) { // right down
            // (y - y_obj) / (x - x_obj) == (y_obj - w) / (x_obj - xt)
            double xt = x_obj - ((y_obj - w) * (x - x_obj) / (y - y_obj));
            if (xt <= h) {
                return {xt, w};
            }
            // (y - y_obj) / (x - x_obj) == (y_obj - yt) / (x_obj - h)
            double yt = y_obj - ((y - y_obj) / (x - x_obj) * (x_obj - h));
            return {h, yt};
        } else {
            return {h, y};
        }
    } else {
        if (y < y_obj) {
            return {x, w};
        } else {
            return {x, 0};
        }
    }
}

bool cmp1(Point &p1, Point &p2) { return p1.x < p2.x; }

bool cmp2(Point &p1, Point &p2) { return p1.y < p2.y; }

double solve(int n) {
    std::vector<Point> left, up, down, right;
    Point p{};
    for (int i = 0; i < n; ++i) {
        p = get_inter_point(a[i], b[i]);
        if (p.x == 0) {
            up.push_back(p);
        } else if (p.x == h) {
            down.push_back(p);
        } else if (p.y == 0) {
            left.push_back(p);
        } else if (p.y == w) {
            right.push_back(p);
        }
    }
    std::sort(left.begin(), left.end(), cmp1);
    std::sort(right.begin(), right.end(), cmp1);
    std::sort(up.begin(), up.end(), cmp2);
    std::sort(down.begin(), down.end(), cmp2);
    double max_dis = 0;
    int idx = 0;

    if (!left.empty()) {
        for (int i = 1; i < left.size(); ++i) {
            max_dis = std::max(max_dis, left[i].x - left[idx++].x);
        }
    }

    if (!right.empty()) {
        p = right[0];
        idx = 0;
        for (int i = 1; i < right.size(); ++i) {
            max_dis = std::max(max_dis, right[i].x - right[idx++].x);
        }
    }

    if (!up.empty()) {
        p = up[0];
        idx = 0;
        for (int i = 1; i < up.size(); ++i) {
            max_dis = std::max(max_dis, up[i].y - up[idx++].y);
        }
    }

    if (!down.empty()) {
        p = down[0];
        idx = 0;
        for (int i = 1; i < down.size(); ++i) {
            max_dis = std::max(max_dis, down[i].y - down[idx++].y);
        }
    }

    if (!up.empty()) {
        if (!left.empty()) {
            max_dis = std::max(up[0].y + left[0].x, max_dis);
        } else if (!down.empty()) {
            max_dis = std::max(max_dis, up[0].y + h + down[0].y);
        } else if (!right.empty()) {
            max_dis = std::max(max_dis, up[0].y + h + w + h - right[right.size() - 1].x);
        } else {
            max_dis = std::max(max_dis, 2 * (w + h) - (up[up.size() - 1].y - up[0].y));
        }
    }

    if (!up.empty()) {
        if (!right.empty())max_dis = std::max(w - up[up.size() - 1].y + right[0].x, max_dis);
        else if (!down.empty()) max_dis = std::max(max_dis, w - up[up.size() - 1].y + h + w - down[down.size() - 1].y);
        else if (!left.empty())
            max_dis = std::max(max_dis, w - up[up.size() - 1].y + h + w + h - left[left.size() - 1].x);
        else {
            max_dis = std::max(max_dis, 2 * (w + h) - (up[up.size() - 1].y - up[0].y));
        }
    }

    if (!down.empty()) {
        if (!right.empty())
            max_dis = std::max(w - down[down.size() - 1].y + h - right[right.size() - 1].x, max_dis);
        else if (!up.empty()) {
            max_dis = std::max(w - down[down.size() - 1].y + h + w - up[up.size() - 1].y, max_dis);
        } else if (!left.empty()) {
            max_dis = std::max(w - down[down.size() - 1].y + h + w + left[0].x, max_dis);
        } else {
            max_dis = std::max(max_dis, 2 * (w + h) - (down[down.size() - 1].y - down[0].y));
        }
    }

    if (!down.empty()) {
        if (!left.empty())max_dis = std::max(down[0].y + h - left[left.size() - 1].x, max_dis);
        else if (!up.empty()) max_dis = std::max(down[0].y + h + up[0].y, max_dis);
        else if (!right.empty()) max_dis = std::max(max_dis, down[0].y + h + w + right[0].x);
        else {
            max_dis = std::max(max_dis, 2 * (w + h) - (down[down.size() - 1].y - down[0].y));
        }
    }

    if (!right.empty()) {
        if (up.empty() && down.empty() && left.empty()) {
            max_dis = std::max(max_dis, 2 * (w + h) - (right[right.size() - 1].x - right[0].x));
        } else if (!left.empty()) {
            if (!up.empty()) {
                max_dis = std::max(max_dis, 2 * (w + h) - (w + left[left.size() - 1].x + right[right.size() - 1].x));
            } else if (!down.empty()) {
                max_dis = std::max(max_dis, (w + left[0].x + right[0].x));
            }
        }
    }

    if (!left.empty()) {
        if (up.empty() && right.empty() && down.empty()) {
            max_dis = std::max(max_dis, 2 * (w + h) - (left[left.size() - 1].x - left[0].x));
        }
    }
    return max_dis;
}

int main() {
    int t;
    scanf("%d", &t);
    for (int kase = 1; kase <= t; ++kase) {

        scanf("%lf %lf", &w, &h);
        scanf("%lf %lf", &x, &y);
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%lf %lf", a + i, b + i);
        }
        if (n == 1) {
            printf("Case #%d: %.8lf\n", kase, 2 * (w + h));
        } else
            printf("Case #%d: %.8lf\n", kase, solve(n));
    }
    return 0;
}