//
// Created by jiang on 2020/9/20.
//

#include <cstdio>

int arr[1000];
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", arr + i);
        }
        bool flag = true;
        for (int i = 0; i < n - 1; ++i) {
            if (arr[i] == arr[i+1]) {
                puts("NO");
                flag = false;
                break;
            }
        }
        if (flag) {
            puts("YES");
        }
    }
    return 0;
}