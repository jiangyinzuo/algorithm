#include <stdio.h>
#include <stdlib.h>

int board[50][50] = {0};
int n;
int even_dir[8][2] = {
        {2,  1},
        {2,  -1},
        {1,  2},
        {1,  -2},
        {-2, 1},
        {-2, -1},
        {-1, 2},
        {-1, -2}
};

struct Score {
    int i;
    int score;
};

int count(int x, int y) {
    int result = 0;
    for (int i = 0; i < 8; ++i)
        if (0 <= x + even_dir[i][0] && x + even_dir[i][0] < n &&
            0 <= y + even_dir[i][1] && y + even_dir[i][1] < n &&
            board[x + even_dir[i][0]][y + even_dir[i][1]] == 0)
            result++;
    return result;
}

int eval(int i, int x, int y) {
    if (
            0 <= x + even_dir[i][0] && x + even_dir[i][0] < n &&
            0 <= y + even_dir[i][1] && y + even_dir[i][1] < n &&
            board[x + even_dir[i][0]][y + even_dir[i][1]] == 0) {
        return count(x + even_dir[i][0], y + even_dir[i][1]);
    }
    return -1;
}

int cmp(const void *a, const void *b) {
    return ((struct Score *) a)->score - ((struct Score *) b)->score;
}

void tsp(int layer, int x, int y) {
    if (layer == n * n) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
        exit(0);
    }

    board[x][y] = layer;
    static struct Score score[8];
    int max_score = -1;
    for (int i = 0; i < 8; ++i) {
        score[i].score = eval(i, x, y);
        score[i].i = i;
        max_score = score[i].score > max_score ? score[i].score : max_score;
    }
    if (max_score == -1) {
        board[x][y] = 0;
        return;
    } else {
        qsort(score, 8, sizeof(struct Score), cmp);
        for (int j = 7; j >= 0; --j) {
            if (score[j].score == -1) {
                continue;
            }
            tsp(layer + 1, x + even_dir[score[j].i][0], y + even_dir[score[j].i][1]);
        }
        board[x][y] = 0;
    }
}


int main() {
    scanf("%d", &n);
    tsp(1, 0, 0);
    return 0;
}