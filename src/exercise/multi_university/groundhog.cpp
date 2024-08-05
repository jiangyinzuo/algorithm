#include <cstdio>
#include <vector>

std::vector<int> tree[100002];
int father[1000002];
int distance[1000002];
int max_distance[1000002];
bool visited[1000002] = {false};

void dfs(int cur_v, int depth) {
    visited[cur_v] = true;
    max_distance[cur_v] = distance[cur_v] = depth;

    for (auto &i : tree[cur_v]) {
        if (!visited[i]) {
            father[i] = cur_v;
            dfs(i, depth + 1);
            max_distance[cur_v] = std::max(max_distance[cur_v], max_distance[i]);
        }
    }
}


int main() {
    int n, t;
    scanf("%d %d", &n, &t);

    int u, v;
    for (int i = 1; i <= n - 1; ++i) {
        scanf("%d %d", &u, &v);
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    father[n] = 0;
    dfs(n, 0);

    int start_v = 1;
    while (t--) {
        start_v = father[start_v];
        if (start_v == n) {
            break;
        }
    }
    printf("%d\n", std::min(distance[start_v], (max_distance[start_v] + 1) / 2));

    return 0;
}
