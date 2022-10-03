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
    ListNode* reverseList(ListNode* r)
    {
        ListNode* prev = NULL;
        ListNode* curr = r;
        ListNode* next = curr;
        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        if (head == NULL)
            return ;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* rev = reverseList(slow->next);
        slow->next = NULL;
        ListNode* curr = head;
        while ( rev != NULL && curr != NULL)
        {
            ListNode* temp1 = curr->next;
            ListNode* temp2 = rev->next;
            curr->next = rev;
            rev->next = temp1;
            curr = temp1;
            rev = temp2;
        }   
     
       
    }
};