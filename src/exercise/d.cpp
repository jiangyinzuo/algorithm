//
// Created by Jiang Yinzuo on 2020/5/5.
//

#include <cstdio>

char Seq[1000009];

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", Seq);
    int idx = 0;
    int l_count = 0;
    int r_count = 0;
    int answer = 0;
    for (int i = 0; i < n; ++i) {
        if (Seq[i] == '(') l_count++;
        else
            r_count++;
    }
    bool valid = true;
    if (l_count == r_count + 2) {
        for (int i = n - 1; i >= 0; --i) {
            if (Seq[i] == ')') {
                idx--;
            } else {
                idx++;
                if (idx == 1) {
                    if (valid) {
                        valid = false;
                        idx = -1;
                        answer++;
                    } else {
                        printf("0\n");
                        return 0;
                    }
                }
                if (valid)
                    answer++;
            }
        }
        printf("%d\n", answer);
    } else if (l_count + 2 == r_count) {
        for (int i = 0; i < n; ++i) {
            if (Seq[i] == '(') {
                idx--;
            } else {
                idx++;
                if (idx == 1) {
                    if (valid) {
                        valid = false;
                        idx = -1;
                        answer++;
                    } else {
                        printf("0\n");
                        return 0;
                    }
                }
                if (valid)
                    answer++;
            }
        }
        printf("%d\n", answer);
    } else {
        printf("0\n");
    }
    return 0;
}
