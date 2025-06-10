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
Node *SortColor( Node *&head){
    int zeroCount =0;
    int oneCount =0;
    int twoCount =0;
    Node *temp = head;
    while(temp!=NULL){
        if(temp->data==0){
            zeroCount++;
        }
        else if(temp->data==1){
            oneCount++;
        }
        else if(temp->data==2){
            twoCount++;
        }
        temp = temp->next;
    }
    temp = head;
    while(temp!=NULL){
        if(zeroCount!=0){
            temp->data = 0;
            zeroCount--;
        }
        else if(oneCount!=0){
            temp->data = 1;
            oneCount--;
        }
        else if(twoCount !=0){
            temp->data=2;
            twoCount--;
        }
        temp =temp->next;
    }
    return head;
}
Node InsertAtTail(Node*&tail,Node *curr){
   tail->next  = curr;
    tail= curr;
}
//if data replacement is not allowed  it means we swap the node;
Node*sortcolor(Node *&head){
     Node *zeroHead = new Node(-1);
     Node *zeroTail = zeroHead;
     Node *oneHead = new Node(-1);
     Node *oneTail = oneHead;
     Node *twoHead = new Node(-1);
     Node *twoTail = twoHead;
     Node *curr = head;
     while(curr!=NULL){
        int val = curr->data;
        if(val == 0){
            InsertAtTail(zeroTail,curr);
        }
        else if(val == 1){
            InsertAtTail(oneTail,curr);

        }
        else if(val == 2){
            InsertAtTail(twoTail,curr);
        }
        curr = curr->next;
     }
     if(oneHead->next!=nullptr){
        zeroTail->next = oneHead->next;
     }
     else{
        zeroTail->next = twoHead->next;
     }
     oneTail->next = twoHead->next;
     twoTail->next = NULL;
     head = zeroHead->next;
     delete oneHead;
     delete zeroHead;
     delete twoHead;
     return head;
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
    head->next = new Node(0);
    head->next->next = new Node(1);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(2);
    head->next->next->next->next->next = new Node(0);
    head->next->next->next->next->next->next= new Node(2);
    print(head);
   
    sortcolor(head);
    print(head);
    return 0;
}