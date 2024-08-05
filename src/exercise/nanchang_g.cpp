//
// Created by Jiang Yinzuo on 2020/10/1.
//

#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>

const long long MOD = 998857459;
long long a[2900];
struct T {
    long long value;
    long long zero_cnt;
};
std::vector<T> vec;

void init() {
    a[0] = a[1] = 1;
    for (long long i = 2; i <= 2803; ++i) {
        a[i] = i * a[i - 1] % 998857459;
    }
}

std::map<long long, long long> m;
std::vector<long long> keys;
std::vector<long long> values;

void get_res() {
    std::vector<long long> pre_values(vec.size() + 1);
    pre_values[1] = vec[0].value;
    for (long long i = 2; i < (vec.size() + 1); ++i) {
        pre_values[i] = (pre_values[i - 1] % MOD + vec[i - 1].value % MOD) % MOD;
    }
    std::vector<long long> pre_zeros(vec.size() + 1);
    pre_zeros[1] = vec[0].zero_cnt;
    for (long long i = 2; i < (vec.size() + 1); ++i) {
        pre_zeros[i] = pre_zeros[i - 1] + vec[i - 1].zero_cnt;
    }

    for (long long i = 0; i < vec.size(); i++) {
        for (long long j = i; j < vec.size(); j++) {
            if (i == j) {
                m[1] = std::max(m[1], vec[i].value);
            } else {
                long long qz = pre_zeros[j + 1] - pre_zeros[i + 1] + j - i + 1;
                long long now_value = (pre_values[j + 1] - pre_values[i] + MOD) % MOD;
                m[qz] = std::max(m[qz], now_value);
            }
        }
    }
    long long last_v = 0;
    for (auto &i : m) {
        if (i.second > last_v) {
            keys.push_back(i.first);
            values.push_back(i.second);
            last_v = i.second;
        }
    }
}

int main() {
    init();
    long long n, mm;
    scanf("%lld %lld", &n, &mm);

    long long temp, zero_cnt = 0;
    for (long long i = 0; i < n; ++i) {
        scanf("%lld", &temp);
        if (temp >= 2803) {
            ++zero_cnt;
        } else {
            vec.push_back({a[temp], zero_cnt});
            zero_cnt = 0;
        }
    }
    get_res();

    for (long long i = 0; i < mm; i++) {
        long long now_m;
        scanf("%lld", &now_m);
        long long idx = std::lower_bound(values.begin(), values.end(), now_m) - values.begin();
        if (idx >= values.size()) {
            puts("-1");
        } else {
            printf("%lld\n", keys[idx]);
        }

    }
    return 0;
}