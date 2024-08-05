//
// Created by Jiang Yinzuo on 2020/4/9.
//

#include <cstdio>
#include <cstring>

const int MAX_N = 707;
char s[MAX_N];

namespace hash {

const unsigned long long MOD = 212370440130137957UL;
const int BASE = 131;
unsigned long long bases[MAX_N];
unsigned long long hash[MAX_N];

unsigned long long init_BKDR_hash(const char *s) {
    bases[0] = 1;
    hash[0] = 1;
    for (int i = 0; s[i]; ++i) {
        hash[i + 1] = (hash[i] * BASE + (unsigned long long) s[i]) % MOD;
        bases[i + 1] = (bases[i] * BASE) % MOD;
    }
}

unsigned long long get_hash(int left, int right) {
    return (hash[right] - hash[left-1] * bases[right - left + 1] + MOD) % MOD;
}

}

int dp[MAX_N][MAX_N];

int solve(int n ,int left, int right) {
    if (dp[left][right] == -1) return dp[left][right];
    if (left == right) return 1;

    int answer = 0x7ffffff;
    for (int i = 1; i < right; ++i) {
        unsigned long long hash = hash::get_hash(left, left + i - 1);
        for (int j = 1; i + j - 1 < right; j += i) {

        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s);

    memset(dp, -1, sizeof(dp));
    hash::init_BKDR_hash(s);
    solve(n, 0, n-1);
    return 0;
}
