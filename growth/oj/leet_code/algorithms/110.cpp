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
    bool global = true;
    
    bool isBalanced(TreeNode* root) {
        is_ok(root);
        return global;
    }
    
    int is_ok(TreeNode* root) {
        if (root == NULL) return 0;
        if (!global) return -1;
        int left_height = is_ok(root->left);
        int right_height = is_ok(root->right);
    
        if (abs(left_height - right_height) > 1) {
            global = false;
            return -1;
        }
        return max(left_height, right_height) + 1;
    }
};
