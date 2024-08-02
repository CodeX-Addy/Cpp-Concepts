#include <iostream>
using namespace std;

int x = 4;//Global variable

void func(){
  int x = 4;
  cout << x << endl;
  ::x = 2;
  cout << ::x << endl;
}
int main() {
  int x = 20;
  cout << x << endl;//Local variable
  cout << ::x << endl;//Global variable
  {//Scope
    int x = 25;
    cout << x << endl;
    {
      int x = 100;
      cout << x << endl;
      cout << ::x << endl;
    }
  }
  func();

  cout << ::x << endl;
  return 0;
}
