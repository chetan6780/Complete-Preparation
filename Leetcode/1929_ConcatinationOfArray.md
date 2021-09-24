# [1929. Concatenation of Array](https://leetcode.com/problems/concatenation-of-array/) 🌟

### O(n) time and O(n) space solution

- We will use inbuilt function `vector.insert()` to concatenate the arrays.

### Code

```cpp
class Solution{
public:
    vector<int> getConcatenation(vector<int> &nums)
    {
        vector<int> ans(nums.begin(), nums.end());
        ans.insert(ans.end(), nums.begin(), nums.end());
        return ans;
    }
};
```
