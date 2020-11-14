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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        // pre [root, left, right]
        // pos [left, right, root]
        TreeNode* root = build(pre, 0, post, 0, post.size()-1);
        return root;
    }
    TreeNode* build(vector<int>& pre, int rootIdx, vector<int>& post, int l, int r) {
        //cout << "root_idx: " << rootIdx << " [ " << l << " " << r << " ]" << endl;
        if (l > r) return NULL;
        TreeNode* node = new TreeNode(pre[rootIdx]);
        if (l == r) return node;

        int seek_split_pos = -1;
        for (int i = l; i <= r; i++) {
            if (post[i] == pre[rootIdx+1]) {
                seek_split_pos = i;
                break;
            }
        }

        int left_size = seek_split_pos - l;
        int right_size = r - seek_split_pos;
        //cout << "left_size " << left_size << " right_size " << right_size << endl;
        if (left_size >= 0) {
            //cout << "build left root " << rootIdx + 1 << " [ " << l << " " << seek_split_pos << " ]" << endl;
            node->left = build(pre, rootIdx+1, post, l, seek_split_pos);
        }
        if (right_size > 0) {
            //cout << "build right root " << rootIdx + 1 + left_size+1 << " [ " << seek_split_pos+1 << " " << r-1 << " ]" << endl;
            node->right = build(pre, rootIdx+1+left_size+1, post, seek_split_pos+1, r-1);
        }
        return node;
    }
};
