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
    ListNode* mergeTwo(ListNode *l1, ListNode *l2)
    {
        if (l1 == NULL)
        {
            return l2;
        }
        if (l2 == NULL)
        {
            return l1;
        }
        ListNode *a = l1;
        ListNode *b = l2;
        ListNode *dummy = new ListNode(-1);
        ListNode *pre = dummy;
        while (a && b)
        {
            if (a->val < b->val)
            {
                pre->next = a;
                pre = pre->next;
                a = a->next;
            }
            else
            {
                pre->next = b;
                pre = pre->next;
                b = b->next;
            }
        }
        if (a)
        {
            pre->next = a;
        }
        if (b)
        {
            pre->next = b;
        }
        return dummy->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0)
        {
            return NULL;
        }
        ListNode *temp = lists[0];
        
        for (int i = 1; i < lists.size(); i++)
        {
            temp = mergeTwo(temp, lists[i]);
        }
        return temp;
    }
};