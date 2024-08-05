#include <unordered_map>
#include <cstdio>

void init(long long x) {
    std::unordered_map<long long, long long> factor_nums;
    for (long long i = 2; i * i <= x; ++i) {
        while (x % i == 0) {
            ++factor_nums[i];
            x /= i;
        }
    }
    if (x > 1) ++factor_nums[x];
    for (auto &i : factor_nums) {
        printf("%lld %lld\n", i.first, i.second);
    }
}

int main() {
    init(998857459);
    return 0;
}
