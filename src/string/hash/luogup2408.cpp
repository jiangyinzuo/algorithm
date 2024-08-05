//
// Created by jiang on 2020/8/14.
//

#include <cstdio>
#include <unordered_set>

unsigned char s[100002];

unsigned long hash_table[100002];
unsigned long p[100002];

void pre_hash(const unsigned char *str, int n) {
    hash_table[0] = 0;
    p[0] = 1;
    for (int i = 1; i <= n; ++i) {
        hash_table[i] = hash_table[i - 1] * 31 + str[i - 1];
        p[i] = p[i - 1] * 31;
    }
}

inline unsigned long get_hash(int l, int r) {
    return hash_table[r] - hash_table[l - 1] * p[r - l + 1];
}

int main() {
    int n;
    scanf("%d %s", &n, s);
    pre_hash(s, n);

    std::unordered_set<unsigned long> h_set;
    for (int len = 1; len <= n; ++len) {
        for (int i = 1; i <= n - len + 1; ++i) {
            h_set.insert(get_hash(i, i + len - 1));
        }
    }
    printf("%lu\n", h_set.size());

    return 0;
}