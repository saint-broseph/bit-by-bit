#include <bits/stdc++.h>
using namespace std;

void printn(int n)
{
    if(n==0)
    return;
    printn(n-1); // CALL FIRST FOR 1 TO N; CALL AFTER COUT FOR N TO 1
    cout << n << " ";
    }

int main()
{
    int n;
    cin >> n;
    printn(n);
    return 0;
}