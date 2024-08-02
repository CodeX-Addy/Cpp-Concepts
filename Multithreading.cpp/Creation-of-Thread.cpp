#include <iostream>
#include <thread>
using namespace std;

void printMessage(const string &message)
{
    cout << message << endl;
}

int main()
{
    // Creating threads
    thread t1(printMessage, "Hello from thread t1");
    thread t2(printMessage, "Hello from thread t2");

    // Joining threads
    t1.join(); // Wait for t1 to finish
    t2.join(); // Wait for t2 to finish

    return 0;
}