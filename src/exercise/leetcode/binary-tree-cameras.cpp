//
// Created by Jiang Yinzuo on 2021/3/18.
//

#include <cstdio>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;

	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	// father has no camera; father has camera
	vector<pair<int, int>> dp;
	int cur_id = 0;

	int minCameraCover(TreeNode *root) {
		if (root == nullptr || root->left == nullptr && root->right == nullptr) return 1;
		dp.resize(1000, {0, 0});

		dfs_id(root);
		dfs(root);
		return min(dp[root->val].first, dp[root->val].second);
	}

	void dfs_id(TreeNode *cur_node) {
		if (cur_node) {
			cur_node->val = ++cur_id;
			dfs_id(cur_node->left);
			dfs_id(cur_node->right);
		}
	}

	void dfs(TreeNode *cur_node) {
		if (cur_node == nullptr) {
			return;
		}

		dfs(cur_node->left);
		dfs(cur_node->right);
		dp[cur_node->val].first = min(min(get_dp_first(cur_node->left) + get_dp_second(cur_node->right),
										  get_dp_first(cur_node->right) + get_dp_second(cur_node->left)),
									  get_dp_second(cur_node->left) + get_dp_second(cur_node->right));
		dp[cur_node->val].second = get_dp_first(cur_node->left)
	}

	int get_dp_first(TreeNode *cur_node) {
		if (cur_node) {
			return dp[cur_node->val].first;
		}
		return 0;
	}

	int get_dp_second(TreeNode *cur_node) {
		if (cur_node) {
			return dp[cur_node->val].second;
		}
		return 0;
	}
};