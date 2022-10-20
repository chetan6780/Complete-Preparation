# [Frog Jump (Codestudio-Easy)](https://www.codingninjas.com/codestudio/problems/frog-jump_3621012?leftPanelTab=0) :star2:

Frog is on 1st position and wants to reach nth position. In one move, he can jump 1 position or 2 position ahead and the energy lost in those jump will be abs(i'th energy - i-1'th energy) or abs(i'th energy - i-2'th energy) accordingly. Find minimum energy required to reach the desired position (n).

### Recursive Solution

-   Represent problem in form of index.
-   Do all operation on it.
-   For this problem we can say to reach 0'th(1st position) we require 0 energy,`f(0)=0`.
-   If we jump 1 step, energy required will be `f(i-1)+abs(h[i]-h[i-1])`.
-   If we jump 2 steps, energy required will be `f(i-2)+abs(h[i]-h[i-2])`.

```cpp
int helper(int n, vector<int>& heights, int i)
{
    if (i == 0) return 0;

    int left = helper(n, heights, i - 1) + abs(heights[i - 1] - heights[i]);
    int right = INT_MAX;
    if (i > 1) right = helper(n, heights, i - 2) + abs(heights[i - 2] - heights[i]);

    return min(left, right);
}

int frogJump(int n, vector<int>& heights)
{
    return helper(n, heights, n - 1);
}
```

### Memoized Solution (Top-Down)

-   The recursive solution is calculating some subproblems again and again, so we can reduce it using memoization.
-   Take memoization array having size n and value -1 in it.
-   If value is already calculated then, return that value.
-   If value is not yet calculated then, store and return it.
-   **TC: O(N)**
-   **SC: O(N)**

```cpp
int helper(int n, vector<int>& heights, int i, vector<int>& memo)
{
    if (i == 0) return 0;
    if (memo[i] != -1) return memo[i]; // New code part

    int left = helper(n, heights, i - 1, memo) + abs(heights[i - 1] - heights[i]);
    int right = INT_MAX;
    if (i > 1) right = helper(n, heights, i - 2, memo) + abs(heights[i - 2] - heights[i]);

    return memo[i] = min(left, right); // New code part
}

int frogJump(int n, vector<int>& heights)
{
    vector<int> memo(n + 1, -1); // New code part
    return helper(n, heights, n - 1, memo);
}
```

### Tabulation (Bottom-Up)

-   Take dp array of size n with default value 0.
-   In memoization, look at the base case and write it as default value in dp array.
-   Check from where to where recursive step is executed.
-   For above problem it is executing from 1 to n.
-   Write for loop for the same.
-   Update dp array inside the loop.
-   **TC: O(N)**
-   **SC: O(N)**

```cpp
int frogJump(int n, vector<int>& heights)
{
    vector<int> dp(n, 0);
    dp[0] = 0;
    for (int i = 1; i < n; i++) {
        int fs = dp[i - 1] + abs(heights[i] - heights[i - 1]);
        int ss = INT_MAX;
        if (i > 1) ss = dp[i - 2] + abs(heights[i] - heights[i - 2]);
        dp[i] = min(fs, ss);
    }
    return dp[n - 1];
}
```

### Space Optimized DP

-   **TIP**: whenever there is i-1 and i-2 is involved there is always space optimization possible.
-   use **`dp[i-1]=prev1`** and **`dp[i-2]=prev2`** and **`curr=min(fs,ss)`**.
-   So **`return dp[n-1]`** will be **`return prev1`**.

```cpp
int frogJump(int n, vector<int>& heights)
{
    int prev1 = 0;
    int prev2 = 0;
    for (int i = 1; i < n; i++) {
        int fs = prev1 + abs(heights[i] - heights[i - 1]);
        int ss = INT_MAX;
        if (i > 1) ss = prev2 + abs(heights[i] - heights[i - 2]);
        int curr = min(fs, ss);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
```

### Follow Up Question

-   **What if K step can be jumped?**
-   **Solution in [next page](./4_KfrogJump.md)**.
