# Print Shortest Common Supersequence

### Prerequesite: [Print LCS](./AV13_printLCS.md)

Given two strings X and Y, print the shortest string that has both X and Y as subsequences. If multiple shortest supersequence exists, print any one of them.

### Code

```cpp
string scsPrint(int x, int y, string s1, string s2)
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
    string res;
    int i = x, j = y;
    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            res.push_back(s1[i - 1]);
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            res.push_back(s1[i - 1]);// pb max char
            i--;
        }
        else
        {
            res.push_back(s2[j - 1]);// pb max char
            j--;
        }
    }
    // if j==0 and i remaining then include all char at i
    while (i > 0)
    {
        res.push_back(s1[i - 1]);
        i--;
    }
    // if i==0 and j remaining then include all char at j
    while (j > 0)
    {
        res.push_back(s2[j - 1]);
        j--;
    }
    reverse(res.begin(), res.end());
    return res;
}
```

### Complexity Analysis

- Time Complexity: **O(X\*Y)**
- Space Complexity: **O(X\*Y)**

### References

- GFG: [Print Shortest Common Supersequence](https://www.geeksforgeeks.org/print-shortest-common-supersequence/)
- YouTube: [AV - Print Shortest Common Supersequence](https://www.youtube.com/watch?v=VDhRg-ZJTuc&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=29)
