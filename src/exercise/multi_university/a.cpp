//
// Created by Jiang Yinzuo on 2020/8/10.
//

#include <cstdio>
#include <vector>
#include <cassert>

bool visited[1000008];

bool solve(int p, int cur_num) {
    for (int i = 0; i <= p; ++i) {
        visited[i] = false;
    }
    std::vector<int> answer;
    visited[cur_num] = true;
    answer.push_back(cur_num);
    while (answer.size() < p - 1) {
        if (!visited[cur_num * 2 % p]) {
            cur_num = cur_num * 2 % p;
        } else if (!visited[cur_num * 3 % p]) {
            cur_num = cur_num * 3 % p;
        } else {
            return false;
        }
        visited[cur_num] = true;
        answer.push_back(cur_num);
    }
    for (auto &i : answer) {
        printf("%d ", i);
    }
    putchar('\n');
    return true;
}


int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int p;
        scanf("%d", &p);

        if (!solve(p, 1))
            if (!solve(p, 2))
                if (!solve(p, 3)) {
                    puts("-1");
                }
    }
    return 0;
}