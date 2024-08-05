//
// Created by Jiang Yinzuo on 2020/12/10.
//

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10;
std::mt19937 rnd(time(0));
int T, a[N], n, p, dp[N], res;
unordered_map<int, int> mp;
inline int qmi(int a, int b = p - 2) {
    int res = 1;
    while (b) {
        if (b & 1)
            res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}
int solve(int l, int r) {
    int res = 2;
    int q = a[r] * qmi(a[l]) % p;
    for (int i = r + 1, pre = a[r]; i <= n; i++)
        if (pre * q % p == a[i])
            pre = a[i], res++;
    for (int i = l - 1, pre = a[l]; i >= 1; i--)
        if (a[i] * q % p == pre)
            pre = a[i], res++;
    return res;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        cin >> n >> p;
        res = 0;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= 150; i++) {
            int x = rnd() % (n - 1) + 1;
            for (int j = x + 1; j <= n && j <= x + 2; j++)
                res = max(res, solve(x, j));
        }
        if (res < (n + 1) / 2)
            cout << -1 << '\n';
        else
            cout << res << '\n';
    }
    return 0;
}