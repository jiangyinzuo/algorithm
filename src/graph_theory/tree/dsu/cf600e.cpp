#include <cstdio>
#include <vector>
#include <bitset>

constexpr int MAX_N = 100005;
int color[MAX_N];
std::vector<int> tree[MAX_N];
int sizes[MAX_N] = {0};

void get_size(int cur_v, int father) {
    for (auto &i : tree[cur_v]) {
        if (i != father) {
            get_size(i, cur_v);
            sizes[cur_v] += sizes[i];
        }
    }
    sizes[cur_v] += 1;
}


void dfs(int cur_v, int father) {
    static std::bitset<MAX_N> has_color;
    if (tree[cur_v].size() == 1) {
        has_color[color[cur_v]] = true;
        return;
    }
    int max_child = -1;
    int max_child_size = 0;
    for (auto &i : tree[cur_v]) {
        if (i != father && sizes[i] > max_child_size) {
            max_child_size = sizes[i];
            max_child = i;
        }
    }
    for (auto &i : tree[cur_v]) {
        if (i != father && i != max_child) {
            dfs(i, father);
        }
    }

}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", color + i);
    }
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
    }

    get_size(1, 0);
    dfs(1, 0);
    return 0;
}