//
// Created by Jiang Yinzuo on 2020/7/1.
//

#include <cstdio>
#include <algorithm>

int arr[100008];

int is_prime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0)
            return false;
    }
    return true;
}

long long get_ans(int prime, int n) {
    long long answer = 0;
    for (int i = 1; i <= n; ++i) {
        answer += abs(arr[i] - prime);
    }
    return answer;
}

void solve(int n) {
    long long answer = 1e18;
    int idx = n / 2;
    if (n % 2 == 0) {
        for (int i = arr[idx]; i <= arr[idx+1]; ++i) {
            if (is_prime(i)) {
                answer = std::min(answer, get_ans(i, n));
                break;
            }
        }
    }


    for (int i = arr[idx + n % 2]; i < 1e17; ++i) {
        if (is_prime(i)) {
            answer = std::min(answer, get_ans(i, n));
            break;
        }
    }

    for (int i = arr[idx + n % 2]; i >= 2; --i) {
        if (is_prime(i)) {
            answer = std::min(answer, get_ans(i, n));
            break;
        }
    }
    printf("%lld\n", answer);

}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i)
        scanf("%d",  arr + i);
    std::sort(arr + 1, arr + n + 1);

    solve(n);
    return 0;
}