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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root = NULL;
        root = build(root, preorder, 0, inorder, 0, inorder.size()-1);
        return root;
    }


    TreeNode* build(TreeNode* node, vector<int>& preorder, int root_idx, vector<int>& inorder, int l2, int r2) {
        if (l2 > r2) return NULL;
        node = new TreeNode(preorder[root_idx]);
        if (l2 == r2) return node;
        int split_inorder_tree = -1;
        for (int i = l2; i <= r2; i++) {
            if (inorder[i] == preorder[root_idx]) {
                split_inorder_tree = i;
                break;
            }
        }
        int left_size = split_inorder_tree - l2;
        int right_size = r2 - split_inorder_tree;

        // left-tree exist, handle [root_idx+1], in-order-range [l2, split_inorder_tree-1]
        if (left_size > 0) {
            node->left = build(node->left, preorder, root_idx + 1, inorder, l2, split_inorder_tree-1);
        }
        
        if (right_size > 0) {
            node->right = build(node->right, preorder, root_idx + left_size+1, inorder, split_inorder_tree+1, r2);
        }
        return node;
    }
};
