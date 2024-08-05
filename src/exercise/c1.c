//
// Created by Jiang Yinzuo on 2020/5/16.
//

#include <stdio.h>
struct Foo {};
int arr[1000009];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", arr + i);
    }

    int from = -1;
    int to = -1;
    int find_it = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (arr[i] < arr[i + 1]) {
            if (find_it == 1) {
                to = i;
                find_it = 2;
            }
        } else if (arr[i] > arr[i + 1]) {
            if (find_it == 2) {
                printf("impossible\n");
                return 0;
            } else if (find_it == 0) {
                from = i;
                while (from > 0 && arr[from] == arr[from - 1])
                    from--;
                find_it = 1;
            }
        }
    }
    if (find_it == 0) {
        printf("1 1\n");
    } else if (find_it == 1) {
        if (from <= 0 || arr[n - 1] >= arr[from - 1]) {
            if (from < 0)
                from = 0;
            printf("%d %d\n", from + 1, n);
        } else {
            printf("impossible\n");
        }
    } else {
        if (from <= 0) {
            if (arr[0] <= arr[to + 1]) {
                printf("%d %d\n", 1, to + 1);
            } else {
                printf("impossible\n");
            }
        } else if (arr[from - 1] <= arr[to] && arr[from] <= arr[to + 1]) {
            printf("%d %d\n", from + 1, to + 1);
        } else {
            printf("impossible\n");
        }
    }
    return 0;
}