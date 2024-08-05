//
// Created by Jiang Yinzuo on 2020/5/16.
//

#include <stdio.h>
#include <string.h>

#define MAX_N 1000003

char s[MAX_N];
char s2[MAX_N];

int main() {
    scanf("%s", s);
    strcpy(s2, s);
    int len = strlen(s);

    int zero_cnt = 0;

    for (int j = len - 1; j > 0; --j) {
        if (s2[j] == '(') {
            zero_cnt++;
            if (s2[j - 1] == ')') {
                s2[j - 1] = '(';
                zero_cnt--;
                int flag = 0;
                for (int k = len - 1; k >= j; --k) {
                    if (flag == 0) {
                        s2[k] = ')';
                        flag++;
                    } else {
                        if (zero_cnt) {
                            s2[k] = '(';
                            zero_cnt--;
                            flag--;
                        } else {
                            s2[k] = ')';
                            flag++;
                        }
                    }
                }
                break;
            }
        }
    }
    printf("%s\n", s2);

    zero_cnt = 0;
    int one_cnt = 0;
    for (int j = len-1; j > 0; --j) {
        if (s[j] == '(') {
            zero_cnt++;
            if (zero_cnt < one_cnt) {
                s[j] = ')';
                for (int k = j + 1; k < len; ++k) {
                    if (zero_cnt > 0) {
                        s[k] = '(';
                        zero_cnt--;
                    } else {
                        s[k] = ')';
                    }
                }
                break;
            }
        } else {
            one_cnt++;
        }
    }
    printf("%s\n", s);
    return 0;
}