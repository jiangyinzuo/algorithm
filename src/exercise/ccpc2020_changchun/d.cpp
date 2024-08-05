#include <cstdio>
#include <cstring>

long long C[3003][3003];
long long sum[3003];
constexpr long long MOD = 1e9 + 7;

void init(long long c) {
    for (int n = 0; n <= 3002; ++n) {
        C[n][0] = C[n][n] = 1;
        sum[n] = 1;
        long long temp = c;
        for (int m = 1; m <= n; ++m) {
            C[n][m] = (C[n - 1][m] + C[n - 1][m - 1]) % MOD;
            sum[n] = (sum[n] + (C[n][m] * temp) % MOD) % MOD;
            temp =  temp *c %MOD;
        }
    }
}

int main() {

    static char n[3001];
    long long c;
    scanf("%s %lld", n, &c);
    init(c);
    long long ans = 1;
    int len = strlen(n);
    for (int i = len - 1; i >= 0; --i) {
        if (n[i] == '1') {
            ans = ((ans * c) % MOD + sum[len - i - 1]) % MOD;
        }
    }
    printf("%lld\n", ans);
    return 0;
}