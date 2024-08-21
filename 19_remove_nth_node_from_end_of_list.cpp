tion for singly-linked list.
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* prev = new ListNode();
        ListNode* prev_prev = prev;
        ListNode* temp_head = head;

        int size = 0;
        while(temp_head) {
            size++;
            temp_head = temp_head->next;
        }

        prev->next = head;

        int cur{0};
        while(head) {
            if(cur == size - n) {
                prev->next = head->next;
                break;
            }

            cur++;
            prev = head;
            head = head->next;
        }

        return prev_prev->next;
    }
};
