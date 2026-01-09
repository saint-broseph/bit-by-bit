#include <bits/stdc++.h>
using namespace std;

// Function to find the largest element in the array
int findLargestElement(int arr[], int n) {
    int max = arr[0];  // Initialize max with the first element in the array

    // Iterate through the array to find the maximum element
    for (int i = 1; i < n; i++) {
        if (max < arr[i]) {  // If the current element is greater than max, update max
            max = arr[i];
        }
    }

    return max;  // Return the largest element found
}


//TC: O(N); //SC: O(1)

/*
    int sortArr(vector<int>& arr) {
    // Sort the array in ascending order
    sort(arr.begin(), arr.end());
    
    // Return the last element (largest element) after sorting
    return arr[arr.size() - 1];
}
    // TC: O(N*LOGN) //SC: O(1)
*/