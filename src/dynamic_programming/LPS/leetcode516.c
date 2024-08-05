//
// Created by jiang on 2020/2/24.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int max(int n1, int n2) {
    return n1 > n2 ? n1 : n2;
}

int longestPalindromeSubseq(char * s){
    int f[3000][2] = {0};
    int s_len = strlen(s);
    for (int i = 0; i < s_len; ++i) {
        f[i][1] = 1;
    }
    for (int i = 1; i < s_len; ++i) {
        if (s[i-1] == s[i]) {
            f[i-1][0] = 2;
        } else {
            f[i-1][0] = 1;
        }
    }
    for (int j = 3; j <= s_len; ++j) {
        for (int i = 0; i + j - 1 < s_len; ++i) {
            f[i][j&1] = s[i] == s[i+j-1] ? f[i+1][j&1] + 2 : max(f[i+1][j&1^1], f[i][j&1^1]);
        }
    }
    return f[0][s_len&1];
}

int longestPalindromeSubseq2(char * s){
    int len = strlen(s);
    int f[3000];
    int max_f = 0;
    int tmp;
    for (int j = 0; j < len; ++j) {
        f[j] = 1;
        max_f = 0;
        for (int i = j-1; i >= 0; --i) {
            tmp = f[i];
            if (s[i] == s[j]) {
                f[i] = max_f + 2;
            }
            max_f = max(max_f, tmp);
        }
    }
    for (int i = 0; i < len; ++i) {
        max_f = max(max_f, f[i]);
    }
    return max_f;
}

int main() {
    printf("%d\n", longestPalindromeSubseq("bbbab"));
    printf("%d\n", longestPalindromeSubseq2("aabaa"));
    return 0;
}
