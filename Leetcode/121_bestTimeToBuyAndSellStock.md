# [121. Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/) 🌟

You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

---

### O(N^2) Time and O(1) Space

-   Brute force:
-   For each day, find the max profit that can be made by buying at that day and selling at the next j days.

### Code

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit=0;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                maxProfit=max(maxProfit,prices[j]-prices[i]);
            }
        }
        return maxProfit;
    }
};
```

---

### O(N) Time and O(N) Space

-   We try to sell stock each day.
-   For each day from last we store maximum stock price that will appear.
-   then for each day we calculate by selling the stock.

### Code

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit = 0;
        vector<int> futureMax(n);
        futureMax[n-1] = prices[n-1];
        for(int i=n-2; i>=0; i--) {
            futureMax[i] = max(prices[i], futureMax[i + 1]);
        }
        for(int i=0; i<n; i++) {
            maxProfit = max(maxProfit, futureMax[i] - prices[i]);
        }
        return maxProfit;
    }
};
```

---

### O(N) Time and O(1) Space

-   We try to buy stock each day.
-   For each day we keep track of the minimum price of the stock that appeared before it.
-   if todays stock price is minimum we will update it.
-   return max profit.

### Code

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit=0,minStockPrice=1e9;
        for(int i=0;i<n;i++){
            maxProfit=max(maxProfit,prices[i]-minStockPrice);
            minStockPrice=min(minStockPrice,prices[i]);
        }
        return maxProfit;
    }
};
```

### The inner for loop can be optimized and will require 33% less time.

-   If the price of the stock that day less than minimum price so far then there is no chance to get profit so we only update minimum price.
-   else we can get profit, update maxProfit.

### Code

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit=0,minStockPrice=1e9;
        for(int i=0;i<n;i++){ // 33% faster
            if(minStockPrice>prices[i])
                minStockPrice=prices[i];
            else
                maxProfit=max(maxProfit,prices[i]-minStockPrice);
        }
        return maxProfit;
    }
};

```
