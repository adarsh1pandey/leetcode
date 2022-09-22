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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* evenh = NULL;
        ListNode* eventt = NULL;
        ListNode* oddh = NULL;
        ListNode *oddt = NULL;
        int n = 1;
        for (ListNode* curr = head; curr != NULL; curr = curr->next)
        {
            
            if (n % 2 == 0)
            {
                if (evenh == NULL)
                {
                    evenh = curr;
                    eventt = evenh;
                
                }
                else
                {
                    eventt->next = curr;
                    eventt = eventt->next;
                }
            }
            else
            {
                if (oddh == NULL)
                {
                    oddh = curr;
                    oddt = oddh;
                   
                }
                else
                {
                    oddt->next = curr;
                    oddt = oddt->next;
                }
            }
            n++;
        }
        if (evenh == NULL || oddh == NULL)
        {
            return head;
        }
        oddt->next = NULL;
        oddt->next = evenh;
        eventt->next = NULL;
        return oddh;;
    }
};