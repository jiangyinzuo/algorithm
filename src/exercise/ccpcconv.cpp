//
// Created by jiang on 2020/9/20.
//

#include <cstdio>

int arr[1003][1003];
int kern[4][4];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                scanf("%d", &arr[i][j]);
            }
        }
        for (int i = 1; i <= 3; ++i) {
            for (int j = 1; j <= 3; ++j) {
                scanf("%d", &kern[i][j]);
            }
        }
        bool flag = true;
        if (kern[1][1] != 0) {
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    if (kern[i][j] != 0 && (i != 1 || j != 1)) {
                        flag = false;
                        break;
                    }
                }
                if (!flag) break;
            }
        } else {
            flag = false;
        }
        if (flag) {
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n - 1; ++j) {
                    printf("%d ", arr[i][j]);
                }
                printf("%d\n", arr[i][n]);
            }
        } else {
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n - 1; ++j) {
                    printf("0 ");
                }
                printf("0\n");
            }
        }
    }
    return 0;
}