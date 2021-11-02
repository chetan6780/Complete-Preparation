# Shortest Common Supersequence

Given two strings str1 and str2, the task is to find the length of the shortest string that has both str1 and str2 as subsequences.

```
Input:  str1 = "geek",  str2 = "eke"
Output: 5
Explanation: String "geeke" has both string "geek" and "eke" as subsequences.
```

### Prerequisite: [Longest Common subsequence](./AV11_longestCommonSubSequence.md)

- We can create string 1 and 2 from lcs by adding extra letters in each string so we just need to find **(m+n-lcs)**.
- It will give us the length of the shortest common supersequence.

### Code

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

int shortestCommonSupersequence(string X, string Y, int m, int n)
{
    return m + n - lcs(m, n, X, Y);
}
```

### Complexity Analysis

- Time Complexity: **O(M\*N)**
- Space Complexity: **O(M\*N)**

### Prerequisite

- GFG: [Shortest Common Supersequence]()
- YouTube: [AV - Shortest Common Supersequence](https://www.youtube.com/watch?v=823Grn4_dCQ&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=24)
