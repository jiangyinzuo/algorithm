#include<bits/stdc++.h>

using namespace std;
const int N = 2e5 + 5;
int T, n, i, j, a[N], xb;
bool bb[N], b[N];
vector<pair<int, int>> ans;

int main() {
    for (i = 2; i < N; ++i)if (!bb[i])for (j = i * 2; j < N; j += i)bb[j] = true;
    for (scanf("%d", &T); T--;) {
        scanf("%d", &n);
        memset(b + 1, false, n);
        ans.clear();
        for (i = n / 2; i > 2; --i)
            if (!bb[i]) {
                xb = 0;
                for (j = i; j <= n; j += i * 2)if (!b[j])a[++xb] = j;
                for (j = xb; j > 1; j -= 2)ans.emplace_back(a[j], a[j - 1]), b[a[j]] = b[a[j - 1]] = true;
                if (j == 1) {
                    ans.emplace_back(a[j] * 2, a[j]);
                    b[a[j] * 2] = b[a[j]] = true;
                }
            }
        xb = 0;
        for (j = 2; j <= n; j += 2)if (!b[j])a[++xb] = j;
        for (j = xb; j > 1; j -= 2)ans.emplace_back(a[j], a[j - 1]), b[a[j]] = b[a[j - 1]] = true;
        printf("%d\n", ans.size());
        for (auto u:ans)printf("%d %d\n", u.first, u.second);
    }
    return 0;
}