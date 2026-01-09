#include <bits/stdc++.h>
using namespace std;

int sum(int n)
{   
    if(n==0)
    return 0;
    
    return n+sum(n-1);
}

int main()
{
    int n=0;
    cin >> n;
    cout << "sum" << sum(n);
    return 0;
}