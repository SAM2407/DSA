class Solution {
private:
    Node* InsertTail(Node*& head, Node*& tail, int val, unordered_map<Node*, Node*>& oldToNew, Node* originalNode) {
        Node* newNode = new Node(val);
        oldToNew[originalNode] = newNode;  

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        return head;
    }

public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;

        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        unordered_map<Node*, Node*> oldToNew;

        Node* temp = head;
        while (temp != NULL) {
            InsertTail(cloneHead, cloneTail, temp->val, oldToNew, temp);
            temp = temp->next;
        }

        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        while (originalNode != NULL) {
            cloneNode->random = (originalNode->random != NULL) ? oldToNew[originalNode->random] : NULL;
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }

        return cloneHead;
    }
};
