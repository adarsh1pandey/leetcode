/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
         ListNode *p = headA;
        while (p != NULL)
        {
            ListNode *q = headB;
            while (q != NULL)
            {
                if (p == q)
                {
                    return p;
                }
                q = q->next;
            }
            p = p->next;
        }
        return NULL;
            
    }
};