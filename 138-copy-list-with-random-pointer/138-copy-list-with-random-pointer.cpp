/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* curr = head;
        Node* next;
        // make copy of each node
        // and link them together 
        
        while (curr != NULL)
        {
            next = curr->next;
            Node* copy = new Node(curr->val);
            curr->next = copy;
            copy->next = next;
            curr = next;
        }
        // copy random pointer 
        curr = head;
        while (curr != NULL)
        {
            if (curr->random != NULL)
            {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }
        
        // third: restore the original list and extract the copy list 
        
        curr = head;
        Node* dummy = new Node(0);
        Node* copy;
        Node* copyTail = dummy;
        while (curr != NULL)
        {
            next = curr->next->next;
            // extract the copy
            copy = curr->next;
            copyTail->next = copy;
            copyTail = copy;
            
            // restore the original list 
            curr->next = next;
            
            curr = next;
        }
        return dummy->next;
    }
};