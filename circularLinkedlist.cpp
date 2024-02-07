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

void insert(Node* &tail, int ele, int d){
    //if list is empty
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

void deleteNode(Node* &tail, int d){
    
    if(tail == NULL){
        cout << "List is empty" << endl;
        return;
    }
    
    else
    {
        Node* prev = tail;
        Node* curr = prev->next;
        while(curr->data != d){
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        if(curr == prev) {
            tail = NULL;
        }

        //>=2 Node linked list
        else if(tail == curr ) {
            tail = prev;
        }
        curr->next = NULL;
    }
 }
 


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
    insert(tail, 5, 3);
    print(tail);
    
    insert(tail, 3, 5);
    print(tail);
    
    deleteNode(tail,3);
    print(tail);
    return 0;
}
