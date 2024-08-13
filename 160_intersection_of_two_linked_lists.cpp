#include <stddef.h>
#include <set>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


#include <set>

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        std::set<ListNode*> headA_set;

        while (headA) {
            headA_set.insert(headA);
            headA = headA->next;
        }

        while (headB) {
            auto count = headA_set.count(headB);

            if(count) {
                return headB;
            }

            headB = headB->next;
        }

        return 0;
    }
};
