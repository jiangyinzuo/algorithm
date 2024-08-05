//
// Created by Jiang Yinzuo on 2020/5/5.
//

#include <cstdio>
#include <algorithm>

const int MAX_N = 200009;
const int MAX_A = 2000009;
int arr[MAX_N] = {0};
int max_small_num[MAX_A] = {0};

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    if (n == 1) {
        printf("0\n");
        return 0;
    }

    std::sort(arr, arr + n);
    n = std::unique(arr, arr + n) - arr;
    int idx = 0;
    for (int i = 1; i <= arr[n - 1]; ++i) {
        if (i > arr[idx])
            max_small_num[i] = arr[idx++];
        else
            max_small_num[i] = max_small_num[i - 1];
    }
    for (int i = arr[n-1]+1; i < 2*arr[n-1]+1; ++i) max_small_num[i] = arr[n-1];

    int answer = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 2 * arr[i]; j < arr[n - 1] + arr[i]; j += arr[i]) {
            answer = std::max(answer, max_small_num[j] % arr[i]);
        }
        answer = std::max(answer, arr[n - 1] % arr[i]);
    }
    printf("%d\n", answer);
    return 0;
}
