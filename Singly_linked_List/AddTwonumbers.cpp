#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

Node* head = NULL;

Node* InsertAtBeg(Node*& head, int data) {
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
    return head;
}

void InsertTail(Node*& head, Node*& tail, int val) {
    Node* temp = new Node(val);
    if (head == NULL) {
        head = temp;
        tail = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
}

Node* reverse(Node*& head) {
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

Node* add(Node* first, Node* second) {
    int carry = 0;
    Node* ansTail = NULL;
    Node* ansHead = NULL;

    while (first != NULL || second != NULL|| carry!=0) {
        int val1 = 0;
            if(first!=NULL)
            val1 = first->data;
            int val2 = 0;
            if(second!=NULL)
            val2 =second ->data;
        int sum = carry +val1+val2;
        int digit = sum % 10;
        InsertTail(ansHead, ansTail, digit);
        carry = sum / 10;
        if(first!=NULL)
        first = first->next;
        if(second!=NULL)
        second = second->next;
    }
    return ansHead;
}

void print(Node*& head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    } 
    cout << "NULL" << endl;
}

Node* addTwolist(Node* first, Node* second) {
    first = reverse(first);
    second = reverse(second);
    Node* ans = add(first, second);
    ans = reverse(ans);
    print(ans);
    return ans;
}

int main() {
    Node* first = NULL;
    Node* second = NULL;
    first = InsertAtBeg(first, 2);
    first = InsertAtBeg(first, 4);
    first = InsertAtBeg(first, 9);

    second = InsertAtBeg(second, 5);
    second = InsertAtBeg(second, 6);
    second = InsertAtBeg(second, 4);
    second = InsertAtBeg(second, 9);

    cout << "First: ";
    print(first);
    cout << "Second: ";
    print(second);

    cout << "Sum: ";
    addTwolist(first, second);
}
