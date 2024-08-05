//
// Created by Jiang Yinzuo on 2020/5/16.
//


#include <vector>
#include <set>
#include <map>
#include <cstdio>

#define PII pair<int, int>

using namespace std;

int f[200010];

int find(int x) {
    return f[x] == x ? x : f[x] = find(f[x]);
}

bool add(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx != fy) {
        f[fx] = fy;
        return true;
    }
    return false;
}

int main() {
    int n;
    scanf("%d", &n);
    map<int, vector<int>> m;
    for (int i = 1; i <= n; i++) {
        f[i] = i;
        int j, k;
        scanf("%d", &j);
        while (j--) {
            scanf("%d", &k);
            m[k].push_back(i);
        }
    }
    vector<pair<PII, int>> ans;
    for (auto i : m) {
        for (int j = 1; j < i.second.size(); j++)
            if (add(i.second[j - 1], i.second[j]))
                ans.push_back({{i.second[j - 1], i.second[j]}, i.first});
    }
    if (ans.size() != n - 1)
        printf("impossible\n");
    else
        for (auto i : ans)
            printf("%d %d %d\n", i.first.first, i.first.second, i.second);
    return 0;
}