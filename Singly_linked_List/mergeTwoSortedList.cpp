#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};
Node *head = nullptr;
Node *head1 = nullptr;
Node *head2 = nullptr;
class Solution {
public:
    void printList(Node* head) {
        if (head == nullptr)
            return;

        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
Node *solve(Node*head1,Node*head2){
     if (head1->next == NULL) {
        head1->next = head2;
        return head1;
    }
    Node *curr1 = head1;
    Node *next1 = curr1->next;
    Node *curr2 = head2;
    Node *next2 = curr2->next;
    while(next1!=NULL && next2!=NULL){
        if((curr2->data>=curr1->data) && (curr2->data<=next1->data)){
            curr1->next =curr2;
            next2 = curr2->next;
            curr2->next = next1;
            
            curr1 = curr2;
            curr2 = next2;
        }
        else{
            curr1 = next1;
            next1 = next1->next;

            if(next1 == NULL){
                curr1->next=curr2;
                return head1;
            }
        }
    }
    return head1;
}
Node *sortList(Node*head1,Node*head2){
    if(head1 == NULL) return head2;
    if(head2 == NULL) return head1;
    if(head2 == NULL && head1 ==NULL) return NULL;
    if(head1->data<=head2->data){
        solve(head1,head2);
    }
    else{
        solve(head2,head1);
    }
    // return head1;
    
}
int main() {
    // First linked list: 1 -> 3 -> 5
    Node* head1 = new Node(1);
    head1->next = new Node(3);
    head1->next->next = new Node(5);

    // Second linked list: 2 -> 4 -> 6
    Node* head2 = new Node(2);
    head2->next = new Node(4);
    head2->next->next = new Node(6);

    Solution s;
    cout << "First Linked List: ";
    s.printList(head1);

    cout << "Second Linked List: ";
    s.printList(head2);
    sortList(head1,head2);
    s.printList(head1);

    return 0;
}