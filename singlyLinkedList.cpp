#include <iostream>
using namespace std;

// Create a single node, insert at begin, insert at end, insert at position
class Node{
   public:
   int data;
   Node* next;

   Node(int data){
     this->data = data;
     this->next = NULL;
   }
};

//print function for traversing the list
void print(Node* &head){
  Node* temp = head;
  while(temp != NULL){
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

//funtion to insert at beginning
void insertAtBegin(Node* &head, int d){
  Node* temp = new Node(d);
  temp->next = head;
  head = temp;
}
//funtion to insert at end
void insertAtEnd(Node* &tail, int d){
  Node* temp = new Node(d);
  tail->next = temp;
  tail = temp;
}

void insertAtPos(Node* &tail, Node* &head, int pos, int d){
  if(pos == 1){
    insertAtBegin(head, d);
    return ;
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

int main(){
  Node * node1 = new Node(10);
  Node* head = node1;
  Node* tail = node1;
  print(head);
  insertAtBegin(head, 20);
  print(head);

  insertAtEnd(tail, 30);
  print(head);

  insertAtPos(tail, head, 3, 50);
  print(head);
  insertAtPos(tail, head, 5, 100);
  print(head);
  
}
