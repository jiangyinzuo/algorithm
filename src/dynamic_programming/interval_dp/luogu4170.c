#include <stdio.h>
#include <string.h>

int min(int n1, int n2) {
    return n1 < n2 ? n1 : n2;
}

void interval_dp(char *s, int s_len) {
    int f[51][51] = {0};
    for (int i = 0; i < s_len; ++i) {
        f[i][i] = 1;
    }
    int j;
    for (int len = 2; len <= s_len; ++len) {
        for (int i = 0; i + len - 1 < s_len; ++i) {
            j = i + len - 1;
            if (s[i] == s[j]) {
                f[i][j] = min(f[i][j - 1], f[i + 1][j]);
            } else {
                f[i][j] = f[i][i] + f[i + 1][j];
                for (int k = i + 1; k < j; ++k) {
                    f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j]);
                }
            }
        }
    }
    printf("%d\n", f[0][s_len - 1]);
}

int main() {
    char s[51];
    scanf("%s", s);
    int len = strlen(s);
    interval_dp(s, len);
    return 0;
}