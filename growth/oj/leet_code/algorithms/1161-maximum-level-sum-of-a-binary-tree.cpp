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
    int maxLevelSum(TreeNode* root) {
        if (root == NULL) return 0;
        queue<TreeNode*> q;
        q.push(root);

        int level = 1;
        int max_level = 1;
        int max_value = root->val;
        while(!q.empty()) {
            int size = q.size();
            int level_sum = 0;
            for (int i = 0; i < size; i++) {
                TreeNode* n = q.front();
                q.pop();
                level_sum += n->val;
                if (n->left != NULL) q.push(n->left);
                if (n->right != NULL) q.push(n->right);
            }
            if (level_sum > max_value) {
                max_value = level_sum;
                max_level = level;
            }
            level += 1;
        }
        return max_level;
    }
};
