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
    ListNode *detectCycle(ListNode *head) {
        ListNode *temp = head;
        ListNode *val= NULL;
        set<ListNode*> s;
        while (temp)
        {
            if (s.find(temp) != s.end())
            {
                val = temp;
                break;
            }
            s.insert(temp);
            temp = temp->next;
        }
        return val;
    }
};