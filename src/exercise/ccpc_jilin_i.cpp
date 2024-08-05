//
// Created by Jiang Yinzuo on 2020/10/7.
//

#include <cstdio>
#include <algorithm>
#include <deque>

struct BobMonster {
#define DEF 1
    long long strength;
    int kind;

    bool operator<(BobMonster &m) const {
        return kind > m.kind || kind == m.kind && strength < m.strength;
    }
} bob_monsters[100002];

long long alice_monsters[100002];

long long kill_all_monsters(long long atk_sum, int n, int m) {
    std::deque<long long> remain_alice_monsters;
    int alice_idx = 0;
    for (int i = 0; i < m; ++i) {
        if (bob_monsters[i].kind == DEF) {
            while (alice_monsters[alice_idx] < bob_monsters[i].strength) {
                remain_alice_monsters.push_back(alice_monsters[alice_idx]);
                ++alice_idx;
                if (alice_idx >= n) return 0;
            }
            atk_sum -= alice_monsters[alice_idx];
        } else {
            bool attacked = false;
            while (!remain_alice_monsters.empty()) {
                long long a_m = remain_alice_monsters.front();
                remain_alice_monsters.pop_front();
                if (a_m >= bob_monsters[i].strength) {
                    atk_sum -= bob_monsters[i].strength;
                    attacked = true;
                    break;
                }
            }
            for (; !attacked && alice_idx < n; ++alice_idx) {
                if (alice_monsters[alice_idx] >= bob_monsters[i].strength) {
                    atk_sum -= bob_monsters[i].strength;
                    break;
                }
            }
        }
    }
    return atk_sum;
}

long long kill_all_atk_monsters(int n, int m) {
    int bob_idx = 0;
    while (bob_monsters[bob_idx].kind == DEF) ++bob_idx;
    long long atk_sum = 0;
    for (int alice_idx = n - 1;
         alice_idx >= 0 &&
         bob_idx < m &&
         alice_monsters[alice_idx] - bob_monsters[bob_idx].strength;
         --alice_idx, ++bob_idx) {
        atk_sum += alice_monsters[alice_idx] - bob_monsters[bob_idx].strength;
    }
    return atk_sum;
}

int main() {
    int t;
    scanf("%d", &t);
    for (int kase = 1; kase <= t; ++kase) {
        int n, m;
        long long atk_sum = 0;
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; ++i) {
            scanf("%lld", alice_monsters + i);
            atk_sum += alice_monsters[i];
        }
        std::sort(alice_monsters, alice_monsters + n);
        for (int i = 0; i < m; ++i) {
            scanf("%lld", &bob_monsters[i].strength);
        }
        for (int i = 0; i < m; ++i) {
            scanf("%lld", &bob_monsters[i].kind);
        }
        std::sort(bob_monsters, bob_monsters + m);
        printf("Case %d: %lld\n", kase, std::max(kill_all_atk_monsters(n, m),
                                                 kill_all_monsters(atk_sum, n, m)));
    }
    return 0;
}