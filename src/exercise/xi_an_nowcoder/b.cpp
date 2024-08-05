//
// Created by jiang on 2020/5/23.
//

#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
std::map<int, int> graph;
std::vector<std::string> name;
std::map<int, std::vector<int>> to_map;

std::vector<int> answer;

void init() {
    graph.clear();
    to_map.clear();
    name.clear();
    answer.clear();
}

void solve(int n, int kase) {
    std::priority_queue<int, vector<int>, greater<> > name_queue;
    int selected_cnt = 0;
    std::vector<int> selected_q[2];
    for (int i = 0; i < n; ++i) {
        if (graph[i] == 0) {
            name_queue.push(i);
            ++selected_cnt;
            for (auto &j : to_map[i]) {
                if(--graph[j] == 0) {
                    selected_q[0].push_back(j);
                }
            }
        }
    }
    if (name_queue.empty()) {
        std::cout << "Case #" << kase << ":\n";
        std::cout << "Impossible\n";
        return;
    } else {
        while (!name_queue.empty()) {
            answer.push_back(name_queue.top());
            name_queue.pop();
        }
    }
    int turn = 0;
    while (selected_cnt < n) {
        for (auto &i : selected_q[turn]) {
            if (graph[i] == 0) {
                name_queue.push(i);
                ++selected_cnt;
                for (auto &j : to_map[i]) {
                    if (--graph[j] == 0)
                        selected_q[turn ^ 1].push_back(j);
                }
            }
        }
        selected_q[turn].clear();
        turn ^= 1;
        if (name_queue.empty()) {
            std::cout << "Case #" << kase << ":\n";
            std::cout << "Impossible\n";
            return;
        } else {
            while (!name_queue.empty()) {
                answer.push_back(name_queue.top());
                name_queue.pop();
            }
        }
    }
    std::cout << "Case #" << kase << ":\n";
    for (auto &i : answer) {
        std::cout << name[i] << '\n';
    }
}


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    std::string from, to, temp;
    int from_id, to_id;
    for (int kase = 1; kase <= t; ++kase) {
        init();
        int n, m;
        std::cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            std::cin >> temp;
            name.push_back(temp);
        }

        std::sort(name.begin(), name.end());

        for (int i = 0; i < m; ++i) {
            std::cin >> from >> to;
            from_id = std::lower_bound(name.begin(), name.end(), from) - name.begin();
            to_id = std::lower_bound(name.begin(), name.end(), to) - name.begin();
            graph[to_id]++;
            to_map[from_id].push_back(to_id);
        }
        solve(n, kase);
    }
    return 0;
}