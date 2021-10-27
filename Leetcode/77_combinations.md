# [77. Combinations](https://leetcode.com/problems/combinations/) 🌟🌟

Given two integers n and k, return all possible combinations of k numbers out of the range [1, n].

You may return the answer in any order.

### Backtracking

- Backtracking is a general technique for solving problems that uses DFS and finds **ALL POSSIBLE SOLUTIONS**.
- General idea:
  ```
  Step 1: DO
  Step 2: RECUR
  Step 3: UNDO
  ```
  Make sure to use base conditions.

### Code

```cpp
class Solution {
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> res;
        backtrack(res, 1, n, k, vector<int>());
        return res;
    }

    void backtrack(vector<vector<int>> &res, int cur, int n, int k, vector<int> comb)
    {
        if (k == 0)
        {
            res.push_back(comb);
            return;
        }
        // If cur>n-k, there are not enough numbers left, we have to select the current element
        if (cur <= n - k)
            backtrack(res, cur + 1, n, k, comb);
        comb.push_back(cur);
        backtrack(res, cur + 1, n, k - 1, comb);
    }
};
```

### MUST READ:

- [A template to those combination problems [C++]](https://leetcode.com/problems/combinations/discuss/27006/A-template-to-those-combination-problems)
- [Backtracking cheatsheet + simple solution [python really easy]](https://leetcode.com/problems/combinations/discuss/844096/Backtracking-cheatsheet-%2B-simple-solution)
