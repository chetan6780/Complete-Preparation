# Longest Common Substring

Given two strings ‘X’ and ‘Y’, find the length of the longest common substring.

### Prerequisites: [Longest Common Subsequence](./AV11_longestCommonSubSequence.md)

- If Substring matches we add 1 to it and store max result.
- Else we start with 0 agian.

### Code

```cpp
int lcst(int x, int y, string s1, string s2)
{
    int dp[x + 1][y + 1];
    int res = 0;

    for (int i = 0; i < x + 1; i++)
    {
        for (int j = 0; j < y + 1; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (s1[i - 1] == s2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    res = max(res, dp[i][j]); // Store maxi ans
                }
            else
                dp[i][j] = 0; // Reset lenght to 0
        }
    }
    return dp[x][y];
}
```

### Complexity Analysis

- Time Complexity: **O(X\*Y)**
- Space Complexity: **O(X\*Y)**
- 1D dp solution available at GFG

### References

- GFG: [Longest Common Substring](https://www.geeksforgeeks.org/longest-common-substring-dp-29/)
- YouTube: [AV - Longest Common Substring](https://www.youtube.com/watch?v=HrybPYpOvz0&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=22)
