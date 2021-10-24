#include<iostream>

using namespace std;
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        
        ListNode* insert = head;
        ListNode* cur = head->next;
        while(cur) {
            if (insert->val == cur->val) {
                cur = cur->next;
                continue;
            }
            insert->next = cur;
            insert = insert->next;
            cur = cur->next;
        }
        insert->next = NULL;
        return head;
    }
};

int main () {
	return 0;
}
