#include<iostream>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL) {
            return true;
        }
        if (p == NULL || q == NULL) {
            return false;
        }
        if (p->val != q->val) {
            return false;
        }
        bool left_same = isSameTree(p->left, q->left);
        if (!left_same) {
            return false;
        }
        bool right_same = isSameTree(p->right, q->right);
        return right_same;
    }
};


int main() {
    Solution obj;
	auto a = obj.isSameTree(NULL, NULL);
	std::cout << a << std::endl;
}
