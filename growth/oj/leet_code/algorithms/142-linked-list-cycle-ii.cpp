#include<iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> s;
        while(head) {
            if (s.find(head) == s.end()) {
                s.insert(head);
            } else {
                return head;
            }
            head = head->next;
        }
        return NULL;
    }
};


int main() {
    return 0;

}
