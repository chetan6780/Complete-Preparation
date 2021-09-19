# Minimum number of deletions and insertions to transform one string into another.

Given two strings str1 and str2. The task is to remove or insert the minimum number of characters from/in str1 so as to transform it into str2. It could be possible that the same character needs to be removed/deleted from one point of str1 and inserted to some another point.

### Prerequisite: [longest common subsequence](./AV11_longestCommonSubSequence.md)

### Algorithm

- We can create string b form a with the help of lcs.
- we can find number of deletion by str1.lenght()-lcs and number of insertion by str2.length()-lcs.
- len be the length of the longest common subsequence of str1 and str2
- minimum number of deletions minDel = m – len
- minimum number of Insertions minInsert = n – len

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

int minOperations(string str1, string str2)
{
    int m = str1.size();
    int n = str2.size();
    int len = lcs(m, n, str1, str2);
    return ((m - len) + (n - len));
}
```

### Complexity Analysis

- Time Complexity: **O(M\*N)**
- Space Complexity: **O(M\*N)**

### References

- GFG: [Minimum number of deletions and insertions to transform string A to B](https://www.geeksforgeeks.org/minimum-number-deletions-insertions-transform-one-string-another/)
- Youtube: [AV - Minimum number of deletions and insertions to transform string A to B](https://www.youtube.com/watch?v=-fx6aDxcWyg&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=25)
