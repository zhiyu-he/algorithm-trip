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
    bool hasCycle(ListNode *head) {
        if (head == NULL) return false;
        ListNode* walk = head;
        ListNode* runner = head;
        while(runner->next != NULL && runner->next->next != NULL) {
            walk = walk->next;
            runner = runner->next->next;
            if (walk == runner) return true;
        }
        return false;
    }
};
