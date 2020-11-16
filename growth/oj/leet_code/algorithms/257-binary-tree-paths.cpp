#include<iostream>


using namepsace std;

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
    vector<string> binaryTreePaths(TreeNode* root) {

        vector<vector<int>> res;
        vector<int> path;
        visit(root, res, path);
        vector<string> ans;
        for(auto path : res) {
            stringstream ss;
            for (int i = 0; i < path.size(); i++) {
                ss << path[i];
                if (i != path.size()-1) {
                    ss << "->";
                }
            }
            string str;
            ss >> str;
            ans.push_back(str);
        }
        return ans;
    }
    void visit(TreeNode* node, vector<vector<int>>& res, vector<int>& path) {
        if (node == NULL) return;
        path.push_back(node->val);
        if (node->left == NULL && node->right == NULL) {
            res.push_back(path);
        }
        visit(node->left, res, path);
        visit(node->right, res, path);
        path.pop_back();
    }
};

int main() {
    return 0;
}
