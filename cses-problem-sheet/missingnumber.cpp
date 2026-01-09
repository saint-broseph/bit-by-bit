#include <bits/stdc++.h>
using namespace std;

int main()
{

    long long sum = 0;
    long long n;
    cin >> n;
    vector<int> arr(n - 1);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    long long missing = n * (n + 1) / 2 - sum;
    cout << missing << endl;

    return 0;
}
