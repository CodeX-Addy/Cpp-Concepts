#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    // Syntax for creating 2D dynamic array
    int **arr = new int*[n];
    for(int i=0; i<n; i++){
        arr[i] = new int[n];
    }
    // Taking input
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }
    // Displaying the output
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << arr[i][j] << " ";
        }cout << endl;
    }
    

    return 0;
}
// Syntax for different rows and columns
    int m,n;
    cin >> m >> n;
    int **arr = new int*[m];
    for(int i=0; i<m; i++){
        arr[i] = new int[n];
    }
