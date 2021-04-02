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
    bool isPalindrome(ListNode* head) {
        if (head == NULL) return false;
        int cnt = 0;
        vector<ListNode*> s;
        ListNode* iter = head;
        while(iter) {
            s.push_back(iter);
            cnt += 1;
            iter = iter->next;
        }
        int left = 0, right = cnt - 1;
        iter = head;
        while (left < right) {
            if (iter->val == s[right]->val) {
                left += 1;
                right -= 1;
                iter = iter->next;
            } else {
                return false;
            }
        }
        return true;
    }
};
int main() {
	Solution s;
	return 0;
}
