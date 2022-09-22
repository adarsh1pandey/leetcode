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
         
        int countA = 0;
        int countB = 0;
        ListNode* curr = headA;
        while (curr)
        {
            countA++;
            curr = curr->next;
        }
        curr = headB;
        while (curr)
        {
            countB++;
            curr = curr->next;
        }
        int val = abs(countA - countB);
        if (countA > countB)
        {
            for (int i = 0; i < val; i++)
            {
                headA = headA->next;
            }
            
            while (headA)
            {
                if (headA == headB)
                {
                    return headA;
                }
                headA = headA->next;
                headB = headB->next;
            }
        }
        else
        {
            for (int i = 0; i < val; i++)
            {
                headB = headB->next;
            }
            while (headB)
            {
                if (headA == headB)
                {
                    return headA;
                }
                headA = headA->next;
                headB = headB->next;
            }
        }
        return NULL;
        
            
    }
};