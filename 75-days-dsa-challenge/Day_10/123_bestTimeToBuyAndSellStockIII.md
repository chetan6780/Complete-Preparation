# [123. Best Time to Buy and Sell Stock III](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/) (Hard)

### Recursive Solution (TLE)

-   For a day we have 2 choices, either can buy stock or sell stock.
-   We can do 2 total transactions(buy & sell) that means we have total 4 individual transactions(buy,sell,buy,sell).
-   if we have even transactions remaining then we buy stock else we sell stock.
-   for every day we return maximum of `(doing nothing, buy/sell stock)`.
-   At any point we finish all our transactions we return 0 also if we don't have days left from trading we return 0.
-   **TC: O(2^n)**
-   **SC: O(n)**

### Code

```cpp
class Solution {
private:
    int helper(vector<int>& prices, int n, int day, int transRem)
    {
        // base cases
        if (day == n || transRem == 0)
            return 0;

        // do nothing
        int doNothing = helper(prices, n, day + 1, transRem);
        int doSomething = 0;

        // do something (buy/sell)
        bool buy = (transRem % 2 == 0);
        if (buy) { // buy
            doSomething = -prices[day] + helper(prices, n, day + 1, transRem - 1);
        } else { // sell
            doSomething = prices[day] + helper(prices, n, day + 1, transRem - 1);
        }

        return max(doNothing, doSomething);
    }

public:
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();
        return helper(prices, n, 0, 4);
    }
};
```

### Memoization (AC)

-   The recursive solution giving TLE because of so many subproblems calculated again and again.
-   We can remember the result of subproblems in dp array.
-   If we already calculated the result of subproblems then we can directly return the result, else we store new calculations in table.
-   **TC: O(N)**
-   **SC: O(N)**

### Code

```cpp
class Solution {
private:
    int helper(vector<int>& prices, int n, int day, int transRem, vector<vector<int>>& dp)
    {
        // base cases
        if (day == n || transRem == 0)
            return 0;

        // if we have already calculated the result, return it
        if (dp[day][transRem] != -1)
            return dp[day][transRem];

        // do nothing
        int doNothing = helper(prices, n, day + 1, transRem, dp);
        int doSomething = 0;

        // do something (buy/sell)
        bool buy = (transRem % 2 == 0);
        if (buy) { // buy
            doSomething = -prices[day] + helper(prices, n, day + 1, transRem - 1, dp);
        } else { // sell
            doSomething = prices[day] + helper(prices, n, day + 1, transRem - 1, dp);
        }

        return dp[day][transRem] = max(doNothing, doSomething);
    }

public:
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(5, -1));
        return helper(prices, n, 0, 4, dp);
    }
};
```

### Tabulation (AC)

-   Tabulation starts from base cases as its the bottom up approach.
-   from memoization solution we can write tabulation method easily
-   **TC: O(N)**
-   **SC: O(N)**

### Code

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(5, 0));
        for (int i = n; i >= 0; i--) {
            for (int j = 0; j < 5; j++) {
                if (i == n || j == 0) {
                    dp[i][j] = 0;
                } else {
                    int doNothing = dp[i + 1][j];
                    int doSomething = 0;
                    bool buy = (j % 2 == 0);
                    if (buy) { // buy
                        doSomething = -prices[i] + dp[i + 1][j - 1];
                    } else { // sell
                        doSomething = prices[i] + dp[i + 1][j - 1];
                    }
                    dp[i][j] = max(doNothing, doSomething);
                }
            }
        }
        return dp[0][4];
    }
};
```

### Tabulation | space optimization (AC)

-   We can observe that, for any day we just need the answers of the next day, so we can reduce space complexity to O(1).
-   **TC: O(N)**
-   **SC: O(1)**

### Code

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(2, vector<int>(5, 0));
        for (int i = n; i >= 0; i--) {
            for (int j = 0; j < 5; j++) {
                if (i == n || j == 0) {
                    dp[i % 2][j] = 0;
                } else {
                    int doNothing = dp[(i + 1) % 2][j];
                    int doSomething = 0;
                    bool buy = (j % 2 == 0);
                    if (buy) { // buy
                        doSomething = -prices[i] + dp[(i + 1) % 2][j - 1];
                    } else { // sell
                        doSomething = prices[i] + dp[(i + 1) % 2][j - 1];
                    }
                    dp[i % 2][j] = max(doNothing, doSomething);
                }
            }
        }
        return dp[0][4];
    }
};
```
