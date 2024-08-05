#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, m, a, b;
    std::cin >> n >> m >> a >> b;
    vector<int> v(m);
    for (int &e: v)
        std::cin >> e;
    int max_firecracker_cnt = abs(b - a) - 1, fire_cracker_cnt = 0;
    int time = a < b ? b - 1 : n - b;
    sort(v.rbegin(), v.rend());

    for (int i = 0; i < m && fire_cracker_cnt < max_firecracker_cnt; ++i) {
        if (time > v[i]) {
            ++fire_cracker_cnt;
            --time;
        }
    }
    printf("%d\n", fire_cracker_cnt);
}

int main() {
    int cases;
    cin >> cases;
    while (cases--) {
        solve();
    }
    return 0;
}
