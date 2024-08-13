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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* prev = new ListNode();
        ListNode* head = prev;

        // NOTE: while we have nodes in both list to travers
        while(list1 && list2) {
            if(list1->val <= list2->val) {
                prev->next = list1;
                prev = list1;
                list1 = list1->next;
            } else if(list2->val < list1->val) {
                prev->next = list2;
                prev = list2;
                list2 = list2->next;
            }
        }

        // NOTE: one list may have remaining nodes
        if(list1) {
            prev->next = list1;
        } else if(list2) {
            prev->next = list2;
        }

        return head->next;
    }
};
