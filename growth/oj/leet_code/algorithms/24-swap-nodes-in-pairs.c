/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
// TIPS: 感觉有两种思路, 1. 交换val 2. 交换指针
struct ListNode* swapPairs(struct ListNode* head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }
    
    struct ListNode *cur, *node1, *node2;
    cur = head;
    node1 = cur;
    node2 = cur->next;
    while(node1 != NULL && node2 != NULL) {
        int tmp = node1->val;
        node1->val = node2->val;
        node2->val = tmp;
        cur = node2->next;
        if(cur == NULL || cur->next == NULL)
            break;
        node1 = cur;
        node2 = cur->next;
    }
    return head;
}
