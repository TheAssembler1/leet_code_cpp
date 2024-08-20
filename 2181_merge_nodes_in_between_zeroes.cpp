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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* prev_head = head;
        ListNode* cursor = head;
        ListNode* prev_cursor = nullptr;

        // NOTE: move cursor to start sum
        head = head->next;

        while(head) {
            int sum = 0;
            while(head->val) {
                sum += head->val;
                head = head->next;
            }

            // NOTE: write cur sum
            cursor->val = sum;
            prev_cursor = cursor;
            cursor = cursor->next;

            head = head->next;
        }

        // NOTE: end linked list
        prev_cursor->next = nullptr;

        return prev_head;
    }
};
