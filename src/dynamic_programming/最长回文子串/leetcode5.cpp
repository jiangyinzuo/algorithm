//
// Created by jiang on 2020/2/25.
//

#include <cstdio>
#include <cstdlib>

inline int min(int n1, int n2) {
    return n1 < n2 ? n1 : n2;
}

inline int max(int n1, int n2) {
    return n1 > n2 ? n1 : n2;
}

char *longestPalindrome(char *s) {
    char str[4000];
    int len = 0;
    for (int i = 0; s[i]; ++i) {
        str[len++] = '#';
        str[len++] = s[i];
    }
    str[len++] = '#';

    int max_right = 0;
    int center = 0;
    int p_rad[4000] = {0};
    for (int i = 0; i < len; ++i) {
        if (i >= max_right) {
            p_rad[i] = 1;
        } else {
            p_rad[i] = min(max_right - i, p_rad[2 * center - i]);
        }

        while (0 <= i - p_rad[i] && i + p_rad[i] < len && str[i - p_rad[i]] == str[i + p_rad[i]]) {
            ++p_rad[i];
        }
        if (i + p_rad[i] > max_right) {
            max_right = i + p_rad[i];
            center = i;
        }
    }

    int idx = 0;
    int max_len = 0;
    for (int i = 0; i < len; ++i) {
        if (p_rad[i] - 1 > max_len) {
            max_len = p_rad[i] - 1;
            idx = i;
        }
    }

    char *result = (char *)malloc(sizeof(char)*(max_len+1));
    int j = 0;
    if (max_len) {
        for (int i = idx / 2 - max_len / 2; i <= (idx-1) / 2 + max_len / 2; ++i) {
            result[j++] = s[i];
        }
    }

    result[j] = '\0';
    return result;
}

int main() {
    char *s = longestPalindrome("cbcdcbedcbc");
    printf("%s\n", s);
    free(s);
    return 0;
}
