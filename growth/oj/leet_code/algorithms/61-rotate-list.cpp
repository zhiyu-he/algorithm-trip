#include<iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 *  
*/
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };


class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL) return head;
        ListNode *ret, *tail;
        ret = tail = head;
        // join tail and head to circle
        int len = 1;
        while(tail->next) {
            tail = tail->next;
            len += 1;
        }
        tail->next = head;
        k %= len;
        if (k) {
            for (int i = 0; i < len - k; i++) {
                tail = tail->next;
            }
        }
        ret = tail->next;
        tail->next = NULL;
        return ret;
    }
};

int main() {
    Solution s;
    return 0;
}
