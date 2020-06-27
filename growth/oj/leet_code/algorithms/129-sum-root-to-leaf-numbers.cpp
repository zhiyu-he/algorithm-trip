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
    int sumNumbers(TreeNode* root) {
        if (root == NULL) return 0;
        int res = 0;
        dfs(root, res, 0);
        return res;
    }

    void dfs(TreeNode* node, int& res, int path_sum) {
        if (node->left == NULL && node->right == NULL) {
            res += path_sum * 10 + node->val;
            return;
        }
        if (node->left != NULL) {
            dfs(node->left, res, path_sum * 10 + node->val);
        }
        if (node->right != NULL) {
            dfs(node->right, res, path_sum * 10 + node->val);
        }

        return;
    }
};

int main() {
    return 0;
}
