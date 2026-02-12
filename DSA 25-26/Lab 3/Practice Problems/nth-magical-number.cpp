/*
  A positive integer is magical if it is divisible by either a or b.
  Given the three integers n, a, and b, return the nth magical number. 
  Since the answer may be very large, return it modulo 109 + 7.
*/

class Solution {
using ll = long long;
public:
int gcd(int a, int b) { return b == 0? a : gcd)b, a%b); }
    int nthMagicalNumber(int n, int a, int b) {
        ll low = min(a,b);
        ll high = (ll)n*min(a,b);
        ll lcmv = (ll)a*b/gcd(a,b);
        ll mod = 1e9 + 7;

        while(low<=high)
          {
              ll mid = low + (high - low)/2;
              if(mid/a +  mid/b - mid/lcmv < n) low = mid+1;
              else high = mid;
          }
      return low % mod;
    }
};

// TLE MC.
