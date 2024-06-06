#include<iostream>
#include<fstream>
using namespace std;

//ifstream : reading from files
//ofstream: writing to files
//fstream: used for both

int main(){
    ofstream outFile("file.txt");
    if(outFile.is_open()){
        outFile << "Hello World" << endl;
        outFile.close();
        cout << "Data is successfully written.." << endl;
    }
    else
        cout << "Unable to open file and write" << endl;
    
    return 0;
}