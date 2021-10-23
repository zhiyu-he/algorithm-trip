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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL) return NULL;
        if (n >= 1 && head->next == NULL) return NULL;
        ListNode* p1 = head;
        ListNode* p2 = head;
        int k = 0;
        bool bingo = false;
        while(k < n+1) {
            p2 = p2->next;
            k++;
            if (p2 == NULL && k < n + 1) {
                bingo = true;
                break;
            }
        }
        if (bingo) {
            head = head->next;
            return head;
        }
        while(p2) {
            p1 = p1->next;
            p2 = p2->next;
        }
        p1->next = p1->next->next;
        return head;
    }
};

int main() {
	return 0;
}
