# [188. Best Time to Buy and Sell Stock IV](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/) 🌟🌟🌟

You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions.

**Note:** You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

### Recursion (TLE)

-   for the i'th day if we are holding a stock we can either sell it or do nothing.
-   if we are not holding a stock we can either buy it or do nothing.
-   The base case arises when we completed all the transactions(k == 0) OR we are done for all days(i == prices.size()).

> Note that you could also set up the solution so that transactions are completed upon buying a stock instead.

**Pseudo code**

```
dp(i, transactionsRemaining, holding) = max(doNothing, sellStock) if holding == 1
                                        otherwise max(doNothing, buyStock)

Where,
doNothing = dp(i + 1, transactionsRemaining, holding),
sellStock = prices[i] + dp(i + 1, transactionsRemaining - 1, 0),
buyStock = -prices[i] + dp(i + 1, transactionsRemaining, 1).
```

![](https://leetcode.com/explore/learn/card/Figures/DP1/C3A5_1.png)

### Code

```cpp
// i = day i, k = transactions, holdings = 0/1
class Solution {
private:
    int maxProfitRec(vector<int>& prices, int k, int i, int holding)
    {
        // if not transactions remaining OR no days remaining(i>=prices.size())
        if (k == 0 || i >= prices.size())
            return 0;

        int doNothing = maxProfitRec(prices, k, i + 1, holding);

        // if holding, sell/not sell
        if (holding) {
            int sellStock = maxProfitRec(prices, k - 1, i + 1, 0) + prices[i];
            return max(doNothing, sellStock);
        } else { // not holding, buy/not buy
            int buyStock = maxProfitRec(prices, k, i + 1, 1) - prices[i];
            return max(doNothing, buyStock);
        }
    }

public:
    int maxProfit(int k, vector<int>& prices)
    {
        return maxProfitRec(prices, k, 0, 0);
    }
};
```

### Memoization (AC)

-   In the recursive version, we have to calculate the same subproblem multiple times.
-   we can reduce the number of subproblems by storing the results of the subproblems.
-   we use 3D array to store the results.
-   **TC : O(N \* K)**
-   **SC : O(N \* K)**

### Code

```cpp
// i = day i, k = transactions, holdings = 0/1
class Solution {
private:
    int dp[1001][101][2];
    int maxProfitRec(vector<int>& prices, int k, int i, int holding)
    {
        // if not transactions remaining OR no days remaining(i>=prices.size())
        if (k == 0 || i >= prices.size())
            return 0;

        // if we have already calculated this state, return it
        if (dp[i][k][holding] != 0)
            return dp[i][k][holding];

        int doNothing = maxProfitRec(prices, k, i + 1, holding);

        // if holding, sell/not sell
        if (holding) {
            int sellStock = maxProfitRec(prices, k - 1, i + 1, 0) + prices[i];
            return dp[i][k][holding] = max(doNothing, sellStock);
        } else { // not holding, buy/not buy
            int buyStock = maxProfitRec(prices, k, i + 1, 1) - prices[i];
            return dp[i][k][holding] = max(doNothing, buyStock);
        }
    }

public:
    int maxProfit(int k, vector<int>& prices)
    {
        return maxProfitRec(prices, k, 0, 0);
    }
};
```

### Tabulation (AC)

-   The recurrence relation is the same with top-down, but we need to be careful about how we configure our for loops.
-   The base cases are automatically handled because the dp array is initialized with all values set to 0.
-   For iteration direction and order, remember with bottom-up we start at the base cases.
-   Therefore we will start iterating from the end of the input and with only 1 transaction remaining.
-   **TC: O(N\*K)**, O(n\*k\*2)--> O(N\*K)
-   **SC: O(N\*K)**, O(n\*k\*2)--> O(N\*K)

### Code

```cpp
// i = day i, k = transactions, holdings = 0/1
class Solution {
public:
    int maxProfit(int k, vector<int>& prices)
    {
        // dp[n+1][k+1][2] = max profit for n days, k transactions, holding 0/1
        int n = prices.size();
        int dp[n + 1][k + 1][2];
        memset(dp, 0, sizeof(dp));

        for (int i = n - 1; i >= 0; i--) { // days from last to first
            for (int transRem = 1; transRem <= k; transRem++) { // transactions remaining
                for (int holding = 0; holding < 2; holding++) { // holding 0/1

                    int doNothing = dp[i + 1][transRem][holding];
                    int doSomething = 0;

                    if (holding == 1) {
                        // Sell stock
                        doSomething = prices[i] + dp[i + 1][transRem - 1][0];
                    } else {
                        // Buy stock
                        doSomething = -prices[i] + dp[i + 1][transRem][1];
                    }

                    // Recurrence relation
                    dp[i][transRem][holding] = max(doNothing, doSomething);
                }
            }
        }

        return dp[0][k][0]; // returns max profit for k transactions
    }
};
```
