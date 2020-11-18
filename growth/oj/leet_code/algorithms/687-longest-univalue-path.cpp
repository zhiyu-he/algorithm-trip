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
    int longestUnivaluePath(TreeNode* root) {
        if (root == NULL) return 0;
        int res = 0;
        counter(root, res);
        return res;
    }
    int counter(TreeNode* node, int& res) {
        if (node == NULL) return 0;
        int left = 0, right = 0;
        left = counter(node->left, res);
        right = counter(node->right, res);
        int l = 0, r = 0;
        if (node->left != NULL && node->left->val == node->val) {
            l = left + 1;
        }
        if (node->right != NULL && node->right->val == node->val) {
            r = right + 1;
        }
        if (node->left != NULL && node->right != NULL &&  l > 0 && r > 0) {
            res = max(res, l + r);
        }
        res = max(res, max(l, r));
        return max(l, r);
    }
};

int main() {
    return 0;
}
