//Stack C++ STL
#include <iostream>
#include<stack>
using namespace std;

int main() {
  stack<int> s;
  //Pushing elements into the stack
  s.push(10);
  s.push(20);
  s.push(30);

  //Printing size of the stack
  cout << "Size of stack: " << s.size() << endl;

  //Removing top element
  s.pop();
  cout << s.size() << endl;

  //What is top on stack
  cout << s.top() << endl;

  //Checking isEmpty stack -> Returns either T or F
  if(s.empty()) cout << "Stack is empty";
  else cout << "Stack is not empty";
  return 0;  
}
