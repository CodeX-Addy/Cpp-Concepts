#include <iostream>
#include <thread>
using namespace std;

// A new thread concurrently executes with main thread
void printMessage()
{
    cout << "Hey I am a thread" << endl;
}

int main()
{
    thread t(printMessage);
    t.join();
    return 0;
}