#include <stdio.h>
#include <string.h>

char s1[1001], s2[1001];
int f[1001][2];

int max(int n1, int n2) {
    return n1 > n2 ? n1 : n2;
}

void lcs() {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    for (int j = 1; j <= len2; ++j) {
        for (int i = 1; i <= len1; ++i) {
            if (s1[i-1] == s2[j-1]) {
                f[i][j & 1] = f[i - 1][j & 1 ^ 1] + 1;
            } else {
                f[i][j & 1] = max(f[i][j & 1 ^ 1], f[i - 1][j & 1]);
            }
        }
    }
    printf("%d\n", f[len1][len2 & 1]);
}

int main() {
    while (~scanf("%s %s", s1, s2)) {
        memset(f, 0, sizeof(f));
        lcs();
    }
    return 0;
}