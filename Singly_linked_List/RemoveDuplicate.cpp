#include <iostream>
#include <unordered_set>
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
Node *RemoveDuplicateNode( Node *&head){
  //It is implemented on a sorted linked list only
    if(head == NULL){
        cout<<"linked list is empty"<<endl;
        return NULL;
    }
    Node*curr = head;
    while( curr!=NULL && curr->next!=NULL){
        if(curr->data == curr->next->data){
            Node *temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        }
        else {
            curr = curr->next;
        }
    }
    return head;
}

//there are two ways for deleting the duplicate from unsorted linked list first we can use two while loop like 
//we use to do with array fixing the first element then comparing and deleting the other duplicate elements 
//We have second way by using hash map where we make a map named as visited then check the the visited and delet it accordingly 
//there is a one more way first we can sort the list then call the sorted way in linked list 

Node *removeDuplicate(Node *&head){
    if(head == NULL)
    return NULL;
    //1->2->3->1->2->2->3->4->x
    Node *curr = head;
    
    while(curr!=NULL ){
        Node *temp = curr;
      while(temp->next!=NULL ){
        if(curr->data == temp->next->data){
            Node *dup = temp->next;
            temp->next = temp->next->next;
            delete dup;
        }
        else{
            temp = temp->next;
        }
      }
      curr = curr->next;
        
    }
    return head;
}
Node* removeduplicatenode(Node* head) {
    if (head == NULL) return NULL;

    unordered_set<int> visit;
    Node* curr = head;
    Node* prev = NULL;

    while (curr != nullptr) {
        if (visit.count(curr->data)) {
            // Duplicate found, delete it
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        } else {
            visit.insert(curr->data);
          // First time seeing this data
            prev = curr;
            curr = curr->next;
        }
    }

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
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(2);
    head->next->next->next->next->next = new Node(3);
    head->next->next->next->next->next->next= new Node(4);
    print(head);
    RemoveDuplicateNode(head);
    removeDuplicate(head);
    removeDuplicateNode(head);
    print(head);
}
