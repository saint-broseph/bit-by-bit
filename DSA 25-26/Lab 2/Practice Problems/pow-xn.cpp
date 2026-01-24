/*
  Implement pow(x, n), which calculates x raised to the power n (i.e., xn).
*/

class Solution {
private:
    double power(double x, long long n) {
        if (n == 0) return 1.0;
        if (n == 1) return x;

        if (n % 2 == 0)
             return power(x * x, n / 2);
          return x * power(x * x, (n - 1) / 2);
    }
public:
    double myPow(double x, long long n) {
        long long num = n;
        if (num < 0) {
            x = 1 / x;
            num = -num;
        }
        return power(x, num);
    }
};
