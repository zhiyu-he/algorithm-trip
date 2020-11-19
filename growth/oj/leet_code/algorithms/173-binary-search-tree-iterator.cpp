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
class BSTIterator {
public:
    queue<TreeNode*> q;
    BSTIterator(TreeNode* root) {
        dfs(root);
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* node = q.front();
        q.pop();
        return node->val;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !q.empty();
    }

    void dfs(TreeNode* node) {
        if (node == NULL) return;
        dfs(node->left);
        q.push(node);
        dfs(node->right);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
