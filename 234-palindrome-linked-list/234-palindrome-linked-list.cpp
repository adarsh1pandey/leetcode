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
    ListNode* reverseList(ListNode* a)
    {
        ListNode* prev = NULL;
        ListNode* curr = a;
        ListNode* next = curr;
        while (curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr= next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if (head == NULL)
            return true;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* rev = reverseList( slow->next);
        
        while (rev != NULL)
        {
            if ( head->val != rev-> val)
                return false;
            head = head->next;
            rev = rev->next;
        }
        return true;
    }
};