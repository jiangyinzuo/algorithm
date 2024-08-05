#include <stdio.h>

int pre[1011];
int res;

void init()
{
    for (int i = 0; i < 1005; ++i) {
        pre[i] = i;
    }
}

int find_root(int v)
{
    if (pre[v] == v) {
        return v;
    }
    pre[v] = find_root(pre[v]);
    return pre[v];
}

void union_element(int v1, int v2)
{
    int r1 = find_root(v1);
    int r2 = find_root(v2);
    if (r1 != r2) {
        pre[r1] = r2;
        --res;
    }
}

int main()
{
    int n, m;
    int v1, v2;
    while (scanf("%d", &n)) {
        if (n == 0) {
            break;
        }
        scanf("%d", &m);
        init();
        
        res = n - 1;
        for (int i = 0; i < m; ++i) {
            scanf("%d %d", &v1, &v2);
            union_element(v1, v2);
        }
        printf("%d\n", res);
    }
    return 0;
}