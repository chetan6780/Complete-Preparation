# [Coin change II](https://www.codingninjas.com/codestudio/problems/ways-to-make-coin-change_630471?leftPanelTab=0) 🌟🌟

### Solution

-   Same as [minimum elements](./20_MinimumElements.md) problem.
-   Just need some changes.
-   for base case store if cost is divisible by arr[0] or not.
-   In take case don't add 1 to ans.
-   Take addition of take and non take case.
-   return `dp[n-1][cost]` OR `prev[cost]`.
-   All solutions of minimum elements with above modifications will work.

### Code

```cpp
long countWaysToMakeChange(int* den, int n, int x)
{
    vector<long> prev(x + 1, 0), curr(x + 1, 0);
    for (int T = 0; T <= x; T++) {
        prev[T] = (T % den[0] == 0); // changed here
    }
    for (int i = 1; i < n; i++) {
        for (int T = 0; T <= x; T++) {
            long notTake = prev[T];
            long take = 0;
            if (den[i] <= T) take = curr[T - den[i]]; // changed here
            curr[T] = take + notTake; // changed here
        }
        prev = curr;
    }
    return prev[x]; // changed here
}
```
