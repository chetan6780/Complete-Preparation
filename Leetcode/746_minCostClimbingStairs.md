# [746. Min Cost Climbing Stairs](https://leetcode.com/problems/min-cost-climbing-stairs/) 🌟

You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.

### Recursive Solution (TLE)

-   Since we can start from either step `0` or step `1`, the cost to reach these steps is `0`.
-   We can arrive at step `i` from either step `i - 1` or step `i - 2`. Choose whichever one is cheaper.
-   Recurrence Relation:
    `mincost(i) = cost[i]+min(mincost(i-1), mincost(i-2))`
-   Base cases:
    `mincost(0) = cost[0]`
    `mincost(1) = cost[1]`
-   **TC: O(2^N)**

### Code

```cpp

class Solution {
private:
    int minCost(vector<int>& cost, int n)
    {
        if (n == 0 || n == 1) return cost[n];
        return cost[n] + min(minCost(cost, n - 1), minCost(cost, n - 2));
    }

public:
    int minCostClimbingStairs(vector<int>& cost)
    {
        int n = cost.size();
        return min(minCost(cost, n - 1), minCost(cost, n - 2));
    }
};
```

### Memoization (Top-Down) (3ms-AC)

-   Since in recursion we are doing lots of redundant calculations, we can use memoization to speed up the process.
-   We can use a hash table(memo vector) to store the results of the subproblems.
-   Every time if the computation of 'n' is already present return that value, else store new value in memo vector.
-   **TC: O(N)**
-   **SC: O(N)**

### Code

```cpp
class Solution {
private:
    int minCost(vector<int>& cost, vector<int>& memo, int n)
    {
        if (n == 0 || n == 1) return cost[n];
        if (memo[n] != -1) return memo[n];
        return memo[n] = cost[n] + min(minCost(cost, memo, n - 1), minCost(cost, memo, n - 2));
    }

public:
    int minCostClimbingStairs(vector<int>& cost)
    {
        int n = cost.size();
        vector<int> memo(n + 1, -1);
        return min(minCost(cost, memo, n - 1), minCost(cost, memo, n - 2));
    }
};
```

### Tabulation (Bottom-Up) (7ms-AC)

-   We can get rid of that recursive stack with the help of tabulation.
-   **TC: O(N)**
-   **SC: O(N)**

### Code

```cpp
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost)
    {
        int n = cost.size();
        vector<int> dp(n + 1);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < n; i++) {
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }
        return min(dp[n - 1], dp[n - 2]);
    }
};
```

### Reduced space complexity

-   If we observe our recurrence relation, we just using last and second last values, so we can reduce by using only two variables instead of a vector.
-   **TC: O(N)**
-   **SC: O(1)**

### Code

```cpp
class Solution {
private:
public:
    int minCostClimbingStairs(vector<int>& cost)
    {
        int first = cost[0];
        int second = cost[1];

        for (auto currCost : cost) {
            int curr = currCost + min(first, second);
            first = second;
            second = curr;
        }
        return min(first, second);
    }
};
```
