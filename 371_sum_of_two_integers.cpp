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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* cur = new ListNode();
        ListNode* prev = nullptr;
        ListNode* head = cur;
        int carry = 0;

        while(l1 || l2) {
            int val1 = (l1) ? l1->val : 0;
            int val2 = (l2) ? l2->val : 0;
            int cur_dig = 0;

            if(val1 + val2 + carry >= 10) {
                cur_dig = (val1 + val2 + carry) % 10;
                carry = 1;
            } else {
                cur_dig = val1 + val2 + carry;
                carry = 0;
            }

            cur->val = cur_dig;
            if((l1 && l1->next) || (l2 && l2->next)) {
                cur->next = new ListNode();
            }
            prev = cur;
            cur = cur->next;

            // NOTE: move nodes
            if(l1) {
                l1 = l1->next;
            }
            if(l2) {
                l2 = l2->next;
            }
        }

        if(carry) {
            cur = new ListNode(carry);
            prev->next = cur;
        } 

        return head;
    }
};
