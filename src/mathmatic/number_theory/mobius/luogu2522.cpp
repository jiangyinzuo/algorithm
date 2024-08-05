//
// Created by jiang on 2020/9/25.
//

#include <cstdio>
#include <algorithm>

constexpr int MAX_N = 50005;
// mu在这里是前缀和
int mu[MAX_N], primes[MAX_N], tot = 0;

void get_mu(int n) {
    static bool flag[MAX_N] = {false};
    mu[1] = 1;
    for (int i = 2; i <= n; ++i) {
        if (!flag[i]) primes[++tot] = i, mu[i] = -1;
        for (int j = 1; j <= tot && i * primes[j] <= n; ++j) {
            flag[i * primes[j]] = true;
            if (i % primes[j] == 0) {
                mu[i * primes[j]] = 0;
                break;
            }
            mu[i * primes[j]] = -mu[i];
        }
    }
    for (int i = 1; i < MAX_N; ++i) mu[i + 1] += mu[i];
}

// 一个二维数论分块
int solve(int n, int m) {
    int res = 0;
    for (int i = 1, j; i <= std::min(n, m); i = j + 1) {
        j = std::min(n / (n / i), m / (m / i));
        res += (mu[j] - mu[i - 1]) * (n / i) * (m / i);
    }
    return res;
}

int main() {
    get_mu(MAX_N - 1);
    int t;
    scanf("%d", &t);
    while (t--) {
        int a, b, c, d, k;
        scanf("%d %d %d %d %d", &a, &b, &c, &d, &k);
        // 容斥
        printf("%d\n",
               solve((a - 1) / k, (c - 1) / k) - solve((a - 1) / k, d / k) -
               solve(b / k, (c - 1) / k) + solve(b / k, d / k));
    }
    return 0;
}
