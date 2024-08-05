//
// Created by Jiang Yinzuo on 2021/3/16.
//
#include <vector>

using namespace std;
class Solution {
public:
	bool ans = true;
	bool validTree(int n, vector<vector<int>>& edges) {
		vector<vector<int>> tree(n+1, vector<int>());
		for (auto &edge : edges) {
			tree[edge[0]].push_back(edge[1]);
			tree[edge[1]].push_back(edge[0]);
		}
		vector<bool> visited(n + 1, false);
		dfs(0, -1, tree, visited);
		for (int i = 0; i < n; ++i) {
			if (!visited[i]) return false;
		}
		return ans;
	}

	void dfs(int cur_node, int father, vector<vector<int>> &tree, vector<bool> &visited) {
		if (!ans || visited[cur_node]) {
			ans = false;
			return;
		}
		visited[cur_node] = true;
		for (auto child : tree[cur_node]) {
			if (child != father) {
				dfs(child, cur_node, tree, visited);
			}
		}
	}
};