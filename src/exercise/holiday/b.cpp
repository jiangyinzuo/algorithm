//
// Created by Jiang Yinzuo on 2020/7/1.
//

#include <cstdio>
#include <algorithm>
long long result[100005];
int idx = 0;

int main() {
    long long a, b;
    scanf("%lld %lld", &a, &b);
    for (long long i = 1; i * i <= a; ++i) {
        if (a % i == 0) {
            result[idx++] = i;
            if (i != a / i)
                result[idx++] = a / i;
        }
    }
    std::sort(result, result + idx);
    for (int i = 0; i < idx; ++i)
        if (result[i] % b == 0) {
            printf("%lld ", result[i]);
        }
    printf("\n");
    return 0;
}