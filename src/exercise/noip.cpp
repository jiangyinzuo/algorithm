#include <cstdio>
#include <map>

int arr[505];


int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int a;
    std::map<int, int> map;
    std::map<int, std::pair<int, int>> dp;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a);
        map[a]++;
    }
    if (map.size() == 1) {
        puts("0");
        return 0;
    }
    for (auto i = map.begin(); i != map.end();) {
        auto j = i++;
        dp[i->first].second = dp[j->first].first;
    }
    // dp[i][0]

    return 0;
}