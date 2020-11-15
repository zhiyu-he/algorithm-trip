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
    bool hasPathSum(TreeNode* root, int sum) {
        return visit(root, sum, 0);
    }

    bool visit(TreeNode* node, int target, int cur_sum) {
        if (node == NULL) return false;
        cur_sum += node->val;
        if (node->left == NULL && node->right == NULL && cur_sum == target) return true;
        bool ok1 = visit(node->left, target, cur_sum);
        if (ok1) return ok1;
        bool ok2 = visit(node->right, target, cur_sum);
        if (ok2) return ok2;
        return false;
    }
};

int main() {
    return 0;
}
