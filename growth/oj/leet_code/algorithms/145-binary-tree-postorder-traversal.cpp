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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        visit(root, res);
        return res;
    }

    void visit(TreeNode* node, vector<int>& res) {
        if (node == NULL) return;
        visit(node->left, res);
        visit(node->right, res);
        res.push_back(node->val);
        return;
    }
};

int main() {
    return 0;
}
