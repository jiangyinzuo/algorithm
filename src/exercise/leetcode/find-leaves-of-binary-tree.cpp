// Copyright (c) 2021, Jiang Yinzuo. All rights reserved.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> findLeaves(TreeNode *root) {
        vector <vector<int>> res;
        this->dfs(root, res);
        return res;
    }
    int dfs(TreeNode *cur_node, vector<vector<int>> &res) {
        if (cur_node == nullptr) {
            return 0;
        }

        int a = dfs(cur_node->left, res);
        int b = dfs(cur_node->right, res);
        int idx = std::max(a, b);
        if (res.size() < idx + 1) {
            res.emplace_back();
        }
        res[idx].push_back(cur_node->val);
        return idx + 1;
    }
};
