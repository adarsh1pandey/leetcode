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
    bool hasCycle(ListNode *head) {
        set<ListNode*> s;
        bool flag = false;
        while (head != NULL)
        {
            if (s.find(head) != s.end())
            {
                flag = true;
                break;
            }
            s.insert(head);
            head = head->next;
        }
        return flag;
    }
};