#include<cstdio>

#define N 100000
using namespace std;

long long f[100000 << 1], g[100000 << 2];

int main() {
    int a, m, T, i;
    for (m = 3; m <= N; m++) {
        for (a = m; a <= N; a += m) {
            g[a + 3]++;
            g[a + m + 1]--;
            g[a + m + 2]--;
            g[a + m * 2]++;
        }
    }
    for (i = 1; i <= N + 5; i++)
        g[i] += g[i - 1];
    for (i = 3; i <= N + 5; i++)
        f[i] = f[i - 2] + g[i];
    for (i = 3; i <= N + 5; i++)
        f[i] += f[i - 1];

    scanf("%d", &T);
    int test = 0;
    while (T--) {
        test++;
        int l, r;
        scanf("%d%d", &l, &r);
        printf("Case #%d: %lld\n", test, f[r] - f[l - 1]);
    }
    return 0;
}