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
    void insertAtTail(Node* &cloneHead, Node* &cloneTail, int data)
    {
        Node* temp = new Node(data);
        if (cloneHead == NULL)
        {
            cloneHead = temp;
            cloneTail = cloneHead;
            return;
        }
        else
        {
            cloneTail->next = temp;
            cloneTail = temp;
        }
    }
    
    Node* copyRandomList(Node* head) {
        if (head == NULL)
        {
            return NULL;
        }
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        
        Node* temp = head;
        while (temp)
        {
            insertAtTail(cloneHead, cloneTail, temp->val);
            temp = temp->next;
        }
        
        // cloneNode add between original lists
        
        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        
        while(originalNode != NULL && cloneNode != NULL)
        {
            Node* next = originalNode->next;
            originalNode->next = cloneNode;
            originalNode = next;
            
            next = cloneNode->next;
            cloneNode->next = originalNode;
            cloneNode = next;
        }
        //step 3: random pointer copy 
        
        temp = head;
        while(temp != NULL)
        {
            if (temp != NULL)
            {
                temp->next->random = temp->random ? temp->random->next :temp->random;
            }
            temp = temp->next->next;
        }
        
        // step 4: revert changes done in step 2
        
        originalNode = head;
        cloneNode = cloneHead;
        while (originalNode != NULL && cloneNode != NULL)
        {
            originalNode->next = cloneNode->next;
            originalNode = cloneNode->next;
            if (originalNode != NULL)
            {
                cloneNode->next = originalNode->next;
            }
            cloneNode = cloneNode->next;
        }
        
        return cloneHead;
    }
};