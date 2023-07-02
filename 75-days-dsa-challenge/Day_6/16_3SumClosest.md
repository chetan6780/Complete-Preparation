# [16. 3Sum Closest](https://leetcode.com/problems/3sum-closest/) (medium)

### Brute force

-   We can find all the possible combinations of three numbers in the array.
-   Then we can find the closest sum by comparing the sum of the three numbers with the target sum.
-   **TC:O(n^3)**
-   **SC:O(1)**

### Optimized

-   We use similar idea as 3Sum.
-   First sort the array.
-   then we will fix first number and find other 2 numbers with the two pointer method.
-   If the sum of current 3 elements is equal to the target sum, we return the sum OR target.
-   If absolute difference between the sum of current 3 elements and target sum `abs(sum - target)` is less than the current closest difference and target sum `abs(ans - target)`, we update the closest difference.
-   If the sum is less than target then move right pointer by 1 else move left pointer by 1.
-   Return the closest difference(`ans`).
-   **TC:O(n^2)**
-   **SC:O(1)**

### Code

```cpp

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int ans = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < n; ++i) {
            int left = i + 1, right = n - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == target)
                    return target;
                if (abs(sum - target) < abs(ans - target))
                    ans = sum;
                if (sum < target)
                    ++left;
                else
                    --right;
            }
        }
        return ans;
    }
};
```
