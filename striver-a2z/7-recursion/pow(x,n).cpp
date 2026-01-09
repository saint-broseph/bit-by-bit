/*
     Implement the power function pow(x, n) , which calculates the x raised to n i.e. xn.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    double power(double x, long n) {
        if (n == 0) return 1.0;
        if (n == 1) return x;
        if (n % 2 == 0) 
            return power(x * x, n / 2);
        return x * power(x, n - 1);
    }
public:
    double myPow(double x, int n) {
        int num = n;
        if (num < 0) 
            return (1.0 / power(x, -1 * num));
        return power(x, num);
    }
};
