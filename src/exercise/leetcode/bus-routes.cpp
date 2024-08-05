#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numBusesToDestination(vector<vector<int>> &routes, int source, int target) {
        if (source == target) return 0;
        unordered_map<int, unordered_set<int>> station_routes;
        int i = 0;
        for (auto &r : routes) {
            for (auto &s : r) {
                station_routes[s].insert(i);
            }
            i++;
        }
        std::vector<std::unordered_set<int>> graph(routes.size());
        for (auto &s : station_routes) {
            for (auto &i : s.second) {
                for (auto &j : s.second) {
                    if (i != j) {
                        graph[i].insert(j);
                        graph[j].insert(i);
                    }
                }
            }
        }

        std::vector<bool> visited(routes.size());
        std::queue<std::pair<int, int>> q;
        for (auto &r : station_routes[source]) {
            visited[r] = true;
            q.push({r, 1});
        }
        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            if (station_routes[target].find(front.first) != station_routes[target].end()) {
                return front.second;
            }
            for (auto v: graph[front.first]) {
                if (!visited[v]) {
                    visited[v] = true;
                    q.push({v, front.second + 1});
                }
            }
        }
        return -1;
    }
};