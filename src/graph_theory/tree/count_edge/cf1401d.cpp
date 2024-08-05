//
// Created by Jiang Yinzuo on 2020/10/31.
//

#include <cstdio>
#include <vector>
#include <algorithm>

constexpr int MAX_N = 200008;

std::vector<int> trees[MAX_N];
long long size[MAX_N];
long long contribute[MAX_N];
long long n;

void get_contribute(int cur_v, int father) {
    size[cur_v] = 1;
    for (auto i : trees[cur_v]) {
        if (i != father) {
            get_contribute(i, cur_v);
            size[cur_v] += size[i];
        }
    }
    contribute[cur_v] = size[cur_v] * (n - size[cur_v]);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%lld", &n);
        for (int i = 1; i <= n; ++i) trees[i].clear();
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            scanf("%d %d", &u, &v);
            trees[u].push_back(v);
            trees[v].push_back(u);
        }
        get_contribute(1, 0);
        std::sort(contribute + 1, contribute + 1 + n);
        long long m;
        scanf("%lld", &m);
        long long primes[MAX_N];
        constexpr long long MOD = 1000000007;

        for (int i = 1; i <= m; ++i) {
            scanf("%lld", primes + i);
        }
        do {
            primes[++m] = 1;
        } while (m < n);
        std::sort(primes + 1, primes + m + 1);
        while (m > n) {
            primes[m - 1] = primes[m - 1] * primes[m] % MOD;
            m--;
        }
        long long answer = 0;
        for (int i = 2; i <= n; ++i)
            answer = (answer + primes[i] * contribute[i] % MOD) % MOD;
        printf("%lld\n", answer);
    }
    return 0;
}
