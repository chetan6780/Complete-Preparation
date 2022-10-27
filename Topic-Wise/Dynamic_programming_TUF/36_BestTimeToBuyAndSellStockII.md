# [Best Time to Buy and Sell Stock II](https://www.codingninjas.com/codestudio/problems/selling-stock_630282?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos) 🌟🌟

**UNLIMITED TRANSACTIONS ARE ALLOWED BUT THEY SHOULD NOT OVERLAP**

### Solution

-   I have written detailed solution for this problem on leetcode, Go there and **UPVOTE IT** 😁.
-   [✅ 4 Solutions | Recursion to memoization | Peak & valley | simple explanation](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/discuss/1888672/4-solutions-recurion-to-memoization-peak-valley-simple-explanation)

### Tabulation(bottom-up)

```cpp
long getMaximumProfit(long* values, int n)
{
    vector<vector<long>> dp(n + 1, vector<long>(2, 0));
    dp[n][0] = dp[n][1] = 0;
    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy < 2; buy++) {
            long profit = 0;
            if (buy) {
                long buyStock = -values[ind] + dp[ind + 1][0];
                long dontBuyStock = dp[ind + 1][1];
                profit = max(buyStock, dontBuyStock);
            } else {
                long sellStock = values[ind] + dp[ind + 1][1];
                long dontSellStock = dp[ind + 1][0];
                profit = max(sellStock, dontSellStock);
            }
            dp[ind][buy] = profit;
        }
    }
    return dp[0][1];
}
```

### Space Optimized Tabulation(bottom-up)

```cpp
long getMaximumProfit(long* values, int n)
{
    vector<long> ahead(2, 0), curr(2, 0);
    ahead[0] = ahead[1] = 0;
    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy < 2; buy++) {
            long profit = 0;
            if (buy) {
                long buyStock = -values[ind] + ahead[0];
                long dontBuyStock = ahead[1];
                profit = max(buyStock, dontBuyStock);
            } else {
                long sellStock = values[ind] + ahead[1];
                long dontSellStock = ahead[0];
                profit = max(sellStock, dontSellStock);
            }
            curr[buy] = profit;
        }
        ahead = curr;
    }
    return ahead[1];
}
```

### 4 Variable solution

```cpp
long getMaximumProfit(long* values, int n)
{
    long aheadNotBuy = 0, aheadBuy = 0, currBuy = 0, currNotBuy = 0;

    for (int ind = n - 1; ind >= 0; ind--) {

        long sellStock = aheadNotBuy;
        long dontSellStock = values[ind] + aheadBuy;
        currNotBuy = max(sellStock, dontSellStock);

        long dontBuyStock = -values[ind] + aheadNotBuy;
        long buyStock = aheadBuy;
        currBuy = max(buyStock, dontBuyStock);

        aheadBuy = currBuy;
        aheadNotBuy = currNotBuy;
    }
    return aheadBuy;
}
```

### 4 Variable solution Short

```cpp
long getMaximumProfit(long* values, int n)
{c
}
```

### Note

-   The solutions above might look confusing for first time, but when you solve this problem more times it will become very easy to understand.
-   For reference check out [striver DP-36](https://www.youtube.com/watch?v=nGJmxkUJQGs&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=37&t=1s)
