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
Node *head = NULL;
Node *InsertAtBeg(Node *&head, int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
    return head;
}
Node *InsertAtEnd(Node *&head, int data)
{
    Node *newnode = new Node(data);
    if (head == NULL)
    {
        InsertAtBeg(head, data);
        return head;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = NULL;
    return head;
}
Node *InsertAtPos(Node *&head, int data)
{
    int pos, count = 1;
    cout << "Enter the position where you want to insert the node:-";
    cin >> pos;
    Node *temp = head;
    if (pos < 1) { // Handle invalid position
        cout << "Position cannot be less than 1." << endl;
        return head;
    }
    if (pos == 1)
    {
        InsertAtBeg(head, data);
        return head;
    }
    while (count < pos - 1 && temp!=NULL)
    {
        temp = temp->next;
        count++;
    }
     if ( temp ==NULL || temp->next == NULL)
    {
        InsertAtEnd(head, data);
    }
    Node *newnode = new Node(data);
    newnode->next = temp->next;
    temp->next = newnode;
    return head;
}
Node *DeleteAtBeg( Node *&head){
    Node *temp = head;
     if (head == NULL) { //  Handle empty list
        cout << "List is empty. Cannot delete from beginning." << endl;
        return head;
    }
    head = temp->next;
    delete(temp);
    return head;
}
Node *DeleteAtEnd(Node *&head){
    if(head == NULL){
        cout<<"list is empty."<<endl;
        return head;
    }
    if(head->next == NULL){
        delete(head);
        head = NULL;
        return head;
    }
    Node *temp = head;
    while(temp->next->next!= NULL){
        temp = temp->next;
    }
    delete(temp->next); 
    temp->next = NULL;
    return head;

}
Node *DeleteAtPos(Node *&head,int pos){
    if(head == NULL){
        cout<<"list is empty."<<endl;
        return head;
    }
    int count =1;
    if(pos == 1){
        DeleteAtBeg(head);
        return head;
    }
    Node *temp = head;
    while(count < pos - 1 && temp!=NULL){
        temp = temp->next;
        count++;
    }
if ( temp ==NULL || temp->next == NULL)
    {
        DeleteAtEnd(head);
    }
    Node *nodetobedeleted = temp->next;
    temp->next  =nodetobedeleted->next;
     delete (nodetobedeleted);
    return head;

}
void print(Node *&head)
{
    Node *temp = head;
    while (temp!= NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
int main()
{   
    InsertAtBeg(head, 10);
    InsertAtBeg(head, 20);
    // InsertAtPos(head,60);
    // print(head);
    InsertAtBeg(head, 30);
    InsertAtEnd(head, 40);
    print(head);
    // InsertAtPos(head,70);
    // print(head);
    DeleteAtPos(head,2);
    print(head);
    // InsertAtEnd(head, 50);
    // print(head);
    return 0;
}