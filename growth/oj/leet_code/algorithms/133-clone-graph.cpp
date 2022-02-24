#include<iostream>

using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<int, Node*> cloned;
    Node* cloneGraph(Node* node) {
        if (node == NULL) return NULL;
        Node* res = new Node();
        cloned[node->val] = res;
        res->val = node->val;
        for (Node* ch : node->neighbors) {
            Node* n = cloned.find(ch->val) == cloned.end() ? cloneGraph(ch) : cloned[ch->val];
            res->neighbors.push_back(n);
        }
        return res;
    }
};

int main() {
	return 0;
}
