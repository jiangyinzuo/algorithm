//
// Created by 江胤佐-2018112664 on 2020/7/4.
//

#include <cstdio>
#include <cstring>

char fence[80][80];
bool grid[160][160];

int odd_next_x_y[4][2] = {{-1, 0},
                          {-1, 1},
                          {1,  0},
                          {1,  1}};
int even_next_x_y[4][2] = {{-1, -1},
                           {-1, 0},
                           {1,  -1},
                           {1,  0}};
int col, row;

int start_x, start_y;
bool is_circle;
int circle_len;

inline bool is_ok(int x, int y) {
    return (1 <= x && x <= row * 2 - 1 &&
            1 <= y && y <= col - (x & 1));
}

void dfs(int cur_x, int cur_y, int length) {
    if (is_circle) return;

    grid[cur_x][cur_y] = true;
    for (int i = 0; i < 4 && !is_circle; ++i) {
        if (cur_x & 1) {
            int next_x = cur_x + odd_next_x_y[i][0];
            int next_y = cur_y + odd_next_x_y[i][1];
            if (is_ok(next_x, next_y)) {
                if (fence[(cur_x + 1) / 2][cur_y] == '/' && i == 2 ||
                    fence[(cur_x + 1) / 2][cur_y] == '\\' && i == 0) {
                    if (next_x == start_x && next_y == start_y && length > 2) {
                        circle_len = length + 1;
                        is_circle = true;
                        return;
                    }
                    if (!grid[next_x][next_y])
                        dfs(next_x, next_y, length + 1);
                }
                if (fence[(cur_x + 1) / 2][cur_y + 1] == '/' && i == 1 ||
                    fence[(cur_x + 1) / 2][cur_y + 1] == '\\' && i == 3) {
                    if (next_x == start_x && next_y == start_y && length > 2) {
                        circle_len = length + 1;
                        is_circle = true;
                        return;
                    }
                    if (!grid[next_x][next_y])
                        dfs(next_x, next_y, length + 1);
                }
            }
        } else {
            int next_x = cur_x + even_next_x_y[i][0];
            int next_y = cur_y + even_next_x_y[i][1];
            if (is_ok(next_x, next_y)) {
                if (fence[cur_x / 2][cur_y] == '/' && i == 1 || fence[cur_x / 2][cur_y] == '\\' && i == 0) {
                    if (next_x == start_x && next_y == start_y && length > 2) {
                        circle_len = length + 1;
                        is_circle = true;
                        return;
                    }
                    if (!grid[next_x][next_y])
                        dfs(next_x, next_y, length + 1);
                }
                if (fence[cur_x / 2 + 1][cur_y] == '/' && i == 2 || fence[cur_x / 2 + 1][cur_y] == '\\' && i == 3) {
                    if (next_x == start_x && next_y == start_y && length > 2) {
                        circle_len = length + 1;
                        is_circle = true;
                        return;
                    }
                    if (!grid[next_x][next_y])
                        dfs(next_x, next_y, length + 1);
                }
            }
        }
    }
}

void solve(int maze_id) {
    int circle_count = 0;
    int max_circle = 0;
    memset(grid, false, sizeof(grid));
    for (int i = 1; i < row * 2 - 1; ++i) {
        for (int j = 1; j <= col - (i & 1); ++j) {
            if (!grid[i][j]) {
                start_x = i;
                start_y = j;
                is_circle = false;
                circle_len = 0;
                dfs(i, j, 0);
                if (is_circle) {
                    ++circle_count;
                    max_circle = max_circle > circle_len ? max_circle : circle_len;
                }
            }
        }
    }
    printf("Maze #%d:\n", maze_id);
    if (circle_count)
        printf("%d Cycles; the longest has length %d.\n", circle_count, max_circle);
    else
        printf("There are no cycles.\n");
    printf("\n");
}

int main() {
    int maze_id = 1;
    while (scanf("%d %d", &col, &row) != EOF && col && row) {
        for (int i = 1; i <= row; ++i)
            scanf("%s", fence[i] + 1);
        solve(maze_id++);
    }
    return 0;
}
