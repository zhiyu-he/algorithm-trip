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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return buildTree(nums, 0, nums.size()-1);
    }
    TreeNode* buildTree(vector<int>& nums, int l, int r) {
        if (l > r) return NULL;
        if (l == r) return new TreeNode(nums[l]);
        int max_num = nums[l];
        int max_idx = l;
        for (int i = l; i <= r; i++) {
            if (nums[i] > max_num) {
                max_num = nums[i];
                max_idx = i;
            }
        }
        TreeNode* n = new TreeNode(max_num);
        n->left = buildTree(nums, l, max_idx-1);
        n->right = buildTree(nums, max_idx+1, r);
        return n;
    }
};
