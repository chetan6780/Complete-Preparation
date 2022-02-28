# [228. Summary Ranges](https://leetcode.com/problems/summary-ranges/) 🌟

You are given a sorted unique integer array nums.

Return the smallest sorted list of ranges that cover all the numbers in the array exactly. That is, each element of nums is covered by exactly one of the ranges, and there is no integer x such that x is in one of the ranges but not in nums.

Each range [a,b] in the list should be output as:

-   "a->b" if a != b
-   "a" if a == b

### Intuitive Solution

-   We traverse the array and find right element to add.
-   If we found then change flag to true.
-   else add arrow and right element to the array as string and store new left element i.e. nums[i] and flag = true.
-   **TC: O(n)**
-   **SC: O(1)**

### Code

```cpp
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums)
    {
        int n = nums.size();
        vector<string> ans;
        if (n == 0)
            return ans;
        string temp = to_string(nums[0]);
        int r = 0;
        bool fl = false;
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1] + 1) {
                r = nums[i];
                fl = true;
            } else {
                if (fl) temp += "->" + to_string(r);
                ans.push_back(temp);
                temp = to_string(nums[i]);
                fl = false;
            }
        }
        if (fl) temp += "->" + to_string(r);
        ans.push_back(temp);
        return ans;
    }
};
```
