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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == NULL) return new TreeNode(val);
        TreeNode* iter = root;
        while(iter) {
            if (iter->val > val) {
                bool is_nul = iter->left == NULL;
                if (iter->left == NULL) {
                    iter->left = new TreeNode(val);
                    return root;
                }
                iter = iter->left;
            }
            if (iter->val < val) {
                if (iter->right == NULL) {
                    iter->right = new TreeNode(val);
                    return root;
                }
                iter = iter->right;
            }
        }
        return root;
    }
};

int main() {
    return 0;
}
