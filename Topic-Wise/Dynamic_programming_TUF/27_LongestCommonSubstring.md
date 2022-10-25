# [Longest common substring](https://www.codingninjas.com/codestudio/problems/longest-common-substring_1235207?leftPanelTab=0) 🌟🌟

### Solution

-   In longest common subsequence, if character at index doesn't match we were trying to move one index at a time and get maximum of both.
-   But here we don't have that option is it will not be a substring.
-   So in that case we will just assign 0 to that index.
-   To find longes common substring we will just find maximum of all the values in dp table.
-   **TC: O(n\*m)**
-   **SC: O(n\*m)**

### Code

```cpp
int lcs(string &a, string &b){
    int n = a.size(), m = b.size();
    int res = 0;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i==0 || j==0)
                dp[i][j] = 0;
            else if (a[i - 1] == b[j - 1]){
                dp[i][j] = 1 + dp[i - 1][j - 1];
                res = max(res,dp[i][j]); // change here
            }
            else
                dp[i][j] = 0; // change here
        }
    }
    return res;
}
```

### Reduces Code
```cpp
int lcs(string &a, string &b){
    int n = a.size(), m = b.size();
    int res = 0;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]){
                dp[i][j] = 1 + dp[i - 1][j - 1];
                res = max(res,dp[i][j]); 
            }
        }
    }
    return res;
}
```
