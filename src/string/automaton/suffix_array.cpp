//
// Created by jiang on 2020/9/22.
//

#include<cstdio>
#include<algorithm>
#include<queue>
#include<iostream>
#include<cmath>
#include<cstring>

static inline int F(int x, int tb) {
    return x / 3 + (x % 3 == 1 ? 0 : tb);
}

static inline int G(int x, int tb) {
    return (x) < tb ? (x) * 3 + 1 : ((x) - tb) * 3 + 2;
}

const int MAXN = 10000 + 100;//n*10
int sa[MAXN], rank[MAXN], height[MAXN], n, r[MAXN], wa[MAXN], wb[MAXN], wv[MAXN], wws[MAXN];
char s[MAXN];

void sort(int *r, const int *a, int *b, int n, int m) {
    int i;
    for (i = 0; i < n; i++) wv[i] = r[a[i]];
    for (i = 0; i < m; i++) wws[i] = 0;
    for (i = 0; i < n; i++) wws[wv[i]]++;
    for (i = 1; i < m; i++) wws[i] += wws[i - 1];
    for (i = n - 1; i >= 0; i--) b[--wws[wv[i]]] = a[i];
}

int c0(int *r, int a, int b) { return r[a] == r[b] && r[a + 1] == r[b + 1] && r[a + 2] == r[b + 2]; }

int c12(int k, int *r, int a, int b) {
    if (k == 2) return r[a] < r[b] || r[a] == r[b] && c12(1, r, a + 1, b + 1);
    else return r[a] < r[b] || r[a] == r[b] && wv[a + 1] < wv[b + 1];
}

void dc3(int *r, int *sa, int n, int m) {
    int i, j, *rn = r + n, *san = sa + n, ta = 0, tb = (n + 1) / 3, tbc = 0, p;
    r[n] = r[n + 1] = 0;
    for (i = 0; i < n; i++) if (i % 3 != 0) wa[tbc++] = i;
    sort(r + 2, wa, wb, tbc, m);
    sort(r + 1, wb, wa, tbc, m);
    sort(r, wa, wb, tbc, m);
    for (p = 1, rn[F(wb[0], tb)] = 0, i = 1; i < tbc; i++)
        rn[F(wb[i], tb)] = c0(r, wb[i - 1], wb[i]) ? p - 1 : p++;
    if (p < tbc) dc3(rn, san, tbc, p);
    else for (i = 0; i < tbc; i++) san[rn[i]] = i;
    for (i = 0; i < tbc; i++) if (san[i] < tb) wb[ta++] = san[i] * 3;
    if (n % 3 == 1) wb[ta++] = n - 1;
    sort(r, wb, wa, ta, m);
    for (i = 0; i < tbc; i++) wv[wb[i] = G(san[i], tb)] = i;
    for (i = 0, j = 0, p = 0; i < ta && j < tbc; p++)
        sa[p] = c12(wb[j] % 3, r, wa[i], wb[j]) ? wa[i++] : wb[j++];
    for (; i < ta; p++) sa[p] = wa[i++];
    for (; j < tbc; p++) sa[p] = wb[j++];
}

void calheight(int *r, int *sa, int n) {
    int i, j, k = 0;
    for (i = 1; i <= n; ++i) rank[sa[i]] = i;
    for (i = 0; i < n; height[rank[i++]] = k)
        for (k ? k-- : 0, j = sa[rank[i] - 1]; r[i + k] == r[j + k]; ++k);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%s", s);
        int Max = -1;
        n = strlen(s);
        for (int i = 0; i < n; i++) {
            r[i] = s[i];
            if (r[i] > Max)Max = r[i];
        }
        r[n] = 0;
        dc3(r, sa, n + 1, Max + 1);
        calheight(r, sa, n);
        for (int i = 0; i <= n; i++)std::cout << sa[i] << " ";
        std::cout << std::endl;
        int sum = 0;
        for (int i = 2; i <= n; i++)sum += height[i];
        printf("%d\n", (1 + n) * n / 2 - sum);
    }
    return 0;
}//C++ 4.3.2编译环境，不同的编译环境可能出错
/*给一个串，数里面不同的子串有多少
测试数据
2
CCCCC
5 4 3 2 1 0
5
ABABA
5 4 2 0 3 1
9
*/