# [Edit Distance](https://www.codingninjas.com/codestudio/problems/edit-distance_630420?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0) 🌟🌟🌟

### Recursive Approach

-   For an index if both characters match we don't need to do anything and move to next index.
-   If both characters don't match we have 3 options:
    -   `Insert` the character i.e. move to `f(i, j-1)`
    -   `Delete` the character i.e. move to `f(i-1, j)`
    -   `Replace` the character i.e. move to `f(i-1, j-1)`
-   In all above cases we have done 1 operation, so take `1` and `minimum of all 3 cases`.
-   base case: if any of the string is empty, then return the length of the other string.
-   In code 2 we have just used 1 based indexing which will help us in tabulation.

### Code-1

```cpp
int f(string& s, string& t, int i, int j)
{
    if (i < 0) return j + 1;
    if (j < 0) return i + 1;

    if (s[i] == t[j]) return f(s, t, i - 1, j - 1);

    int insert = f(s, t, i, j - 1);
    int del = f(s, t, i - 1, j);
    int replace = f(s, t, i - 1, j - 1);

    return 1 + min(insert, min(del, replace));
}

int editDistance(string str1, string str2)
{
    int n = str1.size(), m = str2.size();
    return f(str1, str2, n - 1, m - 1);
}
```

### Code-2

```cpp
int f(string& s, string& t, int i, int j)
{
    // 1 based indexing solution
    if (i == 0) return j;
    if (j == 0) return i;

    if (s[i - 1] == t[j - 1]) return f(s, t, i - 1, j - 1);

    int insert = f(s, t, i, j - 1);
    int del = f(s, t, i - 1, j);
    int replace = f(s, t, i - 1, j - 1);

    return 1 + min(insert, min(del, replace));
}

int editDistance(string str1, string str2)
{
    int n = str1.size(), m = str2.size();
    return f(str1, str2, n, m);
}
```

### Memoization

-   Easy memoization.
-   **TC: O(n\*m)**
-   **SC: O(n\*m)**

### Code

```cpp
int f(string& s, string& t, int i, int j, vector<vector<int>>& dp)
{
    // 1 based indexing solution
    if (i == 0) return j;
    if (j == 0) return i;

    if (dp[i][j] != -1) return dp[i][j];

    if (s[i - 1] == t[j - 1]) return f(s, t, i - 1, j - 1, dp);

    int insert = f(s, t, i, j - 1, dp);
    int del = f(s, t, i - 1, j, dp);
    int replace = f(s, t, i - 1, j - 1, dp);

    return dp[i][j] = 1 + min(insert, min(del, replace));
}

int editDistance(string str1, string str2)
{
    int n = str1.size(), m = str2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return f(str1, str2, n, m, dp);
}
```

### Tabulation(bottom-up)

-   From memoization base case we fill 0'th column with `i` and 0'th row with `j`.
-   Other cells are filled in the same way as memoization.
-   **TC: O(n\*m)**
-   **SC: O(n\*m)**

### Code

```cpp
int editDistance(string str1, string str2)
{
    int n = str1.size(), m = str2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i <= n; i++) dp[i][0] = i;
    for (int j = 0; j <= m; j++) dp[0][j] = j;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
        }
    }
    return dp[n][m];
}
```

### Space optimization

-   ```
      dp[i-1] = prev
      dp[i] = curr
    ```
-   Fill jth column of prev with j(base case 2).
-   Every time update 0th column of curr with i(base case 1).
-   **TC: O(n\*m)**
-   **SC: O(m)**

### Code

```cpp
int editDistance(string str1, string str2)
{
    int n = str1.size(), m = str2.size();
    vector<int> prev(m + 1, 0), curr(m + 1, 0);

    for (int j = 0; j <= m; j++) prev[j] = j; // base case 2

    for (int i = 1; i <= n; i++) {
        curr[0] = i; // base case 1
        for (int j = 1; j <= m; j++) {
            if (str1[i - 1] == str2[j - 1])
                curr[j] = prev[j - 1];
            else
                curr[j] = 1 + min({ prev[j], curr[j - 1], prev[j - 1] });
        }
        prev = curr;
    }
    return prev[m];
}
```
