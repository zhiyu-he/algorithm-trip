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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
                if (preorder.size() == 0) return NULL;
        TreeNode* root = new TreeNode(preorder[0]);

        for (int i = 1; i < preorder.size(); i++) {
            TreeNode* tmp = root;
            while(tmp) {
                //cout << "i " << i << " val " << tmp->val << endl;
                if (preorder[i] < tmp->val) {
                    if (tmp->left == NULL) {
                        tmp->left = new TreeNode(preorder[i]);
                        break;
                    } else {
                        tmp = tmp->left;
                    }
                } else {
                    if (tmp->right == NULL) {
                        tmp->right = new TreeNode(preorder[i]);
                        break;
                    } else {
                        tmp = tmp->right;
                    }
                }
            }
        }
        return root;
    }
};

int main() {
    return 0;
}
