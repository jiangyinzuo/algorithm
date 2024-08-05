//
// Created by jiang on 2020/5/23.
//

#include <cstdio>

int arr[112];

int main() {
    int t;
    scanf("%d", &t);
    int n, m, k;
    while (t--) {
        scanf("%d %d %d", &n, &m, &k);
        for (int i = 0; i < n; ++i) {
            scanf("%d", arr + i);
        }
        int cur_layer = 0;

        int answer = 0;
        int cur_m = m;
        while (cur_layer < n) {
            while (arr[cur_layer] == 0 && cur_layer < n) {
                ++cur_layer;
                if (cur_m < m) {
                    cur_m -= k;
                    if (cur_m <= 0) {
                        cur_m = m;
                        answer++;
                        break;
                    }
                }
            }
            if (cur_layer >= n) break;

            if (cur_m > arr[cur_layer]) {
                cur_m -= arr[cur_layer];
                arr[cur_layer] = 0;
                cur_layer++;
                if (cur_layer == n) {
                    answer++;
                    break;
                }
                if (cur_m <= k) {
                    answer++;
                    cur_m = m;
                } else {
                    cur_m -= k;
                }
            } else {
                arr[cur_layer] -= cur_m;
                answer += (1 + arr[cur_layer] / m);
                arr[cur_layer] %= m;
                cur_m = m;
            }
        }
        printf("%d\n", answer);
    }
    return 0;
}