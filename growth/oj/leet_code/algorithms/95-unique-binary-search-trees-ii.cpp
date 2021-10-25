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
    vector<TreeNode*> generateTrees(int n) {
        auto res  = build(1, n);
        return res;
    }
    vector<TreeNode*> build(int start, int end) {
        vector<TreeNode*> res;
        if (start > end) {
            // 后面组合时候需要用到
            res.push_back(NULL);
            return res;
        }
        if (start == end) {
            TreeNode* node = new TreeNode(start);
            res.push_back(node);
            return res;
        }
        for (int i = start; i <= end; i++) {
            vector<TreeNode*> l = build(start, i - 1);
            vector<TreeNode*> r = build(i+1, end);
            
            for (int ii = 0; ii < l.size(); ii++) {
                for (int jj = 0; jj < r.size(); jj++) {
                    TreeNode* root = new TreeNode(i);
                    root->left = l[ii];
                    root->right = r[jj];
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};

int main() {
	return 0;
}
