# Introduction to Dynamic Programming

Dynamic Programming (DP) is an algorithmic technique used to solve optimization problems by breaking them down into simpler sub-problems and **storing the answers to these sub-problems** to avoid redundant computations.

---

## Core Approaches in DP

There are two primary approaches to implementing dynamic programming:

| Approach | Type | Description |
| :--- | :--- | :--- |
| **Memoization** | Top-Down | Solves the problem by moving from the main problem down to the base cases. |
| **Tabulation** | Bottom-Up | Solves the problem by moving from the base cases up to the main problem. |

> **Note:** The base case does not always mean a smaller input. It depends entirely on the implementation of the algorithm.

---

## Example: Fibonacci Numbers
The Fibonacci series is represented as: `0, 1, 1, 2, 3, 5, 8, 13, 21, ...`

To find the $n$-th Fibonacci number (using 0-based indexing), we use the recurrence relation:

$$F(n) = F(n-1) + F(n-2)$$

**Base Cases:** * $F(0) = 0$
* $F(1) = 1$

In standard recursion, calling $F(n)$ triggers an exponential time complexity because the program repeatedly recalculates the same sub-problems (known as **overlapping sub-problems**). DP eliminates this overhead.

---

## Part 1: Memoization (Top-Down)

Memoization stores the results of expensive function calls and returns the cached result when the same inputs occur again.

### Steps to Memoize:
1. Create a `dp[n + 1]` array initialized to `-1`.
2. Before calculating a value for `n`, check if `dp[n] != -1`. If true, return the cached value.
3. If not calculated yet, compute it using the recursive relation, store it in `dp[n]`, and then return it.

### Code Implementation (C++)
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fib(int n, vector<int>& dp) {
        // Base case
        if (n <= 1) return n;

        // If already computed, return stored value
        if (dp[n] != -1) return dp[n];

        // Otherwise compute, store, and return
        dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
        return dp[n];
    }
};

int main() {
    int n = 10;
    vector<int> dp(n + 1, -1);
    Solution sol;
    cout << sol.fib(n, dp);
    return 0;
}
```

## Part 2: Tabulation (Bottom-Up)

Tabulation avoids recursion altogether by filling a table iteratively from the base cases up to the desired value. This **prevents additional stack space** allocation.

### Steps to Tabulate:
1. Declare a `dp[]` array of size `n + 1`.
2. Initialize the base cases: `dp[0] = 0` and `dp[1] = 1`.
3. Set up an iterative loop running from index `2` to `n`.
4. For every index, compute `dp[i] = dp[i-1] + dp[i-2]`.

### Code Implementation (C++)

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fib(int n) {
        if (n <= 1) return n;

        // Create and initialize dp array
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = 1;

        // Fill dp array iteratively
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};

int main() {
    int n = 10;
    Solution sol;
    cout << sol.fib(n);
    return 0;
}
```

## Part 3: Space Optimization

Looking closely at the relation `dp[i] = dp[i-1] + dp[i-2]`, we only ever need the **last two values** to calculate the current one. Maintaining an entire array is unnecessary.

### Concept:
* Let `prev` represent `dp[i-1]`
* Let `prev2` represent `dp[i-2]`
* In each iteration, calculate `curr = prev + prev2`.
* Shift the pointers for the next iteration: `prev2` becomes `prev`, and `prev` becomes `curr`.

### Code Implementation (C++)

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;

        int prev2 = 0; // stores fib(n-2)
        int prev = 1;  // stores fib(n-1)
        int curr;

        for (int i = 2; i <= n; i++) {
            curr = prev + prev2;
            prev2 = prev; // Update prev2 for next iteration
            prev = curr;  // Update prev for next iteration
        }
        
        return prev;
    }
};

int main() {
    Solution s;
    int n = 10;
    cout << s.fib(n);
    return 0;
}
```

## Complexity Analysis

* **Time Complexity:** $O(n)$ — The loop runs iteratively from $2$ to $n$, performing constant-time arithmetic operations at each step.
* **Space Complexity:** $O(1)$ — Only using three scalar variables (`prev2`, `prev`, `curr`) instead of allocating an entire array or utilizing recursive stack space.
