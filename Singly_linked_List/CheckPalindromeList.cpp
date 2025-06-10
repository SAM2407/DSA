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
Node *getMiddle(Node *head){
    Node *slow = head;
    Node *fast = head->next;
    while(fast!=NULL && fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
Node *reverse(Node *head){
    Node *curr = head;
    Node *prev = NULL;
    Node *next = NULL;
    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
bool isPalindrome(Node *head){
    if(head == NULL || head->next==NULL) return true;
    Node *middle = getMiddle(head);
    Node *temp = middle->next;
    middle->next = reverse(temp);
    Node*head1 = head;
    Node *head2 =  middle->next;
    while(head2!=NULL){
        if(head1->data != head2->data){
            temp = middle->next;
            middle->next = reverse(temp);
            cout<<"list is not a palindrome"<<endl;
            return false;
        }
        head1= head1->next;
        head2 = head2->next;
    }
     temp = middle->next;
     middle->next = reverse(temp);
     cout<<"list is palindrome"<<endl;
     return true;
}
void print(Node *head){
Node*temp = head;
while(temp!=nullptr){
    cout<<temp->data<<"->";
    temp = temp->next;
}
cout<<"NULL"<<endl;
}
int main(){
 Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(2);
    head->next->next->next->next->next = new Node(1);
    isPalindrome(head);
    print(head);
}
