#include <bits/stdc++.h>
using namespace std;

/**
 * Prints the prime factors of a given number n.
 * Uses bitwise AND (&) and right shift (>>) for handling 2s.
 */
void printPrimeFactors(int n) {
    if (n <= 1) {
        cout << "No prime factors for " << n << endl;
        return;
    }

    // 1. Bitwise check for parity: (n & 1) is 0 if n is even
    if ((n & 1) == 0) {
        cout << 2 << " ";
        // Bitwise right shift (n >> 1) is equivalent to n / 2
        while ((n & 1) == 0) {
            n = n >> 1;
        }
    }

    // 2. Standard trial division for odd factors starting from 3
    for (int i = 3; i * i <= n; i = i + 2) {
        while (n % i == 0) {
            cout << i << " ";
            n = n / i;
        }
    }

    // 3. If n is still > 2, the remaining n is prime
    if (n > 2) {
        cout << n;
    }
    cout << endl;
}