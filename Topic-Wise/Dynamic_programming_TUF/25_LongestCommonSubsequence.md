# [Longest common subsequence](https://www.codingninjas.com/codestudio/problems/longest-common-subsequence_1063255) 🌟🌟

### Recursive Approach

-   If current character both strings matches, then we can move both the indexes by 1.
-   If they don't match then we try moving one index at a time and get maximum of both.
-   The base case arises when we move out of bound, return 0 in that case.

### Code

```cpp
int f(string& a, string& b, int i, int j)
{
    if (i < 0 || j < 0) return 0;

    if (a[i] == b[j]) return 1 + f(a, b, i - 1, j - 1);
    return dp[i][j] = max(f(a, b, i, j - 1), f(a, b, i - 1, j));
}

int getLengthOfLCS(string& str1, string& str2)
{
    int n = str1.size(), m = str2.size();
    return f(str1, str2, n - 1, m - 1);
}
```

### Memoization

-   We can easily memoize the recursive solution.
-   **TC: O(n\*m)**
-   **SC: O(n\*m)**

### Code

```cpp
int f(string& a, string& b, int i, int j, vector<vector<int>>& dp)
{
    if (i < 0 || j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (a[i] == b[j])
        return 1 + f(a, b, i - 1, j - 1, dp);
    return dp[i][j] = max(f(a, b, i, j - 1, dp), f(a, b, i - 1, j, dp));
}

int getLengthOfLCS(string& str1, string& str2)
{
    int n = str1.size(), m = str2.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return f(str1, str2, n - 1, m - 1, dp);
}
```

### Tabulation

-   We can see in memoization the base case was only for out of bound, here we can't check for out, so we just shift the indexes by 1 and give 0 for the first row and column(Replica of base case for out of bound).
-   Other recursive relation and be simply applied.
-   **TC: O(n\*m)**
-   **SC: O(n\*m)**

### Code

```cpp
int getLengthOfLCS(string& a, string& b)
{
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    // 0'th row and 0'th column are already 0, we can skip them
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }

    return dp[n][m];
}
```

### Space Optimized Tabulation

-   we need only previous row to calculate current row, so we can reduce space complexity to only O(m).
-   ```
      dp[i-1] = prev
      dp[i] = curr
    ```
-   **TC: O(n\*m)**
-   **SC: O(m)**

### Code

```cpp
int getLengthOfLCS(string& a, string& b)
{
    int n = a.size(), m = b.size();
    vector<int> prev(m + 1, 0), curr(m + 1, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1])
                curr[j] = 1 + prev[j - 1];
            else
                curr[j] = max(curr[j - 1], prev[j]);
        }
        prev = curr;
    }

    return prev[m];
}
```
