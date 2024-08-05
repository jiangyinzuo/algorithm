//
// Created by Jiang Yinzuo on 2020/5/30.
//

#include <cstdio>

int arr[3000000];
int idx = 0;
int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", a * b);
    for (int i = b; i <= a * b; i += b) {
        for (int j = 0; j < b; ++j)
            arr[idx++] = i - j;
    }
    printf("%d", arr[0]);
    for (int i = 1; i < idx; ++i)
        printf(" %d", arr[i]);
    printf("\n");
    return 0;
}