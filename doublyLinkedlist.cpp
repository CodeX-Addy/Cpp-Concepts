#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;
    
    Node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

void insertAtHead(Node* &head, int d){
    Node* temp = new Node(d);
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void insertAtTail(Node* &tail, int d){
    Node* temp = new Node(d);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void insertAtPos(Node* &head, Node* &tail, int pos, int d){
    if(pos==1){
        insertAtHead(head, d);
        return ;
    }
   
    Node* temp = head;
    int cnt = 1;
    while(cnt < pos-1){
        temp = temp->next;
        cnt++;
    }
    
     if(temp->next == NULL){
        insertAtTail(tail, d);
        return;
    }
    
    
    Node* newNode = new Node(d);
    newNode->next = temp->next;
    temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
    
}


void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    print(head);
    insertAtHead(head, 5);
    print(head);
    insertAtTail(tail, 15);
    print(head);
    insertAtPos(head, tail, 4, 20);
    print(head);
    insertAtPos(head, tail, 1, 0);
    print(head);
    
    insertAtPos(head, tail, 3, 13);
    print(head);
    return 0;
}
