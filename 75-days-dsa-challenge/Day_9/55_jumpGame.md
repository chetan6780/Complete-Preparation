# [55. Jump Game](https://leetcode.com/problems/jump-game/) (Medium)

### Solution

-   For each index we can calculate how far we can jump.it will be our maximum reach.
-   If at any point we exceed the maximum reach, we can't jump to last index.
-   **TC:O(N)**
-   **SC:O(1)**

### Code

```cpp
class Solution {
public:
    bool canJump(vector<int>& nums)
    {
        int n = nums.size();
        int max_reach = 0;
        for (int i = 0; i < n; i++)
        {
            if (i > max_reach)
                return false;
            max_reach = max(max_reach, i + nums[i]);
        }
        return true;
    }
};
```
