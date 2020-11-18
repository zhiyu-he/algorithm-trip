#include<iostream>


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
    bool isEvenOddTree(TreeNode* root) {
        if (root == NULL) return false;
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty()) {
            int size = q.size();
            int last_val = 0;
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (level % 2 == 0) {
                    if (i != 0 && node->val <= last_val) return false;
                    if (node->val % 2 == 0) return false;
                } else {
                    if (i != 0 && node->val >= last_val) return false;
                    if (node->val % 2 == 1) return false;
                }
                last_val = node->val;
                if (node->left != NULL) q.push(node->left);
                if (node->right != NULL) q.push(node->right);
            }
            level += 1;
        }
        return true;
    }
};
