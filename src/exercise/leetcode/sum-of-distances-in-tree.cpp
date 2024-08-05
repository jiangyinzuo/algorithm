// Copyright (c) 2021, Jiang Yinzuo. All rights reserved.
#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> tree;
    vector<int> sub_tree_size;
    vector<int> distance_sum;
    vector<int> ans;
    void build_tree(int N, vector<vector<int>> &edges) {
        tree.resize(N);
        for (auto &e : edges) {
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }
    }
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>> &edges) {
        if (N == 1) return {0};
        build_tree(N, edges);
        sub_tree_size.resize(N);
        ans.resize(N);
        distance_sum.resize(N);
        dfs(0, -1);
        dfs2(0, -1);
        return ans;
    }

    void dfs(int cur_node, int father) {
        sub_tree_size[cur_node] = 1;
        distance_sum[cur_node] = 0;
        for (auto &child : tree[cur_node]) {
            if (child != father) {
                dfs(child, cur_node);
                sub_tree_size[cur_node] += sub_tree_size[child];
                distance_sum[cur_node] += distance_sum[child] + sub_tree_size[child];
            }
        }
    }

    void dfs2(int cur_node, int father) {
        if (father != -1) {
            ans[cur_node] = ans[father] + sub_tree_size[0] - 2 * sub_tree_size[cur_node];
        } else {
            ans[cur_node] = distance_sum[cur_node];
        }
        for (auto &child : tree[cur_node]) {
            if (child != father) {
                dfs2(child, cur_node);
            }
        }
    }
};

int main(){
    int N = 6;
    vector<vector<int>> edges = {{0,1},{0,2},{2,3},{2,4},{2,5}};
    Solution s;
    vector<int> res = s.sumOfDistancesInTree(N, edges);
    for (auto i : s.sub_tree_size) {
        cout << i << " ";
    }
    cout << "\n";
    printf("%d\n", res.size());
    for (auto i : s.ans) {
        cout << i << " ";
    }
    cout << '\n';
    return 0;
}