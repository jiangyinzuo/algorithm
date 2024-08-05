//
// Created by Jiang Yinzuo on 2020/7/2.
//

#include <cmath>
#include <cstdio>

const double eps = 1e-6;
const int N = 2510;
double f[N] = {0};

void init() {
    for (int i = 1; i < N; i++) {
        f[i] = f[i - 1] + log(i);
    }
}

double calc(int count) {
    double result = 0;
    int num;
    while (count--) {
        scanf("%d", &num);
        result += f[num];
    }
    return result;
}
int main() {
    init();
    int kase;
    scanf("%d", &kase);
    for (int i = 1; i <= kase; i++) {
        int a, b, c;

        scanf("%d%d%d", &a, &b, &c);

        double res1 = calc(a);
        double res2 = calc(b);
        double res3 = calc(c);

        printf("Case #%d: ", i);
        if (res1 > eps + res2 && res1 > eps + res3) puts("A");
        else if (res2 > eps + res1 && res2 > eps + res3) puts("B");
        else if (res3 > eps + res1 && res3 > eps + res2) puts("C");
        else puts("TIE");
    }
    return 0;
}