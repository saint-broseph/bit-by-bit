/*
  You're given an array a. You should repeat the following operation k times: find the minimum non-zero element in the array, print it, and then subtract it from all the non-zero elements of the array. If all the elements are 0s, just print 0.
  Input
  The first line contains integers n and k (1≤n,k≤105), the length of the array and the number of operations you should perform.
  The second line contains n space-separated integers a1,a2,…,an (1≤ai≤109), the elements of the array.
  Output
  Print the minimum non-zero element before each operation in a new line.
  */

//TIME COMPLEXITY: O(NLOGN + K)
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for(long long i=0; i<n; i++)
    cin >> a[i];

    sort(a.begin(), a.end());
    set<int> b;
    b.insert(a.begin(), a.end());

    long long x = 0;
    auto it = b.begin();
    
    for(long long  i = 0; i<k; i++)
    {
        if(it!=b.end())
        {
            cout << *it - x << endl;
            x = *it;
            it++;
        }
        else
        cout << 0 << endl;
    }
    return 0;
}
