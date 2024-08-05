//
// Created by Jiang Yinzuo on 2020/8/8.
//

#include<iostream>
#include<algorithm>

using namespace std;
#define MAX 0x3f3f3f3f
const int maxn = 2e6 + 100;
struct Node {
    int value;
    int day;
}node[maxn];

bool cmp_Node(const Node &a, const Node &b) {
    return a.value < b.value;
}
int b[maxn];
int d[maxn];
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) b[i] = 0;
    int k = 0;
    for (int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        for (int j = 1; j <= num; j++) {
            cin >> node[k].value;
            node[k].day = i;
            k++;
        }
    }
    sort(node, node + k, cmp_Node);
    int l_node = 0, r_node = 0, ci = 0;
    while (1) {
        if (r_node >= k) break;
        if (ci == m) {
            d[l_node] = node[r_node - 1].value - node[l_node].value;
            while (1) {
                int l_day = node[l_node].day;
                b[l_day]--;
                if (b[l_day] == 0) {
                    l_node++; ci--; break;
                }
                else {
                    l_node++;
                    d[l_node]= node[r_node - 1].value - node[l_node].value;
                }
            }
        }
        else {
            int r_day = node[r_node].day;
            if (b[r_day] == 0) ci++;
            b[r_day]++;
            r_node++;
        }
    }
    int d_min = MAX;
    for (int i = 0; i <= l_node - 1; i++) d_min = min(d_min, d[i]);
    cout << d_min << endl;

    return 0;
}