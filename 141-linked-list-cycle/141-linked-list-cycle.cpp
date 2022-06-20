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
        unordered_map<ListNode*, int> um;
        bool flag = true;
        while (head)
        {
            um[head]++;
            if (um[head] > 1)
            {
                return true;
                
            }
            head = head->next;
        }
        return false;
    }
};