# [518. Coin Change 2](https://leetcode.com/problems/coin-change-2/) 🌟🌟

You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

You may assume that you have an infinite number of each kind of coin.

The answer is **guaranteed** to fit into a signed **32-bit** integer.

### Recursive Solution (TLE)

-   For a i'th coin in coins, we can either use it or not use it.
-   If the ith coin is less than or equal to the amount, we can use it or not use it.
-   else, ith coin is greater than amount we cannot use it.
-   Since we want to find the number of combinations, we add both include and exclude the ith coin.

### Code

```cpp
class Solution {
private:
    int changeRec(int amount, vector<int>& coins, int i)
    {
        if (amount == 0) return 1;
        if (i < 0) return 0;

        int include = 0, notInclude = 0;
        if (coins[i] <= amount) {
            include = changeRec(amount - coins[i], coins, i);
            notInclude = changeRec(amount, coins, i - 1);
        } else {
            notInclude = changeRec(amount, coins, i - 1);
        }

        return include + notInclude;
    }

public:
    int change(int amount, vector<int>& coins)
    {
        int n = coins.size();
        return changeRec(amount, coins, n - 1);
    }
};
```

### Memoization (AC)

-   The recursive solution calculates same sub-problem multiple times.
-   We can use memoization to avoid this.
-   **TC: O(N \* amount)**
-   **SC: O(N \* amount)**

### Code

```cpp
class Solution {
private:
    vector<vector<int>> dp;
    int changeRec(int amount, vector<int>& coins, int i)
    {
        if (amount == 0) return 1;
        if (i <= 0) return 0;

        if (dp[i][amount] != -1)
            return dp[i][amount];

        int include = 0, notInclude = 0;
        if (coins[i - 1] <= amount) {
            include = changeRec(amount - coins[i - 1], coins, i);
            notInclude = changeRec(amount, coins, i - 1);
        } else {
            notInclude = changeRec(amount, coins, i - 1);
        }

        return dp[i][amount] = include + notInclude;
    }

public:
    int change(int amount, vector<int>& coins)
    {
        int n = coins.size();
        dp.resize(n + 1, vector<int>(amount + 1, -1));
        return changeRec(amount, coins, n);
    }
};
```

### Tabulation (AC)

-   Iterative DP.
-   **TC: O(N \* amount)**
-   **SC: O(N \* amount)**

### Code-1

```cpp
class Solution {
public:
    int change(int amount, vector<int>& coins)
    {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));
        for (int i = 0; i < n + 1; i++) {
            for (int j = 0; j < amount + 1; j++) {
                if (i == 0)
                    dp[i][j] = 0;
                else if (j == 0)
                    dp[i][j] = 1;
                else {
                    int include = 0, notInclude = 0;
                    if (coins[i - 1] <= j) {
                        include = dp[i][j - coins[i - 1]];
                        notInclude = dp[i - 1][j];
                    } else {
                        notInclude = dp[i - 1][j];
                    }
                    dp[i][j] = include + notInclude;
                }
            }
        }
        return dp[n][amount];
    }
};
```

### Code-2

```cpp
class Solution {
public:
    int change(int amount, vector<int>& coins)
    {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));
        for (int i = 0; i < n + 1; i++) {
            dp[i][0] = 1;
        }
        for (int j = 0; j < amount + 1; j++) {
            dp[0][j] = 0;
        }
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < amount + 1; j++) {
                int include = 0, notInclude = dp[i - 1][j];
                if (coins[i - 1] <= j) {
                    include = dp[i][j - coins[i - 1]];
                }
                dp[i][j] = include + notInclude;
            }
        }
        return dp[n][amount];
    }
};
```

### Code-3

```cpp
class Solution {
public:
    int change(int amount, vector<int>& coins)
    {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));
        for (int i = 0; i < n + 1; i++) {
            dp[i][0] = 1;
        }
        for (int j = 0; j < amount + 1; j++) {
            dp[0][j] = 0;
        }
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < amount + 1; j++) {
                if (coins[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][amount];
    }
};
```
