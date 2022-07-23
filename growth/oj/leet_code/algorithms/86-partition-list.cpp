#include<iostream>
#include<vector>

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
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL) return head;
        vector<ListNode*> l, r;
        while(head != NULL) {
            if (head->val < x) {
                l.push_back(head);
            } else {
                r.push_back(head);
            }
            head = head->next;
        }
        ListNode* merge_l = NULL;
        ListNode* merge_r = NULL;
        for (ListNode* n : l) {
            if (merge_l == NULL) {
                merge_l = n;
            } else {
                merge_l->next = n;
                merge_l = merge_l->next;
            }
        }
        for (ListNode* n : r) {
            if (merge_r == NULL) {
                merge_r = n;
            } else {
                merge_r->next = n;
                merge_r = merge_r->next;
            }
        }
        if (merge_r != NULL)
            merge_r->next = NULL;
        
        if (merge_l == NULL) return r[0];
        if (merge_l != NULL && r.size() > 0) merge_l->next = r[0];
        
        return l[0];
    }
};

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
class Solution2 {
public:
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL) return head;
        ListNode* small = new ListNode(-1);
        ListNode* large = new ListNode(-1);
        ListNode* sh = small;
        ListNode* lh = large;
        while(head) {
            if (head->val < x) {
                small->next = head;
                small = small->next;
                head = head->next;
                small->next = NULL;
            } else {
                large->next = head;
                large = large->next;
                head = head->next;
                large->next = NULL;
            }
        }
        small->next = lh->next;
        return sh->next;
    }
};

int main() {
	Solution s;
	return 0;
}
