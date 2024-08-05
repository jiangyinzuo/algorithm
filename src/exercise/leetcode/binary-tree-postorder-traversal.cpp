// Copyright (c) 2021, Jiang Yinzuo. All rights reserved.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <vector>
class Solution {
public:
    std::vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> res;
        dfs(res, root);
        return res;
    }

    void dfs(std::vector<int> &res, TreeNode *cur_node) {
        if (cur_node == nullptr) {
            return;
        }
        dfs(res, cur_node->left);
        dfs(res, cur_node->right);
        res.push_back(cur_node->val);
    }
};