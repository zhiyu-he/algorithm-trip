#include<iostream>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverse(ListNode* head, ListNode* tail) {
    ListNode* iter = head;
    while(iter != tail) {
        ListNode* tmp = iter->next;
        iter->next = tail->next;
        tail->next = iter;
        iter = tmp;
    }
    return tail;
}
void printLinkList(ListNode* head);

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 0 || k == 1) {
            return head;
        }
        ListNode* iter = head;
        int cnt = 0;
        ListNode* handle_head = iter;
        ListNode* last_tail = NULL;
        ListNode* res = NULL;
        while (iter != NULL) {
            cnt += 1;
            //std::cout << "cnt: " << cnt << std::endl;
            auto next_iter = iter->next;
            if (cnt % k == 0) {
                //std::cout << "change: " << tmp->val << " cur_val: " << iter->val << std::endl;
                auto new_head = reverse(handle_head, iter);
                if (last_tail != NULL) {
                    std::cout << "last tail: " << last_tail->val << std::endl;
                }
                if (res == NULL) {
                    res = new_head;
                    last_tail = handle_head;
                } else {
                    last_tail->next = new_head;
                    last_tail = handle_head;
                }
                handle_head = next_iter;
            }
            iter = next_iter;
            //std::cout << "cnt: " << cnt << std::endl;
            //printLinkList(res);
        }
        return res == NULL ? head : res;  
    }
};

void printLinkList(ListNode* head) {
    std::cout << "start" << std::endl;

    while (head != NULL) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << "\n" << "end" << std::endl;
}


int main(void) {
	// case1
	ListNode head1 = ListNode(1);
    ListNode node2 = ListNode(2);
	head1.next = &node2;
    ListNode node3 = ListNode(3);
	head1.next->next = &node3;
    ListNode node4 = ListNode(4);
	head1.next->next->next = &node4;
    ListNode node5 = ListNode(5);
    head1.next->next->next->next = &node5;
//    ListNode node6 = ListNode(6);
//    head1.next->next->next->next->next = &node6;



	Solution obj;
	auto res = obj.reverseKGroup(&head1, 4);
    printLinkList(res);
    
    //reverse(&head1, &node5);
    //printLinkList(&node5);
    return 0;
}
