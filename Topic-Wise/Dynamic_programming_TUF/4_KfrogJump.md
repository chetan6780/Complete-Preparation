# [ Frog Jump follow up]()

Prerequisite [frog jump](./3_frogJump.md).

**What if K step can be jumped?**

### Solution Explanation

-   for max 2 jump we were calculating min of
    **min(**
    `f(i-1)+abs(h[i]-h[i-1])` ,
    `if(i>1)`:`f(i-2)+abs(h[i]-h[i-2])`
    **)**
-   for max k jump we will take min of all k jumps.
    **min(**
    `f(i-1)+abs(h[i]-h[i-1])` ,
    `if(i>1)`:`f(i-2)+abs(h[i]-h[i-2])`,
    `if(i>2)`:`f(i-3)+abs(h[i]-h[i-3])`,
    `if(i>3)`:`f(i-4)+abs(h[i]-h[i-4])`,
    .
    .
    .
    `if(i>k-1)`:`f(i-k)+abs(h[i]-h[i-k])`
    **)**
    where **k is jump size**.
-   We can simulate the above process in recursive solution by just adding **for loop for [1,k]**.

---

### Recursive Solution

-   You can test this solution on codestudio by putting `k=2`.
-   It will be timed out as it is calculating same subproblems again and again.

### Code

```cpp
// TESTED OK but TLE
int helper(int n, vector<int>& heights, int k, int i)
{
    if (i == 0) return 0;

    int res = INT_MAX;
    for(int jump=1;jump<=k;jump++)
    {
        if(i>jump-1)
        {
            res = min(res,helper(n, heights, k, i - jump) + abs(heights[i - jump] - heights[i]));
        }
    }

    return res;
}

int frogJump(int n, vector<int>& heights)
{
    int k = 2;
    return helper(n, heights, k, n - 1);
}
```

### Memoized Solution (Top-Down)

-   We just need to add memoization array , store and retrieve values.

### Code

```cpp
// TESTED OK AC
int helper(int n, vector<int>& heights, vector<int>& memo, int k, int i)
{
    if (i == 0)
        return 0;

    if (memo[i] != -1) return memo[i];

    int res = INT_MAX;
    for (int jump = 1; jump <= k; jump++)
    {
        if (i > jump - 1)
        {
            res = min(res, helper(n, heights, memo, k, i - jump)
            + abs(heights[i - jump] - heights[i]));
        }
    }

    return memo[i] = res;
}

int frogJump(int n, vector<int>& heights)
{
    int k = 2;
    vector<int> memo(n + 1, -1);
    return helper(n, heights, memo, k, n - 1);
}
```

### Tabulation Solution (Bottom-Up)

-   We Just need to add for loop other code is same.

### Code-1

```cpp
// TESTED OK AC
int frogJump(int n, vector<int>& heights)
{
    int k = 2;
    vector<int> dp(n, 0);
    dp[0] = 0;
    for (int i = 1; i < n; i++) {
        int maxJump = INT_MAX;
        for(int jump=1;jump<=k;jump++){
            if(i>jump-1)
            {
                int currJump = dp[i-jump] + abs(heights[i-jump] - heights[i]);
                maxJump = min(currJump, maxJump);
            }
        }
        dp[i] = maxJump;
    }
    return dp[n - 1];
}
```

### Code-2

```cpp
// TESTED OK AC
int frogJump(int n, vector<int>& heights)
{
    int k = 2;
    vector<int> dp(n, 0);
    dp[0] = 0;
    for (int i = 1; i < n; i++) {
        dp[i] = INT_MAX;
        for (int jump = 1; jump <= k; jump++) {
            if (i > jump - 1)
            {
                int currJump = dp[i - jump] + abs(heights[i - jump] - heights[i]);
                dp[i] = min(dp[i], currJump);
            }
        }
    }
    return dp[n - 1];
}
```

### Space optimized Tabulation Solution (Bottom-Up)

-   Space can be optimized from **O(N)** to **O(K)**.
-   We just need to have vector of previous k values for computation.
-   The code is not necessary.
