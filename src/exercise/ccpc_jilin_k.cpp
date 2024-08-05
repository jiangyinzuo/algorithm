#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

enum {
    plain = 0, swamp = 1, mountain = 2, island = 3, forest = 4
};

queue<int> deck[2];

int hand[2][5], field[2][5], grave[2][5];

void draw_card(int p) {
    queue<int> &dck = deck[p];
    int *hnd = hand[p];

    if (!dck.empty()) {
        int x = dck.front();
        dck.pop();
        ++hnd[x];
    }
}

bool draw() {
    if (!deck[0].empty() && !deck[1].empty()) return false;
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 5; ++j)
            if (hand[i][j]) return false;
    return true;
}

bool win(int p) {
    int *fld = field[p];
    for (int i = 0; i < 5; ++i)
        if (!fld[i])
            return false;
    return true;
}

bool empty(int p, int cd[2][5]) {
    for (int i = 0; i < 5; ++i)
        if (cd[p][i])
            return false;
    return true;
}

bool have_effect(int p, int c) {
    queue<int> &dck = deck[p];

    if (c == plain) {
        return !dck.empty();
    } else if (c == swamp) {
        return !empty(p ^ 1, hand);
    } else if (c == mountain) {
        return !empty(p ^ 1, field);
    } else if (c == island) {
        return false;
    } else if (c == forest) {
        return !empty(p, grave);
    } else {
        return assert(0), false;
    }
}

int select_card(int p) {
    static const int prior[] = {swamp, plain, mountain, forest, island};
    int *hnd = hand[p];
    int *fld = field[p];

    vector<int> high, mid;
    for (int i = 0; i < 5; ++i)
        if (hnd[i]) {
            if (!fld[i]) {
                if (have_effect(p, i)) {
                    high.push_back(i);
                } else {
                    mid.push_back(i);
                }
            }
        }
    if (!high.empty()) {
        for (int i = 0; i < 5; ++i) {
            int id = prior[i];
            for (int x : high)
                if (id == x) {
                    --hnd[x];
                    return x;
                }
        }
        return assert(0), -1;
    } else if (!mid.empty()) {
        for (int i = 0; i < 5; ++i) {
            int id = prior[i];
            for (int x : mid)
                if (x == id) {
                    --hnd[x];
                    return x;
                }
        }
        return assert(0), -1;
    } else {
        return -1;
    }
}

int count(int p, int cd[2][5]) {
    int cnt = 0;
    for (int i = 0; i < 5; ++i)
        cnt += cd[p][i];
    return cnt;
}

void discard(int p) {
    static const int prior[] = {island, mountain, plain, swamp, forest};
    int *hnd = hand[p];
    int *grv = grave[p];

    vector<int> cnt[6];
    for (int i = 0; i < 5; ++i)
        cnt[hnd[i]].push_back(i);
    for (int i = 5; i > 0; --i) {
        for (int j = 0; j < 5; ++j) {
            int id = prior[j];
            for (int x : cnt[i])
                if (x == id) {
                    --hnd[x];
                    ++grv[x];
                    return;
                }
        }
    }
    assert(0);
}

void do_mountain(int p) {
    static const int prior[] = {forest, island, mountain, plain, swamp};

    vector<int> cnt[6];
    for (int i = 0; i < 5; ++i)
        cnt[field[p ^ 1][i]].push_back(i);
    for (int i = 1; i <= 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            int id = prior[j];
            for (int x : cnt[i])
                if (x == id) {
                    --field[p ^ 1][x];
                    ++grave[p ^ 1][x];
                    return;
                }
        }
    }
    assert(0);
}

void do_forest(int p) {
    static const int prior[] = {forest, swamp, mountain, island, plain};
    int *hnd = hand[p];
    int *fld = field[p];
    int *grv = grave[p];

    vector<int> cnt[6];
    for (int i = 0; i < 5; ++i)
        cnt[hnd[i] + fld[i]].push_back(i);
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            int id = prior[j];
            for (int x : cnt[i])
                if (x == id) {
                    if (grv[x]) {
                        --grv[x];
                        ++hnd[x];
                        return;
                    }
                }
        }
    }
    assert(0);
}

bool counter_attack(int p) {
    int last = -1;
    for (int i = 0; i < 5; ++i)
        if (!field[p ^ 1][i]) {
            if (last == -1) last = i;
            else return false;
        }
    assert(last != -1);
    if (grave[p ^ 1][last] == 5) {
        return false;
    } else {
        if (hand[p][island] && count(p, hand) >= 2) {
            --hand[p][island];
            ++grave[p][island];
            discard(p);
            return true;
        } else {
            return false;
        }
    }
}

void play_card(int p, int cd) {
    if (counter_attack(p ^ 1)) {
        ++grave[p][cd];
    } else {
        ++field[p][cd];
        if (cd == plain) {
            draw_card(p);
        } else if (cd == swamp) {
            if (!empty(p ^ 1, hand))
                discard(p ^ 1);
        } else if (cd == mountain) {
            if (!empty(p ^ 1, field))
                do_mountain(p);
        } else if (cd == island) { ;
        } else if (cd == forest) {
            if (!empty(p, grave))
                do_forest(p);
        } else {
            assert(0);
        }
    }
}

void main_phase(int p) {
    int card = select_card(p);
    if (card != -1)
        play_card(p, card);
}

void play(int p) {
    queue<int> &dck = deck[p];
    int *hnd = hand[p];

    if (!dck.empty()) {
        int x = dck.front();
        dck.pop();
        ++hnd[x];
    }

    main_phase(p);
}

pii solve() {
    for (int i = 0; i < 5; ++i)
        draw_card(0);
    for (int i = 0; i < 5; ++i)
        draw_card(1);
    for (int i = 1; i <= 100; ++i) {
        int p = !(i & 1);
        play(p);
        if (win(p)) return pii(p, i);
        if (draw()) return pii(-1, i);
    }
    return pii(-1, 100);
}

void clean() {
    while (!deck[0].empty()) deck[0].pop();
    while (!deck[1].empty()) deck[1].pop();
    memset(hand, 0, sizeof hand);
    memset(field, 0, sizeof field);
    memset(grave, 0, sizeof grave);
}

int main() {
    int T, _w;
    _w = scanf("%d", &T);
    for (int kase = 1; kase <= T; ++kase) {
        for (int i = 0; i < 25; ++i) {
            int x;
            _w = scanf("%d", &x);
            deck[0].push(x);
        }
        for (int i = 0; i < 25; ++i) {
            int x;
            _w = scanf("%d", &x);
            deck[1].push(x);
        }
        pii ans = solve();
        printf("Case %d: ", kase);
        if (ans.first == 0) printf("Alice %d\n", ans.second);
        else if (ans.first == 1) printf("Bob %d\n", ans.second);
        else printf("Draw %d\n", ans.second);
        clean();
    }
    return 0;
}