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
        if(!head || !head->next) {
            return head;
        }

        ListNode* prev = new ListNode();
        prev->next = head;
        ListNode* prev_head = head->next;

        while(head && head->next) {
            ListNode* cur = head;
            ListNode* next = head->next;
            ListNode* next_next = head->next->next;

            cur->next = next_next;
            next->next = cur;
            prev->next = next;

            prev = cur;
            head = next_next;
        }

        return prev_head;
    }
};
