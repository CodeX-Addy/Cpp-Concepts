#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    
    Node(int d){
        this->data = d;
        this->next = NULL;
    }
};


//Insertion in circular linked list
void insert(Node* &tail, int ele, int d){
    //If linked list is emty
    if(tail == NULL){
        Node* newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
    }
    else{
        Node* curr = tail;
        while(curr->data != ele){
            curr = curr->next;
        }
        
        Node* temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

//Traversing linked list
void print(Node* tail){
    Node* temp = tail;
    do{
        cout << tail->data << " ";
        tail = tail->next;
    }while(tail != temp);
    cout << endl;
}
int main() {
    Node* tail = NULL;
    insert(tail, 3, 3);
    print(tail);
    
    insert(tail, 3, 5);
    print(tail);
    
    insert(tail, 5, 7);
    print(tail);

    return 0;
}
