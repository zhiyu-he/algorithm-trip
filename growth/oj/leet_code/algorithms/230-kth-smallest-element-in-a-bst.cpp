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
    int kthSmallest(TreeNode* root, int k) {
        int res = 0;
        int counter = 0;
        visit(root, k, counter, res);
        return res;
    }
    void visit(TreeNode* node, int k, int& i, int& res) {
        if (node == NULL || i > k)
            return;
        visit(node->left, k, i, res);
        i += 1;
        if (i == k) {
            res = node->val;
            return;
        }
        //cout << node->val << endl;
        visit(node->right, k, i, res);
    }
};
