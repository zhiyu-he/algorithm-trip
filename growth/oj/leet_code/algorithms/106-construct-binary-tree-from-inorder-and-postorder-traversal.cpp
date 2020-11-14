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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode* root = build(postorder, postorder.size()-1, inorder, 0, inorder.size()-1);
        return root;
    }
    TreeNode* build(vector<int>& postorder, int rootIdx, vector<int>& inorder, int l, int r) {
        if (l > r) return NULL;
        TreeNode* node = new TreeNode(postorder[rootIdx]);
        if (l == r) return node;
        int seek_inorder_pos = -1;
        for (int i = l; i <= r; i++) {
            if (inorder[i] == postorder[rootIdx]) {
                seek_inorder_pos = i;
                break;
            }
        }
        int left_size = seek_inorder_pos - l;
        int right_size = r - seek_inorder_pos;

        if (left_size > 0) {
            node->left = build(postorder, rootIdx-right_size-1, inorder, l, seek_inorder_pos-1);
        }
        if (right_size > 0) {
            node->right = build(postorder, rootIdx - 1, inorder, seek_inorder_pos+1, r);
        }
        return node;
    }
};
