# [Palindrome Partitioning II](https://www.codingninjas.com/codestudio/problems/palindrome-partitioning_873266?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0) 🌟🌟🌟

### Recursive solution

-   Front partition logic.
-   [striver's video](https://www.youtube.com/watch?v=_H8V5hJUGd0&feature=youtu.be) for explanation.

### Code

```cpp
bool isPalindrome(int i, int j, string& s)
{
    while (i < j) {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int f(string& s, int n, int i)
{
    if (i == n)
        return 0;
    int minCost = INT_MAX;
    for (int j = i; j < n; j++) {
        if (isPalindrome(i, j, s)) {
            int cost = 1 + f(s, n, j + 1);
            minCost = min(minCost, cost);
        }
    }
    return minCost;
}

int palindromePartitioning(string& s)
{
    int n = s.size();
    return f(s, n, 0) - 1;
}
```

### Memoization

-   **TC: O(N^2)**
-   **SC: O(N)**

```cpp
bool isPalindrome(int i, int j, string& s)
{
    while (i < j) {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int f(string& s, int n, int i, vector<int>& dp)
{
    if (i == n)
        return 0;
    if (dp[i] != -1)
        return dp[i];
    int minCost = INT_MAX;
    for (int j = i; j < n; j++) {
        if (isPalindrome(i, j, s)) {
            int cost = 1 + f(s, n, j + 1, dp);
            minCost = min(minCost, cost);
        }
    }
    return dp[i] = minCost;
}

int palindromePartitioning(string& s)
{
    int n = s.size();
    vector<int> dp(n, -1);
    return f(s, n, 0, dp) - 1;
}
```

### Tabulation

-   **TC: O(N^2)**
-   **SC: O(N)**

```cpp
bool isPalindrome(int i, int j, string& s)
{
    while (i < j) {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int palindromePartitioning(string& s)
{
    int n = s.size();
    vector<int> dp(n + 1, 0);
    dp[n] = 0;
    for (int i = n - 1; i >= 0; i--) {
        int minCost = INT_MAX;
        for (int j = i; j < n; j++) {
            if (isPalindrome(i, j, s)) {
                int cost = 1 + dp[j + 1];
                minCost = min(minCost, cost);
            }
        }
        dp[i] = minCost;
    }
    return dp[0] - 1;
}
```
