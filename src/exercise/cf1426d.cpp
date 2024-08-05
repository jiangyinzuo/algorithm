// Copyright (c) 2021, Jiang Yinzuo. All rights reserved.

#include <cstdio>
#include <unordered_set>
using std::unordered_set;

long long a[200009];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld", a + i);
    }

    unordered_set<long long> prefixs;
    prefixs.insert(0);
    long long prefix = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        prefix += a[i];
        if (prefixs.find(prefix) != prefixs.end()) {
            ++ans;
            prefixs.clear();
            prefix = a[i];
            prefixs.insert(0);
        }
        prefixs.insert(prefix);
    }
    printf("%d\n", ans);
    return 0;
}
