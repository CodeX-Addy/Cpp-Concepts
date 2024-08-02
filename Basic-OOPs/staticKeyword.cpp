//Static Data Members
#include <iostream>
using namespace std;

class Demo{
     public:
     static int x,y;

     void print() const{
       cout << this->x << " " << this->y << endl;
     }
     
};

int Demo::x;
int Demo::y;

int main() {
  Demo obj1;
  obj1.x = 10;
  obj1.y = 20;
  obj1.print();

  Demo obj2;
  obj1.x = 40;
  obj2.y = 60;
  obj1.print();
  
  return 0;
  return 0;
}

//Static member function
#include<iostream>
using namespace std;

class Demo{
public:
int x,y;
static void print(){
  printf("Hello %s\n", __func__);
}
};

int main(){
  Demo::print();
  Demo obj1;
  obj1.print();
  return 0;
}
