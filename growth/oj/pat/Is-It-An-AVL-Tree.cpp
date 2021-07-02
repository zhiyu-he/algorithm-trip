#include<iostream>

using namespace std;

const int N = 35;

int input[N];

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

int dfs(TreeNode* node, bool& is_ok) {
    if (node == NULL) return 0;
    if (!is_ok) return -1;
    int left_h = dfs(node->left, is_ok);
    int right_h = dfs(node->right, is_ok);
    
    if (abs(left_h - right_h) > 1) {
        is_ok = false;
        return -1;
    }
    
    return 1 + max(left_h, right_h);
}

TreeNode* build(int n) {
    if (n <= 0) return NULL;
    TreeNode* root = new TreeNode(input[0]);
    for (int i = 1; i < n; i++) {
        TreeNode* tmp = root;
        while(tmp) {
            if (input[i] < tmp->val) {
                if (tmp->left == NULL) {
                    tmp->left = new TreeNode(input[i]);
                    break;
                } else {
                    tmp = tmp->left;
                }
            } else {
                if (tmp->right == NULL) {
                    tmp->right = new TreeNode(input[i]);
                    break;
                } else {
                    tmp = tmp->right;
                }
            }
        }        
    }
    return root;
}

int main() {
    int k;
    scanf("%d", &k);
    while(k--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &input[i]);
        TreeNode* root = build(n);
        bool is_ok = true;
        dfs(root, is_ok);
        auto res = is_ok ? "Yes" : "No";
        cout << res << endl;
    }
    return 0;
}
