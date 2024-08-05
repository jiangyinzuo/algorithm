//
// Created by jiang on 2020/8/15.
//

#include <cstdio>
#include <unordered_map>

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    std::unordered_map<int, int> parents;
    int op, num;
    for (int i = 0; i < q; ++i) {
        scanf("%d %d", &op, &num);
        if (op == 2) {
            while (parents[num] > 0) {
                num = parents[num];
            }
            printf("%d\n", num);
        } else {
            parents[num] = num + 1;
        }
    }
    return 0;
}