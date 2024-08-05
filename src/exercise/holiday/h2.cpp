//
// Created by Jiang Yinzuo on 2020/7/3.
//

#include <cstdio>

int arr[200009];

int main() {
    int k;
    scanf("%d", &k);
    int idx = 0;
    for (int i = 0; i < k; ++i) {
        scanf("%d", arr + idx);
        while (idx && arr[idx] == arr[idx - 1]) {
            arr[--idx]++;
        }
        ++idx;
    }
    printf("%d\n%d", idx, arr[0]);
    for (int i = 1; i < idx; ++i) {
        printf(" %d", arr[i]);
    }
    printf("\n");
    return 0;
}