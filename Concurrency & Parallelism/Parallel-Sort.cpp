// Parallel sort
#include <iostream>
#include <algorithm>
#include <execution> // Include the execution header
#include <vector>
using namespace std;

int main()
{
    vector<int> v = {5, 4, 2, 1, 3, 7};
    sort(execution::par, v.begin(), v.end());
    for (const auto &i : v)
    {
        cout << i << " ";
    }
}