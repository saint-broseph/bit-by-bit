/*
  A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbors to the left, right, top, and bottom.
  Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the length 2 array [i,j].
  You may assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.
  You must write an algorithm that runs in O(m log(n)) or O(n log(m)) time.
*/

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
            int a1 = 0, b1 = mat[0].size()-1;
            while(a1<=b1)
              {
                int c1 = a1 + (b1-a1)/2;

                int a2=0;
                for(int i=0; i<mat.size(); i++)
                  {  
                      if(mat[i][c1] > mat[a2][c1])
                        a2 = i;
                  }
                bool leftIsBig = (c1 > 0) && (mat[a2][c1 - 1] > mat[a2][c1]);
                bool rightIsBig = (c1 < mat[0].size() - 1) && (mat[a2][c1 + 1] > mat[a2][c1]);
                
                if (!leftIsBig && !rightIsBig) return {a2, c1}; 
                else if (rightIsBig) a1 = c1 + 1; 
                else b1 = c1 - 1;
              }
      return {-1,-1};
    }
};
