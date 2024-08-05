//
// Created by jiang on 2020/9/16.
// 最大子区间和

#include <cstdio>

long long arr[200005];

void solve(int n) {

    long long res = 0;
    for (int i = 0; i < n; i += 2) {
        res += arr[i];
    }

    long long result1 = 0, sum = 0;
    for (int i = 1; i < n; i += 2) {
        sum += arr[i] - arr[i - 1];
        if (sum < 0) sum = 0;
        if (sum > result1) result1 = sum;
    }

    long long result2 = 0;
    sum = 0;
    for (int i = 2; i < n; i += 2) {
        sum += arr[i - 1] - arr[i];
        if (sum < 0) sum = 0;
        if (sum > result2) result2 = sum;
    }

    printf("%lld\n", result1 > result2 ? (result1 + res) : (result2 + res));
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%lld", arr + i);
        }
        solve(n);
    }
    return 0;
}