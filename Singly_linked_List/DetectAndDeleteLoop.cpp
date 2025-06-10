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
Node *floyedDectectioLoop(Node *&head){
    Node *slow = head;
    Node *fast = head;
    if(head == NULL)
    return NULL;
    while(slow  != NULL && fast!=NULL){
        fast = fast->next;
        if(fast !=NULL){
            fast = fast->next;
        }
        slow = slow->next;
        if(slow == fast){
            return slow;
        }
    }
    return NULL;
}
Node *getStartingOfLoop(Node *&head){
    if(head == NULL)
    return NULL;
    Node *interSection = floyedDectectioLoop(head);
    Node *slow = head;
    while(slow != interSection){
        slow = slow->next;
        interSection = interSection->next;
    }
    
    return slow;
}
void RemoveLoop( Node *&head){
    Node *start = getStartingOfLoop(head);
    cout<<"starting point of loop is = "<<start->data<<endl;
    Node *temp = start;
    while(temp->next != start){
        temp =temp->next;
    }
    temp->next = NULL;
    cout<<"loop is removed"<<endl;
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
int main() {
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = head->next; 

     Node *temp = floyedDectectioLoop(head);
     if(temp!=NULL){
        cout<<"loop is present "<<endl;
     }
     else{
        cout<<"loop is not present";
     }
    getStartingOfLoop(head);
     RemoveLoop(head);
    print(head);

   
}
