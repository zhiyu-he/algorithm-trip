#include<iostream>
#include<vector>

using namespace std;

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

class Solution {
public:
    // method1
    ListNode* middleNode(ListNode* head) {
        int cnt = 0;
        ListNode* start = head;
        while (start != NULL) {
            cnt += 1;
            start = start->next;
        }
        ListNode* res = head;
        int mid = cnt /2;
        for (int i = 0; i < mid; i++) {
            res = res->next;
        }
        return res;
    }
    // method2
    ListNode* middleNode2(ListNode* head) {
        ListNode* res = head;
        int len = 1;
        while(head != NULL) {
            if (len % 2 == 0)
                res = res->next;
            head = head->next;
            len += 1;
        }
        return res;
    }
};

int main() {
    return 0;
}
