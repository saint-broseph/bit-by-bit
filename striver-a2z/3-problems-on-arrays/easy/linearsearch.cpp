#include<stdio.h>

// Function to search for a number in the array
int search(int arr[], int n, int num)
{
    int i;

    // Loop through the array to find the number
    for(i = 0; i < n; i++)
    {
        // If the current element matches the number, return its index
        if(arr[i] == num)
            return i;
    }

    // If the number is not found, return -1
    return -1;
}


//TC: O(N)
//SC: O(1)