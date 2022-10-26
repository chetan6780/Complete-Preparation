# [Wildcard Matching](https://www.codingninjas.com/codestudio/problems/wildcard-pattern-matching_701650?leftPanelTab=0) 🌟🌟🌟

### Recursive Approach

-   `?` matches any single character and `*` matches any sequence of characters (including the empty sequence).
-   If in pattern we encounter `?` then we have only one option, match the character and move forward in both the strings.
-   If we encounter `*` we have 2 choices,
    -   Either take empty sequence and move forward in `pattern`.
    -   Or take one character from string and move forward in `text`.
-   In this case we return `true` if any of the two choices return `true`.
-   There are 3 base cases arise,
    -   If both the strings are empty then return `true`.
    -   If only `pattern` is empty but text is still remaining then return `false`.
    -   If only `text` is empty then return `true` if all the remaining characters in `pattern` are `*`.

### Code

```cpp
bool f(string& pattern, string& text, int i, int j)
{
    if (i < 0 && j < 0) return true;
    if (i < 0 && j >= 0) return false;
    if (j < 0 && i >= 0) {
        for (int k = 0; k <= i; k++) {
            if (pattern[k] != '*')
                return false;
        }
        return true;
    }

    if (pattern[i] == text[j] || pattern[i] == '?')
        return f(pattern, text, i - 1, j - 1);
    if (pattern[i] == '*'){
        int takeEmptyAndMove = f(pattern, text, i - 1, j);
        int takeOneCharAndStay = f(pattern, text, i, j - 1);
        return (takeEmptyAndMove || takeOneCharAndStay);
    }

    return false;
}

bool wildcardMatching(string pattern, string text)
{
    int n = pattern.size(), m = text.size();
    return f(pattern, text, n - 1, m - 1);
}
```

### Memoization

-   To reduce the time complexity we can store the results of the subproblems in a 2D array and use it later.
-   **TC: O(n\*m)**
-   **SC: O(n\*m)**

### Code-1

```cpp
bool f(string& pattern, string& text, int i, int j, vector<vector<int>>& dp)
{
    if (i < 0 && j < 0) return true;
    if (i < 0 && j >= 0) return false;
    if (j < 0 && i >= 0) {
        for (int k = 0; k <= i; k++) {
            if (pattern[k] != '*')
                return false;
        }
        return true;
    }

    if (dp[i][j] != -1) return dp[i][j];

    if (pattern[i] == text[j] || pattern[i] == '?')
        return dp[i][j] = f(pattern, text, i - 1, j - 1, dp);
    if (pattern[i] == '*') {
        int takeEmptyAndMove = f(pattern, text, i - 1, j, dp);
        int takeOneCharAndStay = f(pattern, text, i, j - 1, dp);
        return dp[i][j] = (takeEmptyAndMove || takeOneCharAndStay);
    }

    return dp[i][j] = false;
}

bool wildcardMatching(string pattern, string text)
{
    int n = pattern.size(), m = text.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return f(pattern, text, n - 1, m - 1, dp);
}
```

### Code-2

-   Here we have used 1 based indexing to help us in further tabulation optimization.

```cpp
bool f(string& pattern, string& text, int i, int j, vector<vector<int>>& dp)
{
    // One based indexing
    if (i == 0 && j == 0) return true;
    if (i == 0 && j > 0) return false; // remember j>=0 became j>0
    if (j == 0 && i > 0) {
        for (int k = 1; k <= i; k++) {
            if (pattern[k - 1] != '*')
                return false;
        }
        return true;

    }


    if (dp[i][j] != -1) return dp[i][j];

    if (pattern[i - 1] == text[j - 1] || pattern[i - 1] == '?')
        return dp[i][j] = f(pattern, text, i - 1, j - 1, dp);
    if (pattern[i - 1] == '*') {
        int takeEmptyAndMove = f(pattern, text, i - 1, j, dp);
        int takeOneCharAndStay = f(pattern, text, i, j - 1, dp);
        return dp[i][j] = (takeEmptyAndMove || takeOneCharAndStay);
    }
    return dp[i][j] = false;
}

bool wildcardMatching(string pattern, string text)
{
    int n = pattern.size(), m = text.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return f(pattern, text, n, m, dp);
}
```

### Tabulation(Bottom-Up)

-   As base case 1 in memoization suggest when `i` and `j` both are `0` we can `return true`, so `dp[0][0] = true;`
-   As per base case 2, when `i` is `0` and `j` is greater than 0, we can `return false`, so fill first row with `false`.Here we don't need to do it as we have already initialized the dp array with `false`.
-   As per base case 3, when `i` is greater than 0 and `j` is `0`, we can `return true` if all the remaining characters in `pattern` are `*`, so fill first column with `true` if all the remaining characters in `pattern` are `*`.We can do it with `flag` variable.
-   Rest of the table can be simply filled as per the recursive relation.
-   **TC: O(n\*m)**
-   **SC: O(n\*m)**, without recursive stack space.

### Code

```cpp
bool wildcardMatching(string pattern, string text)
{
    int n = pattern.size(), m = text.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
    dp[0][0] = true;

    // Don't need to do below loop as dp is initialized with false
    // Its just for understanding
    for (int j = 1; j <= m; j++) dp[0][j] = false;

    for (int i = 1; i <= n; i++) {
        bool flag = true;
        for (int k = 1; k <= i; k++) {
            if (pattern[k - 1] != '*') {
                flag = false;
                break;
            }
        }
        dp[i][0] = flag;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (pattern[i - 1] == text[j - 1] || pattern[i - 1] == '?') {
                dp[i][j] = dp[i - 1][j - 1];
            } else if (pattern[i - 1] == '*') {
                int takeEmptyAndMove = dp[i - 1][j];
                int takeOneCharAndStay = dp[i][j - 1];
                dp[i][j] = (takeEmptyAndMove || takeOneCharAndStay);
            } else {
                dp[i][j] = false;
            }
        }
    }
    return dp[n][m];
}
```

### Space optimized tabulation

-   ```
      dp[i-1] = prev
      dp[i] = curr
    ```
-   **Note:** For third base case, here every time loop starts we need to assign `curr[0] = flag`, not just once.
-   **TC: O(n\*m)**
-   **SC: O(m)**

### Code

```cpp
bool wildcardMatching(string pattern, string text)
{
    int n = pattern.size(), m = text.size();
    vector<bool> prev(m + 1, false), curr(m + 1, false);
    prev[0] = true;

    for (int i = 1; i <= n; i++) {
        bool flag = true;
        for (int k = 1; k <= i; k++) {
            if (pattern[k - 1] != '*') {
                flag = false;
                break;
            }
        }
        curr[0] = flag;
        for (int j = 1; j <= m; j++) {
            if (pattern[i - 1] == text[j - 1] || pattern[i - 1] == '?') {
                curr[j] = prev[j - 1];
            } else if (pattern[i - 1] == '*') {
                curr[j] = (prev[j] || curr[j - 1]);
            } else {
                curr[j] = false;
            }
        }
        prev = curr;
    }
    return prev[m];
}
```
