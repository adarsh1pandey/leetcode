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
        if (list1 == NULL)
        {
            return list2;
        }
        if (list2 == NULL)
        {
            return list1;
        }
        ListNode *a = list1;
        ListNode *b = list2;
        ListNode *dummy = new ListNode(-1);
        ListNode *prev = dummy;
        
        while (a && b)
        {
            if (a->val < b->val)
            {
                prev->next = a;
                a = a->next;
                prev = prev->next;
            }
            else
            {
                prev->next = b;
                b = b->next;
                prev = prev->next;
            }
        }
        if (a)
        {
            prev->next = a;
        }
        if (b)
        {
            prev->next = b;
        }
        return dummy->next;
    }
};