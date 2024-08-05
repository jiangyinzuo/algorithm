//
// Created by Jiang Yinzuo on 2020/10/16.
//

#include <cstdio>
#include <cstring>

constexpr int MAX_N = 100005;
constexpr int MOD = 1e9 + 7;
long long A[MAX_N];


static char s[100009];

int main() {

    scanf("%s", s);
    int n = strlen(s);
    A[0] = A[1] = 1;
    for (int i = 2; i <= n; ++i) A[i] = A[i-1] * i % MOD;

    return 0;
}