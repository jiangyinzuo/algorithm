#include <cstdio>
#include <vector>

constexpr int MAX_N = 200001;
struct Vertex {
    int to;
    unsigned long long weight;
};
std::vector<Vertex> tree[MAX_N];
long long sci_cnt[3][MAX_N] = {0};
long long tot_cnt[3];
bool has[3][MAX_N] = {false};

unsigned long long ans[3] = {0};

void dfs(int cur_v, int father, unsigned long long fa_cur_weight) {
    for (int i = 0; i < 3; ++i) {
        sci_cnt[i][cur_v] += has[i][cur_v];
    }
    for (auto &v : tree[cur_v]) {
        if (v.to != father) {
            dfs(v.to, cur_v, v.weight);
            for (int i = 0; i < 3; ++i) {
                sci_cnt[i][cur_v] += sci_cnt[i][v.to];
            }
        }
    }
    for (int i = 0; i < 3; ++i) {
        ans[i] += fa_cur_weight * (sci_cnt[i][cur_v] *
                                   (tot_cnt[(i + 1) % 3] - sci_cnt[(i + 1) % 3][cur_v]) +
                                   sci_cnt[(i + 1) % 3][cur_v] * (tot_cnt[i] - sci_cnt[i][cur_v]));
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        unsigned long long w;
        scanf("%d %d %llu", &u, &v, &w);
        tree[u].push_back({v, w});
        tree[v].push_back({u, w});
    }
    int i = 0;
    for (auto &ha : has) {
        int plc;
        scanf("%d", &tot_cnt[i]);
        for (int j = 0; j < tot_cnt[i]; ++j) {
            scanf("%d", &plc);
            ha[plc] = true;
        }
        ++i;
    }
    dfs(1, 0, 0);
    double answer = 0;
    for (i = 0; i < 3; ++i) {
        answer += ans[i] / (double )(tot_cnt[i] * tot_cnt[(i+1)%3]);
    }
    printf("%.12lf\n", answer / (double )2);
    return 0;
}