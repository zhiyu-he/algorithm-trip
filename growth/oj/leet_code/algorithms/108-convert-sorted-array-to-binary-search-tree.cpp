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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0) return NULL;
        if (nums.size() == 1) return new TreeNode(nums[0]);
        return build(nums, 0, nums.size()-1);
    }
    TreeNode* build(vector<int>& nums, int left, int right) {
        if (left > right) return NULL;
        if (left == right) {
            return new TreeNode(nums[left]);
        }
        int mid = (right - left) / 2 + left;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = build(nums, left, mid-1);
        root->right = build(nums, mid + 1, right);
        return root;
    }
};

int main() {}
