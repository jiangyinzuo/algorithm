//
// Created by Jiang Yinzuo on 2020/4/29.
//

#include <stdio.h>

#define MAXM 5
#define DEBUG
static int flag = 0;

int cnt = 0;
void Perm(int list[MAXM], int level, int k, int m, int count, int set[MAXM][MAXM], int nlist[MAXM]) {
    int i;
    int nset[MAXM][MAXM] = {0};
    int mlist[MAXM] = {0};
    int klist[MAXM] = {0};
    if (m == 0) {
        for (int l = k; l <= m; l++) {
            set[count - 1][list[l]] = 1;
        }
        return;
    }
    if (k > m) {
        return;
    }

    for (i = k; i <= m; i++) {
        for (int l = 0; l < level; l++)
            klist[l] = nlist[l];
        klist[level] = list[i];
        int left = 0;
        for (int l = 0; l <= m; l++) {
            int s;
            for (s = 0; s <= level; s++) {
                if (list[l] == klist[s])
                    break;
            }
            if (s > level) {
                mlist[left++] = list[l];
            }
        }
        for (int l = 0; l < MAXM; l++) {
            for (int h = 0; h < MAXM; h++) {
                nset[l][h] = set[l][h];
            }
        }
        for (int l = 0; l <= level; l++) {
            nset[count - 1][klist[l]] = 1;
        }
        left--;
#ifdef DEBUG
        printf("list: ");
        for (int i = 0; i < MAXM; ++i) printf("%d ", list[i]);
        printf("\n level: %d, k: %d, n: %d, count: %d\n", level, k, m, count);
        printf("---------\n");
        if (left < 0 && flag == 0) {
            for (int k = 0; k < MAXM; ++k) {
                for (int j = 0; j < MAXM; ++j)
                    printf("%d ", nset[k][j]);
                printf("\n");
            }
            flag = 1;
        }
#endif
        Perm(mlist, 0, 0, left, count + 1, nset, klist);
        Perm(list, level + 1, i + 1, m, count, set, klist);
    }
    cnt++;
}

int main() {
    int list[MAXM] = {0, 1, 2, 3};
    int set[MAXM][MAXM] = {0};
    int nlist[MAXM] = {0};
    Perm(list, 0, 0, 4, 0, set, nlist);

    return 0;
}