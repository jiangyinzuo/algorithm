//
// Created by Jiang Yinzuo on 2020/7/1.
//

#include <cstdio>
#include <algorithm>
#include <cstring>

int arr[100008];
int stack[100009];
int s_idx = 0;

int answer[100009] ;

int main() {
    memset(answer, -1, sizeof(answer));
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", arr + i);

    stack[s_idx++] = 0;
    for (int i = 1; i < n; ++i) {
        while (s_idx > 0 and arr[stack[s_idx - 1]] < arr[i]) {
            answer[stack[s_idx - 1]] = i - stack[s_idx - 1] - 1;
            --s_idx;
        }
        stack[s_idx++] = i;
    }

    for (int i = 0; i < n; ++i) {
        if (answer[i] == -1) {
            printf("%d ", std::min(arr[i] + i + 1, n) - i - 1);
        } else {
            printf("%d ", answer[i]);
        }
    }
    return 0;
}
