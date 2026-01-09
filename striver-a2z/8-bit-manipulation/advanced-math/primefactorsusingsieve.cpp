/*

    You are given an integer array queries of length n.
    Return the prime factorization of each number in array queries in sorted order.

    Array Initialization: Initialize an array SPF where each index represents a number, and the value at that index represents the smallest prime factor of the number. Initially, all values are set to 1.

    Sieve of Eratosthenes:
    Iterate through all numbers from 2 to MAX_N (100000 in this case).
    For each prime number found (i.e., numbers whose SPF value is still 1), mark its multiples with the prime number as their smallest prime factor.
    This process ensures that every number up to MAX_N has its smallest prime factor precomputed efficiently.
    Helper Function for Prime Factorization:
    Given a number, repeatedly divide it by its smallest prime factor (obtained from the SPF array) until the number is reduced to 1. Store each smallest prime factor during the division process.

    Handling Multiple Queries:
    The main function takes an array of integers and applies the helper function to each element. The prime factors of each number are stored in a 2D list, where each list corresponds to the prime factors of a number in the input array.

*/

#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100000

/* To store the smallest prime factors for 
all number with all nodes initially 
having smallest prime factor as 1 */
vector<int> SPF(MAX_N + 1, 1);

class Solution{
private:
    /* Function to precompute smallest prime 
    factor using sieve of eratosthenes */
    void sieve() {
        // Iterate on all the number
        for (int i = 2; i <= MAX_N; i++) {
            
            // If the number is a prime number 
            if (SPF[i] == 1) {
                
                /* Mark all its multiples who have not 
                received their smallest prime factor yet*/
                for (int j = i; j <= MAX_N; j += i) {
                    
                    // If smallest prime factor not received yet
                    if (SPF[j]== 1) {
                        
                        /* Store i as the smallest 
                        prime factor for its multiple */
                        SPF[j] = i;
                    }
                }
            }
        }
        
        // Return
        return;
    }

    /* Helper function to find the prime 
    factorization of a number */
    vector<int> primeFact(int n) { 
        
        // To store the result
        vector<int> ans;
        
        // Until the number is not reduced to 1
        while (n != 1) {
            
            // Add the smallest prime factor to the list
            ans.push_back(SPF[n]);
            
            // Update the number
            n = n / SPF[n];
        }
        
        // Return the result
        return ans;
    } 
    
public:

    /* Function to get the prime 
    factorization of all the number */
    vector<vector<int>> primeFactors(vector<int>& queries){
        
        /* Pre compute the smallest 
        possible factor for all numbers */
        sieve();
        
        // To store the answer
        vector<vector<int>> ans;
        
        // Iterate on each number in query
        for(int i=0; i < queries.size(); i++) {
            
            /* Function call to get the prime 
            factorization of current number */
            ans.push_back(primeFact(queries[i]));
        }
        
        // Return the answer
        return ans;
    }
};


/*
    Time Complexity: O(max_N x log(log(max_N))) + O(N x log(num)), where N represents the number of queries, num represents the average number in the queries, and max_N = 10^5.
    The Sieve of Eratosthenes takes O(max_N x log(log(max_N))) to precompute the smallest prime factor for all numbers up to max_N.
    In the worst case, finding the prime factors of a number num takes O(log(num)) time, as the number is divided by its smallest prime factor until it becomes 1.
    For N queries, the total time taken will be O(N x log(num)).

    Space Complexity: O(max_N) + O(N x log(num)), where the SPF array takes O(max_N) space and the space taken by the list to store the result is O(N x log(num)).
*/