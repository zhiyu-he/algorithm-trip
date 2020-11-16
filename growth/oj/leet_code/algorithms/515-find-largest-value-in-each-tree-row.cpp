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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if (root == NULL) return res;

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();

            int max_val = 0;
            for (int i = 0; i < size; i++) {
                TreeNode* n = q.front();
                q.pop();
                if (i == 0) max_val = n->val;
                max_val = max(max_val, n->val);
                if (n->left != NULL) q.push(n->left);
                if (n->right != NULL) q.push(n->right);
            }
            res.push_back(max_val);
        }
        return res;
    }
};


int main() {
    return 0;
}
