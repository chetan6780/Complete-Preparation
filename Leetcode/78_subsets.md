# [78. Subsets](https://leetcode.com/problems/subsets/description/) 🌟🌟

Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

### Recursive solution

-   For a number we have 2 choices: either we can include it OR not in include it.

### code

```cpp
class Solution {
public:
void subsets_helper(vector<int>& nums, vector<int>& output, int index, vector<vector<int>>& ans)
{
    if (index >= nums.size()) {
        ans.push_back(output);
        return;
    }

    // include
    output.push_back(nums[index]);
    subsets_helper(nums, output, index + 1, ans);

    // exclude
    output.pop_back();
    subsets_helper(nums, output, index + 1, ans);
}

vector<vector<int>> subsets(vector<int>& nums)
{
    vector<vector<int>> ans;
    vector<int> res;
    int index = 0;
    subsets_helper(nums, res, index, ans);
    return ans;
}
};
```
