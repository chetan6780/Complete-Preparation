# [97. Interleaving String](https://leetcode.com/problems/interleaving-string/) 🌟🌟

Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.

An interleaving of two strings s and t is a configuration where they are divided into non-empty substrings such that:

-   `s = s1 + s2 + ... + sn`
-   `t = t1 + t2 + ... + tm`
-   `|n - m| <= 1`
-   The interleaving is `s1 + t1 + s2 + t2 + s3 + t3 + ...` or `t1 + s1 + t2 + s2 + t3 + s3 + ...`

**Note:** a + b is the concatenation of strings a and b.

### Recursion (TLE)

-   Self Explanatory.

### Code

```cpp
class Solution {
    bool helper(string& s1, string& s2, string& s3, int i, int j, int k)
    {
        int n = s1.size(), m = s2.size(), l = s3.size();
        if (i == n && j == m && k == l) return true;
        if (i > n || j > m || k > l) return false;

        if (s3[k] == s1[i] && s3[k] == s2[j])
            return helper(s1, s2, s3, i + 1, j, k + 1) || helper(s1, s2, s3, i, j + 1, k + 1);
        else if (s1[i] == s3[k])
            return helper(s1, s2, s3, i + 1, j, k + 1);
        else if (s2[j] == s3[k])
            return helper(s1, s2, s3, i, j + 1, k + 1);
        return false;
    }

public:
    bool isInterleave(string s1, string s2, string s3)
    {
        if (s1.size() + s2.size() != s3.size()) return false;
        return helper(s1, s2, s3, 0, 0, 0);
    }
};
```

### Memoization (AC)

### Code

```cpp
class Solution {
    bool helper(string s1, string s2, string s3, int i, int j, int k, vector<vector<int>>& memo)
    {
        int n = s1.size(), m = s2.size(), l = s3.size();
        if (k == l && j == m && i == n) return true;
        if (i > n || j > m || k > l) return false;
        if (memo[i][j] != -1) return memo[i][j];

        bool ans = false;
        if (s3[k] == s1[i] && s3[k] == s2[j])
            ans = (helper(s1, s2, s3, i + 1, j, k + 1, memo) || helper(s1, s2, s3, i, j + 1, k + 1, memo));
        else if (s1[i] == s3[k])
            ans = helper(s1, s2, s3, i + 1, j, k + 1, memo);
        else if (s2[j] == s3[k])
            ans = helper(s1, s2, s3, i, j + 1, k + 1, memo);

        return memo[i][j] = ans;
    }

public:
    bool isInterleave(string s1, string s2, string s3)
    {
        if(s1.size() + s2.size() != s3.size()) return false;
        vector<vector<int>> memo(s1.size() + 1, (vector<int>(s2.size() + 1, -1)));
        return helper(s1, s2, s3, 0, 0, 0, memo);
    }
};
```

### DP (AC)

### Code

```cpp
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        int n = s1.size(), m = s2.size(), l = s3.size();
        if (n + m != l)
            return false;
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        for (int i = n; i >= 0; i--) {
            for (int j = m; j >= 0; j--) {
                int k = i + j;
                if (i == n && j == m)
                    dp[i][j] = 1;
                else if (s1[i] == s3[k] && s2[j] == s3[k])
                    dp[i][j] = dp[i + 1][j] || dp[i][j + 1];
                else if (s1[i] == s3[k])
                    dp[i][j] = dp[i + 1][j];
                else if (s2[j] == s3[k])
                    dp[i][j] = dp[i][j + 1];
            }
        }
        return dp[0][0];
    }
};
```
