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
        
        unordered_map<Node*, Node*> um;
        
        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        while (originalNode != NULL && cloneNode != NULL)
        {
            um[originalNode] = cloneNode;
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }
        
        originalNode = head;
        cloneNode = cloneHead;
        while( originalNode != NULL && cloneNode != NULL)
        {
            cloneNode->random = um[originalNode->random];
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }
        return cloneHead;
        
        
    }
};