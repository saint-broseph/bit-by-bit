# DP on Stocks

## Overview
The "Best Time to Buy and Sell Stock" series is a classic sequence of problems that can be beautifully solved using **State Machine Dynamic Programming**. 

Instead of building large 2D or 3D tables, we can solve almost all of these problems in $O(N)$ time and $O(1)$ space by tracking our current "state" on any given day. On any day, you can generally be in one of two main states:
1. **Buy/Hold State (`b`)**: You currently own a stock. You reached this state by either carrying forward a stock you bought earlier, or by buying a new stock today.
2. **Sell/Empty State (`s`)**: You currently do not own a stock. You reached this state by either continuing to hold no stock, or by selling your stock today.

By updating these states simultaneously as we iterate through the prices, we naturally find the maximum profit.

## Problem Summary & Revision Table

| Problem | Constraints | State Variables | Core Recurrence / Logic | Space |
| :--- | :--- | :--- | :--- | :--- |
| **I** | At most 1 transaction. | `b` (buy), `s` (sell) | `b = max(b, -p)`<br>`s = max(s, b + p)` | $O(1)$ |
| **II** | Infinite transactions. | `b` (buy), `s` (sell) | `b = max(b, s - p)`<br>`s = max(s, b + p)` | $O(1)$ |
| **III** | At most 2 transactions. | `b1`, `s1`, `b2`, `s2` | Cascade states sequentially:<br>`b1 = max(b1, -p)`<br>`s1 = max(s1, b1 + p)`<br>`b2 = max(b2, s1 - p)`... | $O(1)$ |
| **IV** | At most $K$ transactions. | Arrays `b[k]`, `s[k]` | Loop $i$ from 1 to $K$:<br>`b[i] = max(b[i], s[i-1] - p)`<br>`s[i] = max(s[i], b[i] + p)` | $O(K)$ |
| **Cooldown** | Infinite trans + 1 Day Cooldown. | `b` (buy), `s` (sell), `r` (rest) | Introduce a resting state `r`.<br>Buy must come from `r`.<br>`b = max(b, r - p)` | $O(1)$ |
| **Fee** | Infinite trans + Transaction Fee. | `b` (buy), `s` (sell) | Subtract `fee` upon selling.<br>`s = max(s, b + p - fee)` | $O(1)$ |

*Note: In all solutions, `p` represents the stock price on the current day. To initialize, `b` is usually set to `-prices[0]` (or negative infinity) and `s` is set to `0`.*
