#include <stdio.h>
#include <string.h>

char s1[1001];
char s2[1001];
int len1;
int len2;
int f[1001][1001] = {0};

int max(int n1, int n2) {
    return n1 > n2 ? n1 : n2;
}

void lcs() {
    for (int i = 1; i <= len1; ++i) {
        for (int j = 1; j <= len2; ++j) {
            if (s1[i-1] == s2[j-1]) {
                f[i][j] = f[i - 1][j - 1] + 1;
            } else {
                f[i][j] = max(f[i][j - 1], f[i - 1][j]);
            }
        }
    }
}

void print_lcs() {
    char result[1001] = {'\0'};
    int idx = f[len1][len2];
    int i = len1;
    int j = len2;
    while (i && j) {
        if (s1[i-1] == s2[j-1]) {
            result[--idx] = s1[i-1];
            i--;
            j--;
        } else if (f[i][j - 1] > f[i - 1][j]) {
            j--;
        } else {
            i--;
        }
    }
    printf("%s\n", result);
}

int main() {
    scanf("%s%s", s1, s2);
    len1 = strlen(s1);
    len2 = strlen(s2);
    lcs();
    print_lcs();
    return 0;
}