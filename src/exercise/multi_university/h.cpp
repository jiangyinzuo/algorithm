#include <iostream>
#include <cstdio>

using namespace std;
typedef long long LL;
const LL MAXN = 1e6 + 5;


LL cnt[MAXN];
LL a[MAXN];
LL s[MAXN];
LL ans[MAXN];
const LL MOD = 1e9 + 7;


void init() {
    fill(cnt, cnt + MAXN, 0);
    for (LL i = 1; i <= 1e6; i++) {
        for (LL j = i; j <= 1e6; j += i) {
            cnt[j]++;
        }
    }

    a[1] = 1;
    s[1] = 1;
    ans[1] = 1;
    for (LL i = 2; i <= 1e6; i++) {
        a[i] = a[i - 1] + cnt[i - 1] + 1;
        s[i] = a[i];
    }

    for (LL i = 1; i <= 1e6; i++) {
        for (LL j = i + i; j <= 1e6; j += i) {
            s[j] -= s[i];
        }
    }

    for (LL i = 2; i <= 1e6; i++) {
        ans[i] = ans[i - 1] + s[i];
    }
}


int main() {
    init();
    LL n;
    while (scanf("%lld", &n) != EOF) {
        printf("%lld\n", ans[n] % MOD);

    }
    return 0;
}
