#include<iostream>
using namespace std;

// Structure binding is used to bind the structure variable with a temporary object of that structure. 
//It simply assign advance data structures into our program variables.
struct Person{
    int age;
    string name;
};

int main(){
    Person p{25, "John"};
    auto[age, name] = p;
    cout << "Age: " << age << endl;

    return 0;
}