#include<iostream>

using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* dump = NULL;
        ListNode* res = NULL;
        
        
        ListNode* l = head;
        ListNode* iter = head->next;
        while(iter) {
            int cnt = 0;
            while(iter && l->val == iter->val) {
                iter = iter->next;
                cnt += 1;
            }
            if (cnt > 0) {
                l = iter;
                if (iter == NULL) break;
                iter = iter->next;
            } else {
                if (dump == NULL) {
                    dump = l;
                    res = dump;
                }
                else {
                    dump->next = l;
                    dump = dump->next;
                }
                l = iter;
                if (iter == NULL) break;
                iter = iter->next;
            }
        }
        if (dump == NULL) {
            res = l;
            if (l != NULL)
                    res->next = NULL;
        } else {
            dump->next = l;
            if (l != NULL)
                dump->next->next = NULL;
        }
        return res;
    }
};

int main() {
	return 0;
}
