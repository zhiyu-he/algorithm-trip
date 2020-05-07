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
    bool isCousins(TreeNode* root, int x, int y) {
        int p1 = 0;
        int p2 = 0;
        int d1 = visit(root, p1, x, 0);
        int d2 = visit(root, p2, y, 0);
        return d1 == d2 && p1 != p2;

    }
    int visit(TreeNode* node, int& parent, int target, int depth) {
        if (node == NULL) {
            return -1;
        }
        if (node->val == target) {
            return depth;
        }
        parent = node->val;
        int left = visit(node->left, parent, target, depth+1);
        if (left >= 0) {
            return left;
        }
        parent = node->val;
        int right = visit(node->right, parent, target, depth+1);
        if (right >= 0) {
            return right;
        }
        return -1;
    }
};

int main() {
    return 0;
}
