#include <bits/stdc++.h>
using namespace std;

void revarray(int arr[], int start, int end)
{
    if(start>=end)
    return;
    swap(arr[start], arr[end]); //DOUBLE POINTER
    revarray(arr, start+1, end-1);
}
int main()
{
    int n;
    cout << "Enter size of array:";
    cin >> n;
    int arr[n];
    cout << "Enter elements of array";
    for(int i=0; i<n; i++)
    cin >> arr[i];

    revarray(arr,0,n-1);
    for(int i=0; i<n; i++)
    cout << arr[i];
    return 0;
}