#include<iostream>

using namespace std;

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) return NULL;
        if (root->val == key) {
            if (root->left == NULL) return root->right; // 左子树为空, 返回右子树最小的
            if (root->right == NULL) return root->left; // 右子树为空，返回左子树最大的
            TreeNode* minNode = getMin(root->right);
            root->val = minNode->val;
            root->right = deleteNode(root->right, minNode->val);
            return root;
        } else if (root->val > key) {
            root->left = deleteNode(root->left, key);
        } else {
            root->right = deleteNode(root->right, key);
        }

        return root;
    }

    TreeNode* getMin(TreeNode* node) {
        if (node->left == NULL && node->right == NULL) return node;
        if (node->left) {
            return getMin(node->left);
        }
        return node;
    }
};

int main() {
    return 0;
}
