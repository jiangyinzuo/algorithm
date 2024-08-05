#include <cstdio>
#include <vector>
#include <cmath>

constexpr int MAX_N = 30003;

std::vector<int> prime_power;
bool not_prime[MAX_N] = {false};

void thieve() {
    for (int i = 2; i < MAX_N; i++) {
        if (!not_prime[i]) {
            prime_power.push_back({i});
        }
        for (int j = 0; j < prime_power.size() && i * prime_power[j] < MAX_N; ++j) {
            not_prime[i * prime_power[j]] = true;
            if (i % prime_power[j] == 0) {
                break;
            }
        }
    }
}

static double dp[MAX_N] = {0};

void knapsack(int capacity) {
    static double log_cache[MAX_N];
    for (int i = 1; i < MAX_N; ++i) log_cache[i] = log(i);
    for (auto p : prime_power) {
        for (int c = capacity; c >= 0; --c) {
            for (int pi = p; pi <= 30000; pi *= p) {
                if (c >= pi)
                    dp[c] = std::max(dp[c], dp[c - pi] + log_cache[pi]);
                else
                    break;
            }
        }
    }
}

#include <ctime>

int main() {
    thieve();
    int t;
    scanf("%d", &t);
//    clock_t time1 = clock();
    knapsack(30000);
//    printf("%d\n", clock() - time1);
    while (t--) {
        int b;
        scanf("%d", &b);
        printf("%.9lf\n", dp[b]);

    }
    return 0;
}