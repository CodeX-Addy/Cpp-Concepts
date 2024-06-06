#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream inFile("file.txt");
    if(inFile.is_open()){
        string line;
        while(getline(inFile, line)){
            cout << line << endl;
        }
        inFile.close();
    }
    else{
        cout << "File not found" << endl;
    }

    return 0;
}