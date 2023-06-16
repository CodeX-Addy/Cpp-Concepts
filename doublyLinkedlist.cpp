//Doubly linked list implementation
#include <iostream>
using namespace std;

//Node creation
class Node {
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

// Insert at beginning
void insertBegin(Node* &head, int d){
    Node* temp = new Node(d);
    temp->next = head;
    head->prev = temp;
    head = temp;
}
// Traversing the linked list
void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp=temp->next;
    }
    cout << endl;
}


int main() {
    Node* node1 = new Node(10);
    Node* head = node1;
    print(head); //Output:-10

    return 0;
}
