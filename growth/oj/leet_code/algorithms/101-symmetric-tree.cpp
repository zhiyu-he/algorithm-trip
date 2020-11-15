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
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        return cmp(root->left, root->right);
    }
    bool cmp(TreeNode* left, TreeNode* right) {
        if (left == NULL && right != NULL) return false;
        if (left != NULL && right == NULL) return false;
        if (left == NULL && right == NULL) return true;
        if (left->val != right->val) return false;
        bool ok1 = cmp(left->right, right->left);
        bool ok2 = cmp(left->left, right->right);
        return ok1 && ok2;
    }
};

int main() {
    return 0;
}
