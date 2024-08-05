//
// Created by Jiang Yinzuo on 2020/7/4.
//

#include <cstdio>
#include <cstring>

char s[200003];

int main() {
    scanf("%s", s);
    int s_len = strlen(s);
    int l_idx = 0, r_idx = s_len - 1;
    int del_l_idx = -1, del_r_idx = -1;
    int re_r_idx;
    bool l_try = false, r_try = false;
    while (l_idx < r_idx) {
        if (s[l_idx] == s[r_idx]) {
            l_idx++, r_idx--;
        } else if (!l_try) {
            del_l_idx = l_idx++;
            re_r_idx = r_idx;
            l_try = true;
        } else if (!r_try) {
            l_idx = del_l_idx;
            r_idx = re_r_idx - 1;
            del_l_idx = -1;
            del_r_idx = re_r_idx;
            r_try = true;
        } else {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    if (l_try) {
        if (r_try) {
            printf("%d\n", del_r_idx + 1);
        } else {
            printf("%d\n", del_l_idx + 1);
        }
    } else {
        printf("%d\n", l_idx + 1);
    }
    return 0;
}