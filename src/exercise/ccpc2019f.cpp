//
// Created by jiang on 2020/9/19.
//

#include <cstdio>
#include <algorithm>

struct Card {
    int pos, val;
    bool operator<(const struct Card &c) const {
        return pos < c.pos;
    }
} cards[100001];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int card_val;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &card_val);
        cards[card_val] = {i, card_val};
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d", &card_val);
        cards[card_val].pos = - i - 1;
    }
    std::sort(cards + 1, cards + n + 1);
    for (int i = 1; i <= n; ++i) {
        printf("%d ", cards[i].val);
    }
    return 0;
}