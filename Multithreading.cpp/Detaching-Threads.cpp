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
    t1.detach(); // t1 runs independently

    this_thread::sleep_for(chrono::seconds(3)); // Ensuring main thread waits for t1

    return 0;
}