#include<iostream>
using namespace std;

namespace Myspace{
    int a;
    void f1();

    class A{
      public:
      void fun(){
          cout << "This is a class inside namespace Myspace.." << endl;
      }
    };
}

void Myspace :: f1(){
    cout << "This is a f1 function" << endl;
}

using namespace Myspace;
int main(){
    f1();
    A a; a.fun();
    return 0;
}
