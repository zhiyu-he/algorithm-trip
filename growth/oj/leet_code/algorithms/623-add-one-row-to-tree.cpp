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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (root == NULL) return NULL;
        if (d == 1) {
            TreeNode* res = new TreeNode(v);
            res->left = root;
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        int depth = 1;
        while(!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                TreeNode* l = node->left;
                TreeNode* r = node->right;
                if (depth + 1 == d) {
                    node->left = new TreeNode(v);
                    node->right = new TreeNode(v);
                    if (l != NULL) node->left->left = l;
                    if (r != NULL) node->right->right = r;
                }
                if (l != NULL) q.push(l);
                if (r != NULL) q.push(r);
            }
            depth += 1;
        }
        return root;
    }
};

int main() {return 0;}
