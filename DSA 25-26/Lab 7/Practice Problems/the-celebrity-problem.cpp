/*
  Given a square matrix mat[][] of size n x n, where mat[i][j] == 1 means 
  person i knows person j, and mat[i][j] == 0 means person i does not know 
  person j, find the celebrity person where,
  
  A celebrity is defined as someone who:
    Is known by everyone else
    Does not know anyone (except themselves)
  
  Return the index of the celebrity if one exists, otherwise return -1.
  Note: It is guaranteed that mat[i][i] == 1 for all i

  CONCEPT:

  The idea is to use two pointers, one from start and one from the end. 
  Assume the start person is A, and the end person is B. If A knows B, then A 
  must not be the celebrity. Else, B must not be the celebrity. At the end of 
  the loop, only one index will be left as a celebrity. Go through each person 
  again and check whether this is the celebrity. 

  Concept: Find a person who knows no one, but everyone knows them. 
  We can do this in O(N) using an elimination strategy. 
  We assume the input is an NxN adjacency matrix M where M[i][j] == 1 means 
  person i knows person j.
  */

#include <vector>

using namespace std;

int celebrity(vector<vector<int> >& M, int n) {

  int candidate = 0;

  for(int i = 1; i < n; i++)
    {
        if(M[candidate][i] == 1)
          candidate = i;
    }

  for(int i = 0; i < n; i++)
    {
        if( i!= candidate)
        {
          if(M[candidate][i]==1 || M[i][candidate] == 0)
            return -1;
        }
    }
  return candidate;
}





