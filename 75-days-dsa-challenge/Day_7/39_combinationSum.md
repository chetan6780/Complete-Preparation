# [39. Combination Sum](https://leetcode.com/problems/combination-sum/) (Medium)

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

### Code - 3

```cpp
class Solution {
private:
    void backtrack(vector<int>& cand, int i, int target, vector<int>& temp, vector<vector<int>>& ans)
    {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }
        if (i == cand.size() || target < 0)
            return;

        temp.push_back(cand[i]);
        backtrack(cand, i, target - cand[i], temp, ans);
        temp.pop_back();
        backtrack(cand, i + 1, target, temp, ans);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        int n = candidates.size();
        vector<vector<int>> ans;
        vector<int> temp = {};
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, 0, target, temp, ans);
        return ans;
    }
};
```
