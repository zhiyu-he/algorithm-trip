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
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        bool ans = dfs(root, arr, 0, root->left == NULL && root->right == NULL);
        return ans;
    }

    bool dfs(TreeNode* node, vector<int>& arr, int idx, bool is_leaf) {
        if (node == NULL && idx < arr.size()) return false;
        if (idx == arr.size()) {
            return is_leaf;
        }
        if (arr[idx] != node->val) return false;
        bool left_ok = dfs(node->left, arr, idx+1, node->left == NULL && node->right == NULL);
        if (left_ok) return true;

        bool right_ok = dfs(node->right, arr, idx+1, node->left == NULL && node->right == NULL);
        if (right_ok) return true;
        return false;
    }
};


int main() {
    return 0;
}
