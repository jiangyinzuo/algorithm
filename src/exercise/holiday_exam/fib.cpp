//
// Created by Jiang Yinzuo on 2020/7/19.
//

#include <cstdio>

long long arr[44];

int main() {
    arr[1] = arr[2] = 1;
    arr[3] = 2;
    for (int i = 4; i <= 40; ++i) {
        arr[i] = arr[i-1] + arr[i-2];
    }
    int t;
    scanf("%d", &t);
    while (t--) {
        int m;
        scanf("%d", &m);
        printf("%lld\n", arr[m]);
    }
    return 0;
}