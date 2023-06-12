#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
      this->data = data;
      this->next = NULL;
    }
    
};

void insertAtBegin(Node* &head, int d){
  Node* temp = new Node(d);
  temp->next = head;
  head = temp;
}

void insertAtEnd(Node* &tail, int d){
  Node* temp = new Node(d);
  tail->next = temp;
  temp = tail;
}

void deleteNode(int position, Node* &head){
  if(position == 1){
    Node *temp = head;
    head = head->next;
    delete temp;
  }
  else{
    Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < position) {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        prev -> next = curr -> next;
        curr -> next  = NULL;
        delete curr;
  }
}


void insertAtPos(Node* &tail, Node* &head, int pos, int d){
  if(pos == 1){
    insertAtBegin(head, d);
    return;
  }

  Node* temp = head;
  int cnt = 1;
  while(cnt < pos-1){
    temp = temp->next;
    cnt++;
  }

  Node* newNode = new Node(d);
  newNode->next = temp->next;
  temp->next = newNode;

  if(temp->next == NULL){
    insertAtEnd(tail, d);
    return; 
  }
  
}

void print(Node* &head){
  Node* temp = head;
  while(temp != NULL){
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

int main(){
  Node* node1 = new Node(10);
  Node* head = node1;
  Node* tail = node1;

  print(head);

  insertAtBegin(head, 20);
  print(head);

  insertAtEnd(tail, 100);
  print(head);

  insertAtPos(tail, head, 4, 500);
  print(head);

  insertAtPos(tail, head, 1, 1000);
  print(head);

  deleteNode(2, head);
  print(head);

  
}
