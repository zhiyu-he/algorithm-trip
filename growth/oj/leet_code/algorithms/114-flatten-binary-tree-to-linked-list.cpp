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
    void flatten(TreeNode* root) {
        flat(root);
    }

    TreeNode* flat(TreeNode* node) {
        if (node == NULL) return NULL;
        if (node->left == NULL && node->right == NULL) return node;

        TreeNode* r_last = flat(node->right);
        TreeNode* l_last = flat(node->left);

        TreeNode* tmp = node->right;
        if (node->left != NULL) {
            node->right = node->left;
            if (l_last != NULL) {
                l_last->right = tmp;
            } else {
                node->right->right = tmp;
            }
            node->left = NULL;
        }
        return r_last == NULL ? (l_last == NULL ? node->right: l_last) : r_last;
    }
};

int main() {
    return 0;
}
