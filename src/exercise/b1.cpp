//
// Created by Jiang Yinzuo on 2020/5/16.
//

#include <cstdio>
#include <map>

int canvas[1009][2];
int peg[2009];
int canvas_peg_cnt[1009] = {0};

int answer[2009];
std::map<int, bool> has_peg;

int answer_idx = 0;

void add_a_peg(int c_idx) {
    int i = canvas[c_idx][0] + 1;

    while (has_peg[i]) i++;
    answer[answer_idx++] = i;
    has_peg[i] = true;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &canvas[i][0], &canvas[i][1]);
    }
    int p;
    scanf("%d", &p);
    for (int i = 0; i < p; ++i) {
        scanf("%d", &peg[i]);
        has_peg[peg[i]] = true;
    }

    int p_idx = 0;

    for (int i = 0; i < n; ++i) {
        while (peg[p_idx] < canvas[i][0]) p_idx++;
        while (p_idx < p && canvas[i][0] <= peg[p_idx] && peg[p_idx] <= canvas[i][1]) {
            canvas_peg_cnt[i]++;
            if (canvas_peg_cnt[i] > 2) {
                printf("impossible\n");
                return 0;
            }
            if (i < n - 1 && canvas[i][1] == canvas[i+1][0] && peg[p_idx] == canvas[i+1][0])
                canvas_peg_cnt[i+1]++;
            p_idx++;
        }
    }

    for (int c = 0; c < n - 1; c++) {
        if (canvas_peg_cnt[c] == 2) continue;

        if (canvas_peg_cnt[c + 1] < 2) {
            if (canvas_peg_cnt[c] == 0) {
                add_a_peg(c);
                if (canvas[c][1] == canvas[c + 1][0]) {
                    answer[answer_idx++] = canvas[c][1];
                    canvas_peg_cnt[c + 1]++;
                    has_peg[canvas[c][1]] = true;
                } else add_a_peg(c);
            } else if (canvas_peg_cnt[c] == 1) {
                if (canvas[c][1] == canvas[c + 1][0]) {
                    if (has_peg[canvas[c][1]])
                        add_a_peg(c);
                    else {
                        answer[answer_idx++] = canvas[c + 1][0];
                        canvas_peg_cnt[c + 1]++;
                        has_peg[canvas[c][1]] = true;
                    }
                } else {
                    add_a_peg(c);
                }
            }
        } else {
            add_a_peg(c);
            if (canvas_peg_cnt[c] == 0) add_a_peg(c);
        }
    }

    if (canvas_peg_cnt[n - 1] == 1) {
        add_a_peg(n - 1);
    } else if (canvas_peg_cnt[n - 1] == 0) {
        add_a_peg(n - 1);
        add_a_peg(n - 1);
    }

    printf("%d\n", answer_idx);
    if (answer_idx > 0) {
        printf("%d", answer[0]);
        for (int i = 1; i < answer_idx; ++i) {
            printf(" %d", answer[i]);
        }
        printf("\n");
    }

    return 0;
}