#include <bits/stdc++.h>
using namespace std;

bool pal(string s, int st, int e)
{
    if(st>=e)
    return true;
    if(s[st]!=s[e]) //DOUBLE POINTER
    return false;
    return pal(s,st+1,e-1);
}
int main()
{
    string s;
    cout << "Enter the string";
    cin >> s;
    
    if(pal(s,0,s.length()-1))
    cout << "Palindrome";
    else
    cout << "Not palindrome";
    return 0;
}