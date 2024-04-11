#include<iostream>
#include"bird.h"
using namespace std;

void func(Bird*&bird){
    bird->fly();
    bird->eat();
}

int main(){
    Bird *bird = new Eagle();
    func(bird);
}