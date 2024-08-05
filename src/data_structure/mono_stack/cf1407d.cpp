//
// Created by Jiang Yinzuo on 2020/10/17.
//

#include <cstdio>
#include <stack>

int dp[300009];

struct Pair {
    int value, idx;

    Pair(int value, int idx) : value(value), idx(idx) {}
};

int main() {
    int n;
    scanf("%d", &n);
    std::stack<Pair> inc_stack, dec_stack;

    dp[0] = 0;
    int temp;
    scanf("%d", &temp);
    inc_stack.emplace(temp, 0);
    dec_stack.emplace(temp, 0);
    for (int i = 1; i < n; ++i) {
        scanf("%d", &temp);
        if (temp > inc_stack.top().value) {
            inc_stack.emplace(temp, i);
        } else {
            dp[inc_stack.top().idx] = 
        }
    }
}