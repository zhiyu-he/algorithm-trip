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
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        int i = 1;
        ListNode* res_node = head;
        ListNode* last_odd = head;
        ListNode* last_even = NULL;
        ListNode* cur_node = head;
        while (cur_node != NULL) {
            if (i % 2 == 1 && i != 1) {


                ListNode* tmp = last_odd->next;
                last_odd->next = cur_node;

                last_even->next = cur_node->next;



                last_odd->next->next = tmp;
                last_odd = last_odd->next;
                cur_node = last_even;

                tmp = res_node;

            }
            if (i % 2 == 0) {
                last_even = cur_node;
            }
            cur_node = cur_node->next;
            i += 1;
        }
        return res_node;
    }
};

int main() {
    return 0;
}
