//
// Created by jiang on 2020/8/16.
//

#include <cstdio>
#include <vector>
#include <map>

int arr[102][102];
int score[102] = {0};

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            scanf("%d", &arr[i][j]);
        }
    }
    if (n == 1) {
        puts("1");
        return 0;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (arr[i][j] > arr[j][i]) {
                score[i] += 3;
            } else if (arr[i][j] == arr[j][i]) {
                score[i]++;
                score[j]++;
            } else {
                score[j] += 3;
            }
        }
    }
    int maxv = 0;
    int winner;
    for (int i = 1; i <= n; ++i) {
        if (maxv < score[i]) {
            maxv = score[i];
            winner = i;
        }
    }
    std::vector<int> vec;

    for (int i = 1; i <= n; ++i) {
        if (maxv == score[i]) vec.push_back(i);
    }
    if (vec.size() > 1) {
        std::map<int, int> diff;
        for (auto &i : vec) {
            for (int j = 1; j <= n; ++j) {
                diff[i] += arr[i][j] - arr[j][i];
            }
        }
        int max_idx, max_diff = -10000;
        for (auto &i : diff) {
            if (i.second > max_diff) {
                max_diff = i.second;
                max_idx = i.first;
            }
        }
        for (auto &i : diff) {
            if (i.second == max_diff && i.first != max_idx) {
                puts("play-offs");
                return 0;
            }
        }
        printf("%d\n", max_idx);
    } else {
        printf("%d\n", winner);
    }
    return 0;
}
