#include<cstdio>
#include<algorithm>

using namespace std;

typedef struct {
    int from;
    int to;
    int dis;
} Edge;
Edge e[5555];
int father[109];

bool cmp(Edge &e1, Edge &e2) {
    return e1.dis < e2.dis;
}

int getRoot(int x) {
    if (father[x] == x) return x;
    else return getRoot(father[x]);
}

void unionNode(int x, int y) {
    father[y] = getRoot(x);
}

void kruskal(int n) {
    sort(e + 1, e + 1 + n * (n - 1) / 2, cmp);
    int len = 0;
    int r1, r2;
    int k = 0;
    for (int i = 1; i <= n * (n - 1) / 2 && k != n - 1; ++i) {
        r1 = getRoot(e[i].from);
        r2 = getRoot(e[i].to);
        if (r1 != r2) {
            unionNode(r1, r2);
            len += e[i].dis;
            ++k;
        }
    }
    if (k == n - 1) {
        printf("%d\n", len);
    }
}

int main() {
    int n;
    while (scanf("%d", &n) && n) {
        for (int i = 1; i <= n * (n - 1) / 2; ++i) {
            scanf("%d %d %d", &e[i].from, &e[i].to, &e[i].dis);
        }
        for (int i = 1; i <= n; ++i) father[i] = i;
        kruskal(n);
    }
    return 0;
}