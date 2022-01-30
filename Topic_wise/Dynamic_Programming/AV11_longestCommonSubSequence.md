# Longest Common Subsequence

Given two sequences, find the length of longest subsequence present in both of them. Both the strings are of uppercase.

### Method 1: Naive Recursion Approach

- If length fo any of the strings is 0, then return 0.
- if last char of both the strings are same, then we can add it to our sequence and reduce both string length by 1 to check for remaining string.
- Else we try to get max of each string length reduced by one at a time - max(lcs(x - 1, y, s1, s2), lcs(x, y - 1, s1, s2));

### Code

```cpp
int lcsRec(int x, int y, string s1, string s2)
{
    if (x == 0 || y == 0)
        return 0;

    if (s1[x - 1] == s2[y - 1])
        return 1 + lcs(x - 1, y - 1, s1, s2);
    else
        return max(lcs(x - 1, y, s1, s2), lcs(x, y - 1, s1, s2));
}
```

### Complexity Analysis

- Time complexity: **O(2^n)**, exponential complexity
- Space Complexity: **O(1)**, No extra space used,except recursive stack space.

---

### DP APPROACHES

### A) Memoization(Top-Down)

### code

```cpp

int dp[1001][1001];

void initialize()
{
    for (int i = 0; i < 1001; i++)
        for (int j = 0; j < 1001; j++)
            dp[i][j] = -1;
}
int lcsMo(int x, int y, string s1, string s2)
{
    if (x == 0 || y == 0)
        return 0;

    if (dp[x][y] != -1)
        return dp[x][y];

    if (s1[x - 1] == s2[y - 1])
        return dp[x][y] = 1 + lcs(x - 1, y - 1, s1, s2);
    else
        return dp[x][y] = max(lcs(x, y - 1, s1, s2), lcs(x - 1, y, s1, s2));
}

int lcs(int x, int y, string s1, string s2)
{
    initialize();
    return lcsMo(x, y, s1, s2);
}
```

### Complexity Analysis

- Time Complexity: **O(X\*Y)**
- Space Complexity: **O(X\*Y)**

---

### B) Tabulation(Bottom up)

```cpp
int lcs(int x, int y, string s1, string s2)
{
    int dp[x + 1][y + 1];

    for (int i = 0; i < x + 1; i++)
    {
        for (int j = 0; j < y + 1; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[x][y];
}
```

### Complexity Analysis

- Time Complexity: **O(X\*Y)**
- Space Complexity: **O(X\*Y)**

### References

- GFG: [Longest Common Subsequence](https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/)
- YouTube: [AV - Longest Common Subsequence](https://www.youtube.com/watch?v=4Urd0a0BNng&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=19)
