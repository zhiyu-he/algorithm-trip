#include<iostream>
#include<queue>

using namespace std;
struct TreeNode {
     int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    int max_depth = 0;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL)
            return 0;
        depth(root);
        return max_depth;
    }

    int depth(TreeNode* node) {
        if (node == NULL)
            return 0;
        if (node->left == NULL && node->right == NULL)
            return 1;
        int left = depth(node->left);
        int right = depth(node->right);
        if (left + right > max_depth)
            max_depth = left + right;
        return left > right ? left + 1 : right + 1;
    }
};



int main() {
    return 0;
}
