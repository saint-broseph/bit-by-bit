/*
    For each element at position (i, j) in the original matrix, we calculate its new position in the rotated matrix as (j, n - i - 1) where n is the size of the matrix.

    BRUTE:

    #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to rotate the matrix 90 degrees clockwise using extra space
    vector<vector<int>> rotateClockwise(vector<vector<int>>& matrix) {
        // Get the size of the square matrix
        int n = matrix.size();

        // Create a new matrix of same size to store rotated result
        vector<vector<int>> rotated(n, vector<int>(n));

        // Traverse each element of original matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // Place the element at its new rotated position
                rotated[j][n - i - 1] = matrix[i][j];
            }
        }

        // Return the rotated matrix
        return rotated;
    }
};

OPTIMAL:

Step 1: Transpose the matrix: swap elements across the diagonal. This converts rows into columns.
Step 2: Reverse each row: this turns the new columns into the final rotated rows.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to rotate matrix 90 degrees clockwise in-place
    void rotateClockwise(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // Step 1: Transpose the matrix
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                // Swap element at (i, j) with (j, i) to transpose
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Step 2: Reverse each row
        for (int i = 0; i < n; ++i) {
            // Reverse the current row to complete clockwise rotation
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

//TC: Same for both
//SC: O(N^2) for first; O(1) for second



