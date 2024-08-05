//
// Created by Jiang Yinzuo on 2020/10/7.
//

#include <cstdio>
#include <cmath>

int main() {
    int t;
    scanf("%d", &t);
    for (int kase = 1; kase <= t; ++kase) {
        double r, h;
        scanf("%lf %lf", &r, &h);
        double x0, y0, z0;
        scanf("%lf %lf %lf", &x0, &y0, &z0);
        double vx, vy, vz;
        scanf("%lf %lf %lf", &vx, &vy, &vz);

        // vx * x + vy * y + vz * z + d = 0
        double d = -vx * x0 - vy * y0 - vz * z0;

        double x1 = (h * r * vz + d * r) / (sqrt(2) * h * vz - vx - vy * r);
        double y1 = x1;
        double z1 = (h * r * (vx + vy + sqrt(2) * h * d)) / (r * (vx + vy) - sqrt(2) * h * vz);
        double time = std::abs(x0 - x1 / vx);
        printf("Case %d: %lf\n", kase, time);
    }
    return 0;
}