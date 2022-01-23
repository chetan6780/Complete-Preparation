# [77. Combinations](https://leetcode.com/problems/combinations/) 🌟🌟

Given two integers n and k, return all possible combinations of k numbers out of the range [1, n].

You may return the answer in any order.

### Backtracking: solution-1 (28ms-AC)

-   Backtracking is a general technique for solving problems that uses DFS and finds **ALL POSSIBLE SOLUTIONS**.
-   General idea:
    ```
    Step 1: DO
    Step 2: RECUR
    Step 3: UNDO
    ```
    Make sure to use base conditions.

### Code

-   my solution based on general backtracking template in python 😄.

```cpp
class Solution {
private:
    void backtrackComb(vector<vector<int>>& ans, vector<int>& comb, int n, int k, int currNum)
    {
        if (k == 0) {
            ans.push_back(comb);
            return;
        }
        for (int i = currNum; i <= n; i++) {
            comb.push_back(i);
            backtrackComb(ans, comb, n, k - 1, i + 1);
            comb.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> ans;
        vector<int> comb;
        backtrackComb(ans, comb, n, k, 1);
        return ans;
    }
};
```

### Solution-2 (10ms-AC)

```cpp
class Solution {
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> res;
        vector<int> comb;
        backtrack(res, 1, n, k, comb);
        return res;
    }

    void backtrack(vector<vector<int>>& res, int cur, int n, int k, vector<int>& comb)
    {
        if (k == 0) {
            res.push_back(comb);
            return;
        }
        if (cur <= n - k)
            backtrack(res, cur + 1, n, k, comb);
        comb.push_back(cur);
        backtrack(res, cur + 1, n, k - 1, comb);
        comb.pop_back();
    }
};
```

### MUST READ:

-   [A template to those combination problems [C++]](https://leetcode.com/problems/combinations/discuss/27006/A-template-to-those-combination-problems)
-   [Backtracking cheatsheet + simple solution [python really easy]](https://leetcode.com/problems/combinations/discuss/844096/Backtracking-cheatsheet-%2B-simple-solution)
