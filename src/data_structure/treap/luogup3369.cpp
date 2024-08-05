// Copyright (c) 2021, Jiang Yinzuo. All rights reserved.

#include<bits/stdc++.h>
using namespace std;

const int INF = 1000000007;
template<const int MAXN = 100009>
class Treap {
    int size[MAXN]{0}, value[MAXN]{0}, node_count[MAXN]{0}, rand_priority[MAXN]{0}, son[MAXN][2]{0};

    void calc_size(int root) {
        size[root] = size[son[root][0]] + size[son[root][1]] + node_count[root];
    }

    void rotate(int &root, int direction) {
        int new_root = son[root][direction ^ 1];
        son[root][direction ^ 1] = son[new_root][direction];
        son[new_root][direction] = root;
        calc_size(root);
        calc_size(new_root);
        root = new_root;
    }

    void _insert(int cur_node, int v) {
		if (value[cur_node] == v) {
			node_count[cur_node]++;
			size[cur_node]++;
			return;
		}
    }

public:
	void insert(int v) {
    	if (size[0] == 0) {
    		++size[0];
    		++node_count[0];
    		value[0] = v;
    		rand_priority[0] = rand();
    		return;
    	}
    	_insert(0, v);
    }
};

const int MAXN = 1e5 + 10;
int sz, rt;
int siz[MAXN], key[MAXN], cnt[MAXN], rd[MAXN], son[MAXN][2];
inline void push_up(int x) {
    siz[x] = siz[son[x][0]] + siz[son[x][1]] + cnt[x];
}
void rotate(int &x, int y) {
    int ii = son[x][y ^ 1];
    son[x][y ^ 1] = son[ii][y];
    son[ii][y] = x;
    push_up(x);
    push_up(ii);
    x = ii;
}
void ins(int &p, int x) {
    if (!p) {
        p = ++sz;
        siz[p] = cnt[p] = 1;
        key[p] = x;
        rd[p] = rand();
        return;
    }
    if (key[p] == x) {
        cnt[p]++;
        siz[p]++;
        return;
    }
    int d = (x > key[p]);
    ins(son[p][d], x);
    if (rd[p] < rd[son[p][d]])
        rotate(p, d ^ 1);
    push_up(p);
}
void del(int &p, int x) {
    if (!p)
        return;
    if (x != key[p])
        del(son[p][x > key[p]], x);
    else {
        if (!son[p][0] && !son[p][1]) {
            cnt[p]--;
            siz[p]--;
            if (cnt[p] == 0)
                p = 0;
        } else if (son[p][0] && !son[p][1]) {
            rotate(p, 1);
            del(son[p][1], x);
        } else if (!son[p][0] && son[p][1]) {
            rotate(p, 0);
            del(son[p][0], x);
        } else {
            int d = rd[son[p][0]] > rd[son[p][1]];
            rotate(p, d);
            del(son[p][d], x);
        }
    }
    push_up(p);
}
int get_rank(int p, int x) {
    if (!p)
        return 0;
    if (key[p] == x)
        return siz[son[p][0]] + 1;
    if (key[p] < x)
        return siz[son[p][0]] + cnt[p] + get_rank(son[p][1], x);
    /*if(key[p]>x)*/
    return get_rank(son[p][0], x);
}
int find(int p, int x) {
    if (!p)
        return 0;
    if (siz[son[p][0]] >= x)
        return find(son[p][0], x);
    else if (siz[son[p][0]] + cnt[p] < x)
        return find(son[p][1], x - cnt[p] - siz[son[p][0]]);
    else
        return key[p];
}
int pre(int p, int x) {
    if (!p)
        return -INF;
    if (key[p] >= x)
        return pre(son[p][0], x);
    else
        return max(key[p], pre(son[p][1], x));
}
int suf(int p, int x) {
    if (!p)
        return INF;
    if (key[p] <= x)
        return suf(son[p][1], x);
    else
        return min(key[p], suf(son[p][0], x));
}
int Q;
int main() {
    scanf("%d", &Q);
    while (Q--) {
        int ii, jj;
        scanf("%d%d", &ii, &jj);
        switch (ii) {
        case 1: {
            ins(rt, jj);
            break;
        }
        case 2: {
            del(rt, jj);
            break;
        }
        case 3: {
            printf("%d\n", get_rank(rt, jj));
            break;
        }
        case 4: {
            printf("%d\n", find(rt, jj));
            break;
        }
        case 5: {
            printf("%d\n", pre(rt, jj));
            break;
        }
        case 6: {
            printf("%d\n", suf(rt, jj));
            break;
        }
        }
    }
    return 0;
}
