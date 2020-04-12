#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        visit_dfs(root, v);
        return v;
    }

    void visit_dfs(TreeNode* root, vector<int>& v) {
        if (root == NULL)
            return;
        v.push_back(root->val);
        visit(root->left, v);
        visit(root->right, v);
        return;
    }

    void visit_bfs(TreeNode* root, vector<int>& v) {
        return;
    }
};

int main() {
    return 0;
}
