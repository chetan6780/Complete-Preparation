# [39. Combination Sum](https://leetcode.com/problems/combination-sum/) 🌟🌟

Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

### Backtracking

-   for a number we have 2 choices either:
    -   we choose it
    -   we don't choose it
-   if current element is less than target we can choose it.
-   else we can't choose it.
-   Base case arises when target is 0, we add the vector in answer.
-   and if index is greater than size of candidates array, we return.

### Code-1

```cpp
class Solution {
private:
    void combinationSumBack(vector<int>& candidates, int target, int i, vector<vector<int>>& ans, vector<int>& temp)
    {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }
        while (i < candidates.size() && candidates[i] <= target) {
            temp.push_back(candidates[i]);
            combinationSumBack(candidates, target - candidates[i], i, ans, temp);
            temp.pop_back();
            i++;
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        int n = candidates.size();
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> temp = {};
        combinationSumBack(candidates, target, 0, ans, temp);
        return ans;
    }
};
```

### Code-2 (100%-AC)

```cpp
class Solution {
private:
    void combinationSumBack(vector<int>& candidates, int target, int i, vector<vector<int>>& ans, vector<int>& temp)
    {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }
        if (i >= candidates.size())
            return;
        if (candidates[i] <= target) {
            temp.push_back(candidates[i]);
            combinationSumBack(candidates, target - candidates[i], i, ans, temp);
            temp.pop_back();
        }
        combinationSumBack(candidates, target, i + 1, ans, temp);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        int n = candidates.size();
        vector<vector<int>> ans;
        vector<int> temp = {};
        combinationSumBack(candidates, target, 0, ans, temp);
        return ans;
    }
};
```
