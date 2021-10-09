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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> cache;

        vector<TreeNode*> res;
        helper(root, cache, res);
        return res;
    }
    string helper(TreeNode* node, unordered_map<string, int>& cache, vector<TreeNode*>& res) {
        if (node == NULL) return "#";
        string str = to_string(node->val) + "," + helper(node->left, cache, res) + "," + helper(node->right, cache, res);
        cache[str] += 1;
        if (cache[str] == 2) {
            res.push_back(node);
        }
        return str;
    }
};
