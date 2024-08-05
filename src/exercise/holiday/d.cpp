//
// Created by Jiang Yinzuo on 2020/7/1.
//

#include <cstdio>
#include <cstring>

char s[1000009];
char t[1000009];
int main() {
    scanf("%s %s", s, t);
    int s_idx = 0, t_idx = 0, t_len = strlen(t);
    for (; s[s_idx]; ++s_idx) {
        if (s[s_idx] == t[t_idx]) {
            t_idx++;
            if (t_idx >= t_len) {
                printf("YES\n");
                return 0;
            }
        }
    }
    printf("NO\n");
    return 0;
}