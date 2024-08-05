//
// Created by Jiang Yinzuo on 2021/3/1.
//
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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* end = swapPairs(head->next->next);
        head->next->next = head;
        ListNode *start = head->next;
        head->next = end;
        return start;
    }
};

int main() {
    Solution s;
    s.swapPairs()
    return 0;
}