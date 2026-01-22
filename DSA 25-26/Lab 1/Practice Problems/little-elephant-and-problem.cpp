/*
  The Little Elephant has got a problem — somebody has been touching his sorted by non-decreasing array a of length n and possibly swapped some elements of the array.
  The Little Elephant doesn't want to call the police until he understands if he could have accidentally changed the array himself. He thinks that he could have accidentally changed array a, only if array a can be sorted in no more than one operation of swapping elements (not necessarily adjacent). That is, the Little Elephant could have accidentally swapped some two elements.
  Help the Little Elephant, determine if he could have accidentally changed the array a, sorted by non-decreasing, himself.
  Input
  The first line contains a single integer n (2 ≤ n ≤ 105) — the size of array a. The next line contains n positive integers, separated by single spaces and not exceeding 109, — array a.
  Note that the elements of the array are not necessarily distinct numbers.
  Output
  In a single line print "YES" (without the quotes) if the Little Elephant could have accidentally changed the array himself, and "NO" (without the quotes) otherwise.
*/

#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    long long n;
    cin >> n;
 
    vector<long long> a(n);
    for(long long x = 0; x<a.size(); x++)
    cin >> a[x];
    vector<long long> b(n);
    b=a;
    long long k=0;
    sort(a.begin(), a.end());
    for(long long i=0; i<a.size(); i++)
    {
        if(a[i]!=b[i])
        k++;
    }
    if(k==2 || k==0) 
        cout<< "YES" << endl;
    else
        cout << "NO" << endl;
    
    return 0;
}
