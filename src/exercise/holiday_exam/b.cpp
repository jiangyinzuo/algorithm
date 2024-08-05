//
// Created by Jiang Yinzuo on 2020/7/19.
//

#include <cstdio>
#include <algorithm>

int arr[200005];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", arr + i);
        }
        std::sort(arr, arr + n);
        int answer = 0;
        int count = 0;
        for (int i = 0; i < n; ++i) {
            count++;
            if (count >= arr[i]) {
                answer++;
                count = 0;
            }
        }
        printf("%d\n", answer);
    }
    return 0;
}
