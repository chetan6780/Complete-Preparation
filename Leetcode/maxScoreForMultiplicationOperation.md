# [1770. Maximum Score from Performing Multiplication Operations](https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/) 🌟🌟

You are given two integer arrays nums and multipliers of size n and m respectively, where n >= m. The arrays are 1-indexed.

You begin with a score of 0. You want to perform exactly m operations. On the ith operation (1-indexed), you will:

-   Choose one integer x from either the start or the end of the array nums.
-   Add multipliers[i] \* x to your score.
-   Remove x from the array nums.

Return the maximum score after performing m operations.

### Recursion (TLE)

-   A **greedy solution** where for every index in multipliers vector you would choose the **first** or **last** one from the nums vector and then multiply it and keep on adding it to the sum.
-   **This is not a correct solution** as it fails when their are uneven number of +ve and -ve values in both vector.
-   Thus a recursive solution is required where all the possible values of choosing the leftmost num or rightmost num in nums vector are computed.Below is the implementation.
-   **TC: O(2^N)**

### Code

```cpp
class Solution {
private:
    int helper(vector<int>& nums, vector<int>& multipliers, int i, int l)
    {
        int n = nums.size();
        int m = multipliers.size();

        if (i == m) return 0;
        int pickLeft = (multipliers[i] * nums[l]) + (helper(nums, multipliers, i + 1, l + 1));
        int pickRight = (multipliers[i] * nums[n - (i - l) - 1]) + (helper(nums, multipliers, i + 1, l));

        return max(pickLeft, pickRight);
    }

public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers)
    {
        return helper(nums, multipliers, 0, 0);
    }
};
```

### Memoization (Top-Down) (AC)

-   As we have a correct recursive code at hand, 90% of our Dynamic Programming solution is DONE.
-   We just have to memorize the recursive code into a 2-D array of (Size of nums) X (Size of multipliers) as its changing variables.
-   We initialize the 2-D array with -1, and keep on updating the smaller sub-solutions which is the maximum of choosing answer from leftmost or rightmost in nums vector.
-   If during a pass we find some sub-problem is already present, return the answer.
-   **TC: O(2\*m^2)**, where `m<=10^3`
-   **SC: O(m^2)**

### Code

```cpp
class Solution {
private:
    int helper(vector<int>& nums, vector<int>& multipliers, vector<vector<int>>& memo, int i, int l)
    {
        int n = nums.size();
        int m = multipliers.size();

        if (i == m) return 0;
        if(memo[l][i] != -1) return memo[l][i];
        int pickLeft = (multipliers[i] * nums[l]) + (helper(nums, multipliers, memo, i + 1, l + 1));
        int pickRight = (multipliers[i] * nums[n - (i - l) - 1]) + (helper(nums, multipliers, memo, i + 1, l));

        return memo[l][i] = max(pickLeft, pickRight);
    }

public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers)
    {
        int m = multipliers.size();
        vector<vector<int>> memo(m,vector<int>(m,-1)); // size is M x M not N x N

        return helper(nums, multipliers, memo, 0, 0);
    }
};
```

### Tabulation (Bottom-Up) (AC-fastest)

-   We can convert the top-down approach to the bottom-up approach and hence reduce the recursive stack space.
-   **TC: O(2\*m^2)**, where `m<=10^3`
-   **SC: O(m^2)**

### Code

```cpp
class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers)
    {
        int n = nums.size();
        int m = multipliers.size();
        int dp[1001][1001] = {};

        for (int i = m - 1; i >= 0; i--) {
            int mult = multipliers[i];
            for (int left = i; left >= 0; left--) {
                int right = n - 1 - (i - left);
                int pickLeft = mult * nums[left] + dp[i + 1][left + 1];
                int pickRight = mult * nums[right] + dp[i + 1][left];
                dp[i][left] = max(pickLeft, pickRight);
            }
        }
        return dp[0][0];
    }
};
```

### MUST READ

-   [[Java/C++/Python 3] Top Down DP - O(m^2) - Clean & Concise](<https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/discuss/1075469/JavaC%2B%2BPython-3-Top-Down-DP-O(m2)-Clean-and-Concise>)
-   [C++ DP (SIMPLEST TO UNDERSTAND) -> Recursive to Memoization -> Complete EXPLANATION](<https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/discuss/1078881/C%2B%2B-DP-(SIMPLEST-TO-UNDERSTAND)-greater-Recursive-to-Memorisation-greater-Complete-EXPLANATION>)
