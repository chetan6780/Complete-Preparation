# [309. Best Time to Buy and Sell Stock with Cooldown](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/) 🌟🌟

You are given an array prices where `prices[i]` is the price of a given stock on the `ith` day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

-   After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).

**Note:** You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

### Recursive Solution (TLE)

-   For ith day we can `doNothing` or `buyOrSell`.
-   `doNothing` is simple we just move to next day with current states.
-   For `buyOrSell`:
    -   if we can buy then we can choose from `doNothing` or `sell`
        -   To buy, we have to subtract the price from the current balance and move to next day where we cannot buy again.
    -   if we can sell then we can choose from `doNothing` or `buy`
        -   To sell, we have to add the price to the current balance and rest 1 day(cooldown).
        -   then for `i+2`nd day we can again buy.
    -   We choose the max of `doNothing` and `buyOrSell`
-   **TC: O(2^N)**
-   **SC: O(N)**

### Code

```cpp
class Solution {
private:
    int maxProfitRec(vector<int>& prices, int i, bool buy)
    {
        if (i >= prices.size()) {
            return 0;
        }

        int doNothing = maxProfitRec(prices, i + 1, buy);
        int buyOrSell = 0;

        if (buy) {
            // buy, we cannot buy next day
            buyOrSell = -prices[i] + maxProfitRec(prices, i + 1, false);
        } else {
            // sell, now we can buy after 1 cooldown day i.e.(i+2)'th day
            buyOrSell = prices[i] + maxProfitRec(prices, i + 2, true); // NOTE: i+2
        }

        return max(doNothing, buyOrSell);
    }

public:
    int maxProfit(vector<int>& prices){
        return maxProfitRec(prices, 0, true);
    }
};
```

### Memoization (AC)

-   We can easily convert recursive code to memoized code with 2-3 extra lines.
-   Fill dp array with -1.
-   If we already calculated the value for i, then return it.
-   else calculate and store new value.
-   **TC: O(N)**, O(N\*2)-->O(N)
-   **SC: O(N)**, O(N\*2)-->O(N)

### Code

```cpp
class Solution {
private:
    int dp[5001][2];
    int maxProfitRec(vector<int>& prices, int i, bool buy)
    {
        if (i >= prices.size()) {
            return 0;
        }

        // if we have already calculated the result, return it
        if (dp[i][buy] != -1) {
            return dp[i][buy];
        }

        int doNothing = maxProfitRec(prices, i + 1, buy);
        int buyOrSell = 0;

        if (buy) {
            // buy, we cannot buy next day
            buyOrSell = -prices[i] + maxProfitRec(prices, i + 1, false);
        } else {
            // sell, now we can buy after 1 cooldown day i.e.(i+2)'th day
            buyOrSell = prices[i] + maxProfitRec(prices, i + 2, true); // NOTE: i+2
        }

        return dp[i][buy] = max(doNothing, buyOrSell);
    }

public:
    int maxProfit(vector<int>& prices)
    {
        memset(dp, -1, sizeof(dp));
        return maxProfitRec(prices, 0, true);
    }
};
```

### Tabulation (AC)

-   For iteration direction and order, remember with bottom-up we start at the base cases.
-   Therefore we will start iterating from the end of the input.
-   **TC: O(N)**
-   **SC: O(N)**

### Code

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();
        int dp[n + 2][2]; // NOTE: n+2 for i+2

        for (int i = n + 1; i >= 0; i--) {
            for (int buy = 0; buy < 2; buy++) {
                if (i >= n) {
                    dp[i][buy] = 0;
                } else {
                    int doNothing = dp[i + 1][buy];
                    int buyOrSell = 0;
                    if (buy) {
                        // buy, we cannot buy next day
                        buyOrSell = -prices[i] + dp[i + 1][0];
                    } else {
                        // sell, we can buy after 1 cooldown day i.e.(i+2)'th day
                        buyOrSell = prices[i] + dp[i + 2][1];
                    }
                    dp[i][buy] = max(doNothing, buyOrSell);
                }
            }
        }
        return dp[0][1];
    }
};
```

### Space optimized dp

-   For any day, we just need the answers for the next 2 days i.e day + 1 and day + 2.
-   which means that we need to store the answers of 3 states (day, day + 1, day + 2).
-   That's why we have taken an Array of [3][2] always and did modulo by 3.
-   **TC: O(N)**
-   **SC: O(1)**

### Code

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();
        int dp[3][2]; // 3 states (day, day + 1, day + 2).
        memset(dp, 0, sizeof(dp));

        for (int i = n - 1; i >= 0; i--) { // NOTE: start from n-1
            for (int buy = 0; buy < 2; buy++) {
                int doNothing = dp[(i + 1) % 3][buy];
                int buyOrSell = 0;

                if (buy) {
                    // buy, we cannot buy next day
                    buyOrSell = -prices[i] + dp[(i + 1) % 3][0];
                } else {
                    // sell, we can buy after 1 cooldown day i.e.(i+2)'th day
                    buyOrSell = prices[i] + dp[(i + 2) % 3][1];
                }
                dp[i % 3][buy] = max(doNothing, buyOrSell);
            }
        }
        return dp[0][1];
    }
};
```
