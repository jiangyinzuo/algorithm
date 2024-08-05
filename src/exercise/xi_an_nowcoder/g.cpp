//
// Created by jiang on 2020/5/23.
//

#include <cstdio>
#include <set>
#include <map>

std::set<int> total;
std::map<int, int> up_down_map;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, a, b;
        total.clear();
        up_down_map.clear();
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d %d", &a, &b);
            total.insert(a);
            total.insert(b);
            up_down_map[a]++;
            up_down_map[b]--;
        }
        int max_seat = 0;
        int seat = 0;
        for (auto &i : up_down_map) {
            seat += i.second;
            max_seat = max_seat > seat ? max_seat : seat;
        }
        printf("%lu %d\n", total.size(), max_seat);
    }
    return 0;
}