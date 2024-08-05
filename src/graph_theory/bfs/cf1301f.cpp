//
// Created by Jiang Yinzuo on 2020/10/30.
//

#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>

constexpr int MAX_N = 1000;
int grid[MAX_N][MAX_N];

constexpr int MAX_COLOR = 40;
int distance[MAX_COLOR + 1][MAX_N][MAX_N];

std::vector<std::pair<int, int>> color_group[MAX_COLOR + 1];
int n, m, k;

void bfs(int color) {
    static bool visited[MAX_COLOR + 1];
    for (int i = 1; i <= k; ++i) visited[i] = false;
    std::queue<std::pair<int, int> > queue;
    for (auto p : color_group[color]) {
        distance[color][p.first][p.second] = 0;
        queue.push(p);
    }

    while (!queue.empty()) {
        int r = queue.front().first, c = queue.front().second;
        queue.pop();
        if (!visited[grid[r][c]]) {
            visited[grid[r][c]] = true;
            for (auto &p : color_group[grid[r][c]]) {
                int nr = p.first;
                int nc = p.second;
                if (distance[color][nr][nc] == -1) {
                    distance[color][nr][nc] = distance[color][r][c] + 1;
                    queue.emplace(nr, nc);
                }
            }
        }

        static int dr[4]{1, 0, -1, 0};
        static int dc[4]{0, 1, 0, -1};
        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i], nc = c + dc[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && distance[color][nr][nc] == -1) {
                distance[color][nr][nc] = distance[color][r][c] + 1;
                queue.emplace(nr, nc);
            }
        }
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &grid[i][j]);
            color_group[grid[i][j]].emplace_back(i, j);
        }
    }
    memset(distance, -1, sizeof(distance));

    for (int i = 1; i <= k; ++i) {
        bfs(i);
    }
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
        int r1, c1, r2, c2;
        scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
        --r1, --r2, --c1, --c2;
        int ans = abs(r1 - r2) + abs(c1 - c2);
        for (int color = 1; color <= k; ++color)
            ans = std::min(ans, distance[color][r1][c1] + distance[color][r2][c2] + 1);
        printf("%d\n", ans);
    }
    return 0;
}
