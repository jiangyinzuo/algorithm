#include <algorithm>
#include <cstdio>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 2007;
int n, k, ans = 114514, cnt[N], dep[N];
int head[N], edge_id;
struct node {
    int to, next;
} e[N << 1];
void add_edge(int u, int v) {
    ++edge_id, e[edge_id].next = head[u], e[edge_id].to = v, head[u] = edge_id;
}
void dfs(int x, int fa) {
    cnt[dep[x]] ++;
    for(int i = head[x]; i; i = e[i].next) {
        int v = e[i].to;
        if(v == fa) continue;
        dep[v] = dep[x] + 1, dfs(v, x);
    }
}
void work(int x) {
    int maxn = 0, sum = 0;
    if(k % 2 == 0) {
        L(i, 0, k / 2) cnt[i] = 0;
        dep[x] = 0, dfs(x, -1);
        L(i, 0, k / 2) sum += cnt[i];
        ans = min(ans, n - sum);
        return;
    }
    sum ++;
    for(int i = head[x]; i; i = e[i].next) {
        int v = e[i].to;
        L(t, 0, k / 2) cnt[t] = 0;
        dep[v] = 0, dfs(v, x);
        L(t, 0, k / 2 - 1) sum += cnt[t];
        maxn = max(maxn, cnt[k / 2]);
    }
    ans = min(ans, n - sum - maxn);
}
int main() {
    scanf("%d%d", &n, &k);
    L(i, 1, n - 1) {
        int u, v; scanf("%d%d", &u, &v);
        add_edge(u, v), add_edge(v, u);
    }
    L(i, 1, n) work(i);
    printf("%d\n", ans);
    return 0;
}