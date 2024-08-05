//
// Created by Jiang Yinzuo on 2020/12/10.
//

#include <algorithm>
#include <cstdio>

long long a[100001], b[100001];

int n;
long long max_score;
void dfs(int base, int cur_v, long long score) {

    if (cur_v > n) {
        max_score = std::max(max_score, score);
        return;
    }
    dfs(base, cur_v * base, score + )
}

int main() {
    scanf("%d", &n);
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", a + i);
        ans += a[i];
    }
    for (int i = 1; i <= n; ++i)
        scanf("%lld", b + i);

    static bool visited[100001]{false};
    for (int i = 2; i <= n; ++i) {
        if (!visited[i]) {
            for (int j = i * i; j <= n; j *= i) {
                visited[j] = true;
                ans -= std::min(a[j], b[j]);
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}