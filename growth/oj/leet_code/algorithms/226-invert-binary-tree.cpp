#include<iostream>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
 		if (root == NULL) {
			return NULL;
		}
		TreeNode* tmp = root->left;
		root->left = root->right;
		root->right = tmp;
		invertTree(root->left);
		invertTree(root->right);
		return root;
    }
};

void printTree(TreeNode* root) {
	if(root == NULL) return;
	std::cout << root->val << std::endl;
    /*
	if(root->left != NULL) {
		std::cout << root->left->val << std::endl;
	}
	if(root->right != NULL) {
		std::cout << root->right->val << std::endl;
	}
    */
	printTree(root->left);
	printTree(root->right);
}


int main() {
	TreeNode root(4);
    auto node1 = TreeNode(2);
	root.left = &node1;
    auto node2 = TreeNode(7);
	root.right = &node2;

    auto node3 = TreeNode(1);
	root.left->left = &node3;
    auto node4 = TreeNode(3);
	root.left->right = &node4;
	
    auto node5 = TreeNode(6);
	root.right->left = &node5;
    auto node6 = TreeNode(9);
	root.right->right = &node6;

	Solution solution;
	auto p = solution.invertTree(&root);
	
	printTree(p);
	return 0;
}
