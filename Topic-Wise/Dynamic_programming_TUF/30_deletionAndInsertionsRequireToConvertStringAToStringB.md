# [Deletions and insertions require to convert string A to B](https://www.codingninjas.com/codestudio/problems/can-you-make_4244510?leftPanelTab=0) 🌟🌟

### Solution

-   Number of deletions required = `size of string A - length of LCS of A and B.`
-   Number of insertions required = `size of string B - length of LCS of A and B.`
-   Total operations are `insertion + deletion - lcs(A,B) = size(A) + size(B) - 2*lcs(A,B)`
-   **TC: O(n\*n)**
-   **SC: O(n\*n)**

### Code

```cpp
int getLengthOfLCS(string& a, string& b)
{
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
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

int canYouMake(string &str, string &ptr)
{
    int lenLCS = getLengthOfLCS(str,ptr);
    int deletions = str.size() - lenLCS;
    int insertions = ptr.size() - lenLCS;
    return deletions + insertions;
}
```
