#include <cstdio>
#include <map>

std::map<int, int> color_map;
int total = 0;
int a[100008];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        if (color_map[a[i]]++ == 0) {total++;}
    }
    int m;
    scanf("%d", &m);
    int k, x;
    int answer = total == 1 ? 0 : -1;
    for (int i = 1; i <= m; ++i) {
        scanf("%d %d", &k, &x);
        if (--color_map[a[k]] == 0) {
            total--;
        }
        if (color_map[x]++ == 0) {
            total++;
        }
        a[k] = x;
        if (answer == -1 && total == 1) {
            answer = i;
        }
    }
    printf("%d\n", answer);
    return 0;
}