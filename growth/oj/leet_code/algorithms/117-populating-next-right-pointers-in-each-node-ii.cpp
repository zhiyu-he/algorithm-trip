#include<iostream>

using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) return root;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            Node* iter = NULL;
            for (int i = 0; i < size; i++) {
                Node* n = q.front();
                if (iter == NULL)
                    iter = n;
                else {
                    iter->next = n;
                    iter = iter->next;
                }
                q.pop();
                if (n->left != NULL) q.push(n->left);
                if (n->right != NULL) q.push(n->right);
            }
        }
        return root;
    }
};


int main() {
    return 0;
}
