//
// Created by Jiang Yinzuo on 2020/7/17.
//

#include <cstdio>
#include <cstring>

bool is_prime[1000006];
int answer[1000006] = {0};

void sieve(int n) {
    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; ++i) {
        answer[i] = answer[i - 1];
        if (is_prime[i]) {
            if (is_prime[i-2]) answer[i]++;
            for (int j = i + i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

int main() {
    int n;
    sieve(1000005);
    while (scanf("%d", &n) && n > 0) {
        printf("%d\n", answer[n]);
    }
    return 0;
}