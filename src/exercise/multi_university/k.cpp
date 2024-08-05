#include<algorithm>
#include<iostream>

using namespace std;
const int maxn = 2e6 + 100;
long long n, k;
int a[maxn], v[maxn];//a用来存序列  v用来记录序列中1的位置

int bfs_l(int l, int r, int l_num, int r_num);
int bfs_r(int l, int r, int l_num, int r_num);

int bfs_l(int l, int r, int l_num, int r_num) {
    if (l - 1 < 0) {
        if (r + 1 <= n - 1 && a[r + 1] == max(l_num, r_num) + 1) return bfs_r(l, r, l_num, r_num);
        return l_num;
    }
    if (a[l - 1] == max(l_num, r_num) + 1) {
        return bfs_l(l - 1, r, max(l_num, r_num) + 1, r_num);
    } else {
        if (a[r + 1] == max(l_num, r_num) + 1) {
            int rr = bfs_r(l, r, l_num, r_num);
            if (a[l - 1] <= rr + 1) {
                return bfs_l(l - 1, r, rr, rr);
            }
        }
    }
    return l_num;
}

int bfs_r(int l, int r, int l_num, int r_num) {
    if (r + 1 > n - 1) {
        if (l - 1 >= 0 && a[l - 1] == max(l_num, r_num) + 1) return bfs_l(l, r, l_num, r_num);
        return r_num;
    }
    if (a[r + 1] == max(l_num, r_num) + 1) {
        return bfs_r(l, r + 1, l_num, max(l_num, r_num) + 1);
    } else {
        if (a[l - 1] == max(l_num, r_num) + 1) {
            int ll = bfs_l(l, r, l_num, r_num);
            if (a[r + 1] <= ll + 1) {
                return bfs_r(l - 1, r, ll, ll);
            }
        }
    }
    return r_num;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        long long ci = 0;
        for (int i = 0; i <= n - 1; i++) {
            cin >> a[i];
            if (a[i] == 1) {
                v[ci] = i;
                ci++;
            }
        }
        int max_k = 0;//记录最大的k
        for (int i = 0; i <= ci - 1; i++) {
            int u = v[i];

        }
        if (max_k != k) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }

    return 0;
}