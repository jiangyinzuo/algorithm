//
// Created by Jiang Yinzuo on 2020/3/21.
//

#include <cstdio>

int n, k;

int status_count = 0;
long long bit_status[1024];
long long chess_counts[1024];

void dfs(int cur_place, int bit_arr, int chess_count) {
    if (cur_place >= n) {
        bit_status[++status_count] = bit_arr;
        chess_counts[status_count] = chess_count;
        return;
    }

    dfs(cur_place + 1, bit_arr, chess_count);
    dfs(cur_place + 2, bit_arr + (1 << cur_place), chess_count + 1);
}

long long f[10][1025][1025] = {0};

int main() {

    scanf("%d %d", &n, &k);
    dfs(0, 0, 0);

    for (int i = 1; i <= status_count; ++i) {
        f[1][i][chess_counts[i]] = 1;
    }
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= status_count; ++j) {
            for (int x = 1; x <= status_count; ++x) {
                if (bit_status[x] & bit_status[j] ||
                    (bit_status[x] << 1) & bit_status[j] ||
                    (bit_status[x] >> 1) & bit_status[j]) {
                    continue;
                }
                for (long long cnt = chess_counts[x]; cnt <= k; ++cnt) {
                    f[i][j][cnt] += f[i - 1][x][cnt - chess_counts[j]];
                }
            }
        }
    }

    long long answer = 0;
    for (int i = 1; i <= status_count; ++i) {
        answer += f[n][i][k];
    }
    printf("%lld\n", answer);
    return 0;
}