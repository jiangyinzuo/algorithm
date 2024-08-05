#include <stdio.h>

static char s[10000];
static int stack_num[10000], stack_idx[10000];

int main() {
    scanf("%s", s);
    int idx = 0, num = 0;
    for (int i = 0; s[i]; ++i) {
        if (s[i] == '[')
            num = 0;
        else if ('0' <= s[i] && s[i] <= '9') {
            num = num * 10 + s[i] - '0';
        } else if (s[i] == '|') {
            stack_num[idx] = num;
            stack_idx[idx++] = i + 1;
        } else if (s[i] == ']') {
            if (stack_num[idx - 1] <= 1) {
                --idx;
            } else {
                --stack_num[idx - 1];
                i = stack_idx[idx - 1] - 1;
            }
        } else
            putchar(s[i]);
    }
    return 0;
}