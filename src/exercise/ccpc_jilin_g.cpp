//
// Created by Jiang Yinzuo on 2020/10/7.
//

#include <cstdio>
#include <vector>

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

/**
 * m / n
 */
int continued_fraction(int m, int n, std::vector<int> &res) {
    int sum = 0;
    while (n > 0) {
        if (sum + m / n > 10000) return sum;
        sum += m / n;
        res.push_back(m / n);
        m = m % n;
        std::swap(m, n);
    }
    return sum;
}

int main() {
    char r_str[55];
    int t;
    scanf("%d", &t);
    for (int kase = 1; kase <= t; ++kase) {
        scanf("%s", r_str);

        // m / n
        int m = 0, n = 1;
        for (int i = 2; r_str[i] && i < 8; ++i) {
            m = 10 * m + r_str[i] - '0';
            n *= 10;
        }
        int q = gcd(m, n);
        m /= q;
        n /= q;
        std::vector<int> res;
        int new_rid = continued_fraction(m, n, res);

        // 1 parallel merge
        // 0 serial merge
        int op = (res.size() + 1) % 2, last_new_rid, this_new_rid;
        printf("Case %d:\n", kase);
        int used = 0;
        for (auto iter = res.rbegin(); iter != res.rend(); ++iter) {
            if (*iter > 1) {
                printf("%d %d %d\n", op, used, used + 1);
                ++used;
                for (int i = 2; i < *iter; ++i) {
                    printf("%d %d %d\n", op, used + 1, new_rid);
                    ++new_rid;
                    ++used;
                }
                this_new_rid = new_rid - 1;
            } else {
                this_new_rid = used;
            }
            if (iter != res.rbegin()) {
                printf("%d %d %d\n", op, last_new_rid, this_new_rid);
            }
            last_new_rid = this_new_rid;
            op ^= 1;
        }
    }


    return 0;
}