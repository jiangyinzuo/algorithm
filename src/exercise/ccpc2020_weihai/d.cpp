#include <cstdio>
#include <vector>
#include <cmath>
constexpr int MAX_N = 1000005;
std::vector<long long> prime_power;
bool not_prime[MAX_N] = {false};

void thieve() {
    for (long long i = 2; i < MAX_N; i++) {
        if (!not_prime[i]) {
            prime_power.push_back(i);
        }
        for (int j = 0; j < prime_power.size() && i * prime_power[j] < MAX_N; ++j) {
            not_prime[i * prime_power[j]] = true;
            if (i % prime_power[j] == 0) {
                break;
            }
        }
    }
}
int main() {
    thieve();
    int t;
    scanf("%d", &t);
    while (t--) {
        unsigned long long b;
        scanf("%llu", &b);
        bool yes = false;
        for (auto p : prime_power) {
            if (b % p == 0) {
                b /= p;
                if (b % p == 0) {
                    yes = true;
                    break;
                }
                if (b == 1) {
                    break;
                }
                auto _temp = (unsigned long long)sqrt(b);
                if (_temp * _temp == b) {
                    yes = true;
                    break;
                }

            }
        }
        auto _temp = (unsigned long long)sqrt(b);
        if (_temp != 1 && _temp * _temp == b) {
            yes = true;
        }
        puts(yes ? "yes" : "no");
    }
    return 0;
}