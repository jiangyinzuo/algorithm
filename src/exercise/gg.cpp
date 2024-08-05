//
// Created by Jiang Yinzuo on 2020/5/5.
//

#include <cstdio>
#include <algorithm>

int arr[1000009];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &arr[i]);
    }
    int start = arr[1];
    std::sort(arr + 1, arr + n + 1);

    long long answer = 0;
    for (int i = 1; i <= n; ++i) {
        if (i > arr[i]) answer += i - arr[i];
        else answer += arr[i] - i;
    }


    printf("%lld ", answer);
    for (int i = 1; i <= n; ++i) {
        if (arr[i] == start) {
            printf("%lld\n", i - 1);
        }
    }
    return 0;
}