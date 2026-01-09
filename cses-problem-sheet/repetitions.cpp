#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    long long n=s.length();
    long long maxc=1, currc=1;
    for(int i=0; i<n; i++)
    {
        if(s[i]==s[i-1])
        currc++;
        else 
        currc=1;
        
        maxc=max(currc, maxc);
        
    }
    cout << maxc;
    return 0;   
}