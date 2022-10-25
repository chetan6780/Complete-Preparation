# [Distinct Subsequences](https://leetcode.com/problems/distinct-subsequences/) 🌟🌟🌟

Given two strings s and t, return the number of distinct subsequences of s which equals t.

A string's subsequence is a new string formed from the original string by deleting some (can be none) of the characters without disturbing the remaining characters' relative positions. (i.e., "ACE" is a subsequence of "ABCDE" while "AEC" is not).

The test cases are generated so that the answer fits on a 32-bit signed integer.

### Recursive Approach

-   `f(i,j)` represents the number of subsequences of `t[0..j]` present in `s[0..i]`.
-   On index (i,j) if characters of both string matches we have two options:
    -   Take the character from `s` and `t` and move forward in both strings.
    -   Take the character from `s` and move forward in `s` only.
-   If characters don't match we have only one option:
    -   To reduce search space in `s`. So we move forward in `s` only.

### Code

```cpp
class Solution {
    int f(int i, int j, string& s, string& t)
    {
        if (j < 0) return 1;
        if (i < 0) return 0;

        if (s[i] == t[j]) {
            int take = f(i - 1, j - 1, s, t);
            int notTake = f(i - 1, j, s, t);
            return take + notTake;
        }
        int reduce = f(i - 1, j, s, t);
        return reduce;
    }

public:
    int numDistinct(string s, string t)
    {
        int n = s.size(), m = t.size();
        return f(n - 1, m - 1, s, t);
    }
};
```

### Memoization(Top-Down)

-   To reduce time complexity we use memoization.
-   Notice here on leetcode taking int or long long will result in overflow, So take double to avoid overflow.
-   Also pass string by reference and not by value.
-   In Code-2 we have used 1 based indexing for dp table to simplify the code which will help us in tabulation.

### Code-1

```cpp
class Solution {
    int f(int i, int j, string& s, string& t, vector<vector<double>>& dp)
    {
        if (j < 0) return 1;
        if (i < 0) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == t[j]) {
            int take = f(i - 1, j - 1, s, t, dp);
            int notTake = f(i - 1, j, s, t, dp);
            return dp[i][j] = take + notTake;
        }
        int reduce = f(i - 1, j, s, t, dp);
        return dp[i][j] = reduce;
    }

public:
    int numDistinct(string s, string t)
    {
        int n = s.size(), m = t.size();
        vector<vector<double>> dp(n, vector<double>(m, -1));
        return f(n - 1, m - 1, s, t, dp);
    }
};
```

### Code-2

```cpp
class Solution {
    int f(int i, int j, string& s, string& t, vector<vector<double>>& dp)
    {
        if (j == 0) return 1;
        if (i == 0) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        if (s[i - 1] == t[j - 1]) {
            int take = f(i - 1, j - 1, s, t, dp);
            int notTake = f(i - 1, j, s, t, dp);
            return dp[i][j] = take + notTake;
        }
        int reduce = f(i - 1, j, s, t, dp);
        return dp[i][j] = reduce;
    }

public:
    int numDistinct(string s, string t)
    {
        int n = s.size(), m = t.size();
        vector<vector<double>> dp(n + 1, vector<double>(m + 1, -1));
        return f(n, m, s, t, dp);
    }
};
```

### Tabulation(Bottom-Up)

-   For the 0'th column we can fill the whole row with 1's because we can make empty string from any string.
-   Other rows and columns are filled in the same way as recursive approach.
-   **TC: O(n\*m)**
-   **SC: O(n\*m)**

### Code

```cpp
class Solution {
public:
    int numDistinct(string s, string t)
    {
        int n = s.size();
        int m = t.size();
        vector<vector<double>> dp(n + 1, vector<double>(m + 1, 0));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = m; j >= 1; j--) { // both reverse and normal order works
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return (int)dp[n][m];
    }
};
```

### Space Optimized Tabulation

-   We can observe that we are using only the previous row to fill the current row.
-   So we can reduce space complexity to O(m) by using only two rows.
-   **TC: O(n\*m)**
-   **SC: O(m)**, 2 arrays of size m.

### Code

```cpp
class Solution {
public:
    int numDistinct(string s, string t)
    {
        int n = s.size(), m = t.size();
        vector<double> prev(m + 1, 0), curr(m + 1, 0);

        prev[0] = curr[0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = m; j >= 1; j--) {
                if (s[i - 1] == t[j - 1]) {
                    curr[j] = prev[j - 1] + prev[j];
                } else {
                    curr[j] = prev[j];
                }
            }
            prev = curr;
        }
        return (int)prev[m];
    }
};
```

### Space Optimized Tabulation 1 Array

-   We are calculating `current[i] = prev[i] + prev[i-1]`, so instead for storing it into `current[i]` we can store it as `prev[i]` as we are not using `prev[i]` in future(it will become `prev[i+1]` for next iteration).
-   **TC: O(n\*m)**
-   **SC: O(m)**, 1 array of size m.

```cpp
class Solution {
public:
    int numDistinct(string s, string t)
    {
        int n = s.size(), m = t.size();
        vector<double> dp(m + 1, 0);

        dp[0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = m; j >= 1; j--) {
                if (s[i - 1] == t[j - 1]) {
                    dp[j] = dp[j - 1] + dp[j];
                }
            }
        }
        return (int)dp[m];
    }
};
```
