# [1143. Longest Common Subsequence](https://leetcode.com/problems/longest-common-subsequence/) 🌟🌟

Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

-   A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

### Recursive Solution (TLE)

-   If last character of both strings are same them we can check for LCS with 1 character less in both strings. and return 1+lcs(1 char less in both strings)
-   else they are not same we return the maximum of 1 char less in first text and 1 char less in second text.
-   We reach to base case when one of i and j are 0, we return 0;
-   **TC: O(2^n)**

### Code

```cpp
class Solution {
private:
    int lcsHelper(string s1, string s2, int i, int j)
    {
        if (i == 0 || j == 0) return 0;
        if (s1[i - 1] == s2[j - 1]) return 1 + lcsHelper(s1, s2, i - 1, j - 1);
        return max(lcsHelper(s1, s2, i - 1, j), lcsHelper(s1, s2, i, j - 1));
    }

public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.size();
        int m = text2.size();
        return lcsHelper(text1, text2, n, m);
    }
};
```

### Memoization (Top-Down) (AC)

-   We can easily memoize the recursive function by using the extra space.
-   make sure you pass by value if you are passing anything like string and vector.
-   **TC: O(nm)**
-   **SC: O(nm)**

### Code

```cpp
class Solution {
    int memo[1001][1001];

private:
    int lcsHelper(string& s1, string& s2, int i, int j)
    {
        if (i == 0 || j == 0) return 0;
        if (memo[i][j] != -1) return memo[i][j];
        if (s1[i - 1] == s2[j - 1]) return memo[i][j] = 1 + lcsHelper(s1, s2, i - 1, j - 1);
        return memo[i][j] = max(lcsHelper(s1, s2, i - 1, j), lcsHelper(s1, s2, i, j - 1));
    }

public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.size();
        int m = text2.size();
        memset(memo, -1, sizeof(memo));
        return lcsHelper(text1, text2, n, m);
    }
};
```

### Tabulation (Bottom-Up) (AC)

-   With the help of memoized code we can visualize the code in a tabular form.
-   Below is the implementation.
-   **TC: O(nm)**
-   **SC: O(nm)**

### Code

```cpp
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.size(), m = text2.size();
        int dp[n + 1][m + 1];
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
                else if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n][m];
    }
};
```
