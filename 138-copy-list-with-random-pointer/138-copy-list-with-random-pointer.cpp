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
    void insertAtTail(Node* &head, Node* &tail, int data)
    {
        Node* newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    Node* copyRandomList(Node* head) {
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        
        Node* temp = head;
        while (temp)
        {
            insertAtTail(cloneHead, cloneTail, temp->val);
            temp = temp->next;
        }
        
        unordered_map<Node*, Node*> oldToNew;
        
        Node* cloneNode = cloneHead;
        Node* originalNode = head;
        
        while (cloneNode != NULL && originalNode != NULL)
        {
            oldToNew[originalNode] = cloneNode;
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }
        
        cloneNode = cloneHead;
        originalNode = head;
        while (originalNode != NULL)
        {
            cloneNode->random = oldToNew[originalNode->random];
            cloneNode = cloneNode->next;
            originalNode = originalNode->next;
        }
        return cloneHead;
  
    }
};
