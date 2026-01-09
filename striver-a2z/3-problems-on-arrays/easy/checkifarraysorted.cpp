/*
    BRUTE: 
    The idea is pretty simple here, We will start with the element at the 0th index, and will compare it with all of its future elements that are present in the array.
If the picked element is smaller than or equal to all of its future values then we will move to the next Index/element until the whole array is traversed.
If any of the picked elements is greater than its future elements, Then simply we will return False.
If the size of the array is Zero or One i.e ( N = 0 or N = 1 ) or the entire array is traversed successfully then we will simply return True.

TC: O(N^2); SC: O(1)
*/

#include<bits/stdc++.h>
using namespace std;

// Function to check if the array is sorted
bool isSorted(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1])  // If any element is smaller than the previous one, return false
            return false;
    }

    return true;  // Return true if the array is sorted
}


//TC: O(N)
//SC: O(1)


