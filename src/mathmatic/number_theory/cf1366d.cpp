//
// Created by Jiang Yinzuo on 2020/7/23.
//

#include <vector>
#include <cstdio>

int min_prime[10000007] = {0};

/**
 * 若i为质数，则min_prime[i] = 0
 * 否则mim_prime[i] = 最小质因数
 */
void get_min_prime_factor() {
    // 最小质因数i*i < 10000000
    for (int i = 2; i <= 3163; ++i) {
        if (min_prime[i] == 0) {
            for (int j = i * 2; j <= 10000000; j += i) {
                if (min_prime[j] == 0)
                    min_prime[j] = i;
            }
        }
    }
}

std::vector<int> b_ans, c_ans;

void solve(int a) {
    if (min_prime[a] == 0) {
        b_ans.push_back(-1);
        c_ans.push_back(-1);
        return;
    }
    int c = a;
    while (c % min_prime[a] == 0) {
        c /= min_prime[a];
    }
    if (c > 1) {
        b_ans.push_back(min_prime[a]);
        c_ans.push_back(c);
    } else {
        b_ans.push_back(-1);
        c_ans.push_back(-1);
    }
}

int main() {
    get_min_prime_factor();
    int n;
    scanf("%d", &n);
    int a;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a);
        solve(a);
    }
    for (auto &i : b_ans) {
        printf("%d ", i);
    }
    puts("");
    for (auto &i : c_ans) {
        printf("%d ", i);
    }
    puts("");
    return 0;
}