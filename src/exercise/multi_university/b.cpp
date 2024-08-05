//
// Created by Jiang Yinzuo on 2020/7/25.
//

#include <cstdio>
#include <algorithm>

int arr[505];
int dp[505] = {0};

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", arr + i);
    }
    int start;
    for (int i = 0; i < n; ++i) {
        if (arr[i] == 1) {
            start = i;
            break;
        }
    }
    int idx = 0;
    int j;
    for (int i = start;; i = (i + 1) % n) {
        if ((j = std::lower_bound(dp, dp + idx, arr[i]) - dp) == idx) {
            idx++;
        }
        dp[j] = arr[i];
        if ((i + 1) % n == start) break;
    }
    int index = 0;
    int count = 0;
    int last_i = -1;
    for (int i = start;; i = (i + 1) % n) {
        if (arr[i] == dp[index]) {
            index++;
        } else {
            if (last_i == -1) {
                last_i = i;
            } else if (arr[i] != arr[last_i] + 1) {
                count++;
                last_i = i;
            } else {
                last_i++;
            }
        }
        if ((i + 1) % n == start) break;
    }
    if (last_i != -1) count++;
    printf("%d\n", count);
    return 0;
}