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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == NULL) return;
        vector<ListNode*> even;
        vector<ListNode*> odd;
        ListNode* iter = head;
        int i = 0;
        while(iter) {
            i += 1;
            iter = iter->next;
        }
        iter = head;
        int cur_cnt = 0;
        int stop_pos = i % 2 == 0 ? i / 2 : i / 2 + 1;
        while(iter) {
            if (cur_cnt < stop_pos)
                even.push_back(iter);
            else
                odd.push_back(iter);
            iter = iter->next;
            cur_cnt += 1;
        }
        int j = odd.size() - 1;
        i = 0;
        ListNode* new_head = even[i];
        i += 1;
        cur_cnt = 1;
        while(i < even.size() && j >= 0) {
            if(cur_cnt % 2 == 0) {
                new_head->next = even[i++];
            } else {
                new_head->next = odd[j--];
            }
            cur_cnt += 1;
            new_head = new_head->next;

        }
        while(i < even.size()) {
            new_head->next = even[i];
            i++;
            new_head = new_head->next;
        }
        while(j >= 0) {
            new_head->next = odd[j];
            j--;
            new_head = new_head->next;
        }
        new_head->next = NULL;
        return;
    }
};

int main() {
    Solution s;
    return 0;
}
