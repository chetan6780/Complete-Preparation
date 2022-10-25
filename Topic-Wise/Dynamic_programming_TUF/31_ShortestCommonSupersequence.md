# [Shortest Common Supersequence](https://www.codingninjas.com/codestudio/problems/shortest-supersequence_4244493?leftPanelTab=0) 🌟🌟🌟

### Solution

-   length of shortest common supersequence = `length of string A + length of string B - lcs(A,B)`
-   To print SCS we need to observe dp table.
-   If `A[i-1] == B[j-1]` then we need to take that character in our `result` string.
-   else if `if (dp[i - 1][j] > dp[i][j - 1])` then we can take `A[i-1]` OR `B[i-1]` in `result` string.
-   Else take other string's character in `result` string.
-   While traversing if character of any string is remaining take them in `result` string.
-   Reverse `result` string.
-   **TC: O(n\*m)**
-   **SC: O(n\*m)**

```cpp
string shortestSupersequence(string a, string b)
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

    // Finding and printing the shortest common supersequence
    string res = "";
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            res += a[i - 1];
            i--;
            j--;
        }
        else {
            if (dp[i - 1][j] > dp[i][j - 1]) {
                res += a[i - 1];
                i--;
            }
            else {
                res += b[j - 1];
                j--;
            }
        }
    }

    // check if any character of a is left
    while (i > 0) {
        res += a[i - 1];
        i--;
    }

    // check if any character of b is left
    while (j > 0) {
        res += b[j - 1];
        j--;
    }

    // Reverse the string
    reverse(res.begin(), res.end());

    return res;
}
```
