# [96. Unique Binary Search Trees](https://leetcode.com/problems/unique-binary-search-trees/)

### DP Solution(Tabulation)

-   We have base conditions of `dp[0] = dp[1] = 1.`
-   Then we calculate result for each number of nodes `i` from `2...n.`
-   For `i` nodes. we can consider each of the node `j` from `1...i` as the root node.
-   Considering the jth node as the root node in BST having total of `i` nodes, the result is summation for all `j` from `1...i` of `dp[j-1] * dp[i-j]`. (Comparing to above solution `dp[j-1] = numTrees(j-1) and dp[i-j]=numTrees(i-j)`)

### Code

```cpp
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1);
        dp[0] = dp[1] = 1;
        for(int i = 2; i <= n; i++)
            for(int j = 1; j <= i; j++)
                dp[i] += dp[j-1] * dp[i-j];
        return dp[n];
    }
};
```

### MUST READ 👇:

-   There are a few ways to solve this problem. I have explained all the solutions and approach to optimize it from Brute-Force to Dynamic Programming to solving using Catalan formula in: ✅[ Simple Solution w/ Explanation | Optimization from Brute-Force to DP](https://leetcode.com/problems/unique-binary-search-trees/discuss/1565543/Simple-Solution-w-Explanation-or-Optimization-from-Brute-Force-to-DP)

1. **Brute-Force**                 `( Time: O(3^N), Space: O(N) )`
1. **Dynamic Programming - Memoization**    `( Time: O(N^2), Space: O(N) )`
1. **Dynamic Programming - Tabulation**     `( Time: O(N^2), Space: O(N) )`
1. **Catalan Numbers**             `( Time: O(N), Space: O(1) )`
1. **Catalan Numbers (2nd Approach)**      `( Time: O(N), Space: O(1) )`

-   [C++ Easy & Clean Solution | Fastest | All (4+) Methods | Detailed Explanation & Comments](<https://leetcode.com/problems/unique-binary-search-trees/discuss/1565544/C%2B%2B-Easy-and-Clean-Solution-or-Fastest-or-All-(3%2B)-Methods-or-Detailed-Explanation-and-Comments>)
