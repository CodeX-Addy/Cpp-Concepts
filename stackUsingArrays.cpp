#include<iostream>
using namespace std;

class Stack{
  public:
  int *arr;
  int size;
  int top;

  //constructor
  Stack(int size){
    arr = new int[size];
    this->size = size;
    this->top = -1;
  }

  //Push func
  void push(int data){
    if(top == size-1){
      cout << "Stack overflow" << endl;
      return;
    }
   else{
     ++top;
     arr[top] = data;
   }
  }

  //Pop func
  void pop(){
    if(top == -1){
      cout << "Stack is empty" << endl;
      return;
    }
    else --top;
  }

  //Empty fun
  bool isEmpty(){
    if(top == -1) return true;
    else return false;
  }

  //get top
  int getTop(){
    if(top == -1){
      cout << "Stack is empty" << endl;
      return -1;
    }
    else return arr[top];
  }

  //get size
  int getSize(){
    return top+1;
  }

  //Printing the progress
  void print(){
    cout << "Top: " << top << endl;
    cout << "Top element: " << getTop() << endl;
    cout << "Stack: ";
    for(int i=0; i<getSize(); ++i){
      cout << arr[i] << " ";
    }cout << endl << endl;
  }
};

int main(){
  Stack s(5);
  s.push(10);
  s.print();
  s.push(20);
  s.print();

  s.push(30);
  s.print();

  return 0;
}
