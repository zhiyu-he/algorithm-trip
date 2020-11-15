#include<iostream>

using namespace std;

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
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        // because root-to-leaf, so use preorder [root, left, right]
        vector<int> path;
        visit(root, sum, 0, path, res);
        return res;
    }
    void visit(TreeNode* node, int target, int cur_sum, vector<int>& path, vector<vector<int>>& res) {
        if (node == NULL) return;
        cur_sum += node->val;

        path.push_back(node->val);
        if (node->left == NULL && node->right == NULL && cur_sum == target) {

            res.push_back(path);
        }
        visit(node->left, target, cur_sum, path, res);

        visit(node->right, target, cur_sum, path, res);
        path.pop_back();
    }
};


int main() {
    return 0;
}
