#include <stdio.h>

int f_l[1000];
int f_r[1000];
int seq_prefix_sum[1001];
int seq[1000];

int max(int n1, int n2) {
    return n1 > n2 ? n1 : n2;
}

int min(int n1, int n2) {
    return n1 < n2 ? n1 : n2;
}

int interval_sum(int l, int r) {
    return seq_prefix_sum[r] - seq_prefix_sum[l] + seq[l];
}

void init(int n) {
    // 求前缀和
    seq_prefix_sum[0] = seq[0];
    for (int i = 1; i < n; ++i) {
        seq_prefix_sum[i] = seq_prefix_sum[i - 1] + seq[i];
    }
}

void interval_dp(int n) {
    for (int i = 0; i < n; ++i) {
        f_r[i] = f_l[i] = seq[i];
    }
    for (int dt = 1; dt < n; ++dt) {
        for (int i = 0; i + dt < n; ++i) {
            f_r[i] = seq[i + dt] + max(f_r[i], interval_sum(i, i + dt - 1) - max(f_l[i], f_r[i]));
            f_l[i] = seq[i] + max(f_l[i + 1], interval_sum(i + 1, i + dt) - max(f_l[i + 1], f_r[i + 1]));
        }
    }
    printf("%d\n", max(f_l[0], f_r[0]));
}

int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", seq + i);
        }
        init(n);
        interval_dp(n);
    }
    return 0;
}