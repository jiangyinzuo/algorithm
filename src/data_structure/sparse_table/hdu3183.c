#include <stdio.h>
#include <string.h>

char seq[1012];
int m;
int size;
char sparse_table[1002][21];
int LOG_2[1011];

void calculate_log() {
    LOG_2[1] = 0;
    for (int i = 2; i <= 1000; ++i) {
        LOG_2[i] = LOG_2[i >> 1] + 1;
    }
}

int min(int n1, int n2) {
    return n1 < n2 ? n1 : n2;
}

void init_sparse_table() {
    memset(sparse_table, '\0', sizeof(sparse_table));
    size = strlen(seq + 1);
    for (int i = 1; i <= size; ++i) {
        sparse_table[i][0] = seq[i];
    }
    for (int j = 1; j <= LOG_2[size]; ++j) {
        for (int i = 1; i + (1 << j) - 1 <= size; ++i) {
            sparse_table[i][j] = min(sparse_table[i][j - 1], sparse_table[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int get_min(int l, int r) {
    return min(sparse_table[l][LOG_2[r - l + 1]], sparse_table[r - (1 << LOG_2[r - l + 1]) + 1][LOG_2[r - l + 1]]);
}

int find_place(int l, int r, int value) {
    for (int i = l; i <= r; ++i) {
        if (value == seq[i]) {
            return i;
        }
    }
    return -1;
}

void solve() {
    char ans[1013] = {'\0'};
    int idx = 0;
    int l = 1;
    int r = m + 1;
    int deleted = 0;
    int place;
    while (deleted < m) {
        ans[idx] = get_min(l, r);
        place = find_place(l, r, ans[idx++]);
        deleted += place - l;
        l = place + 1;
        r = l + m - deleted;
        if (r > size) {
            break;
        }
    }
    if (deleted >= m) {
        while (ans[idx++] = seq[++place]);
    }

    int i = 0;
    while (ans[i] == '0') ++i;
    if (ans[i]) {
        printf("%s\n", ans + i);
    } else {
        printf("0\n");
    }

}

int main() {
    calculate_log();
    while (~scanf("%s %d", seq + 1, &m)) {
        init_sparse_table();
        solve();
    }
    return 0;
}