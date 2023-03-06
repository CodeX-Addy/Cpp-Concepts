// Macros implementation
// Program to print area of the rectangle
#include <iostream>
using namespace std;

#define Area(l,b) l*b // The given syntax defines the macros

int main() {
    int l,b;
    cout << "Ënter the length of rectangle: " << endl;
    cin >> l;
    cout << "Ënter the breadth of rectangle: " << endl;
    cin >> b;
    
    cout << "The area of rectangle is " << Area(l,b);
    return 0;
}

// Chain macros
#include <iostream>
using namespace std;

#define INSTA FOLLOWERS
#define FOLLOWERS 320

int main() {
    cout << "I have " << INSTA << " followers on instagram" << endl;
    return 0;
}
// Output:- I have 320 followers on instagram
