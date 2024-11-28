#include <bits/stdc++.h>
#include <regex>
using namespace std;

char thirdConsonant(string &str)
{
    string withoutVowel = regex_replace(str, regex("[aeiouAEIOU]"), ""); 

    if (withoutVowel.size() >= 3)
    {
        return withoutVowel[withoutVowel.size() - 3];
    }
    return '0';
}

int main()
{
    string str = "abcdefi";
    cout << thirdConsonant(str) << endl; // Outputs 'c'
}
