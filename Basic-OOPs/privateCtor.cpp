#include <iostream>
using namespace std;

class Box{
  int width;
  //ctor
  Box(int _w):width(_w){}
  
  public:
  int getWidth() const{
      return width;
  }
  
  void setWidth(int _w){
      this->width = _w;
  }
  
  friend class BoxFactory;
};

class BoxFactory{
    int cnt;
    public:
    Box getBox(int _w){
        ++cnt;
        return Box(_w);
    }

};
int main() {
    BoxFactory bfact;
    Box b = bfact.getBox(5);
    cout << b.getWidth() << endl;
    return 0;
}
