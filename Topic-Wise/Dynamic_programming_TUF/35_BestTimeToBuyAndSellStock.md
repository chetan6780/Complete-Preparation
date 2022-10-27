# [Best Time to Buy and Sell Stock](https://www.codingninjas.com/codestudio/problems/stocks-are-profitable_893405?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos) 🌟

**ONLY ONE TRANSACTION IS ALLOWED**

### Solution

-   For each day we keep track of the minimum stock price till that day.
-   update the maximum profit if we sell the stock on that day.
-   **TC: O(n)**
-   **SC: O(1)**

### Code

```cpp
int maximumProfit(vector<int>& prices)
{
    int mini = prices[0];
    int maxProfit = 0;
    int n = prices.size();
    for (int i = 1; i < n; i++) {
        int cost = prices[i] - mini;
        maxProfit = max(maxProfit, cost);
        mini = min(mini, prices[i]);
    }
    return maxProfit;
}
```

### Other

-   [Other solutions](../../Leetcode/121_bestTimeToBuyAndSellStock.md) for this problem.
