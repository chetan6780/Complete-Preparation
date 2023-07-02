# [11. Container With Most Water](https://leetcode.com/problems/container-with-most-water/) (Medium)

### Solution

### Code

```cpp
class Solution {
public:
    int maxArea(vector<int>& height)
    {
        int n = height.size();
        int i = 0, j = n - 1;
        int maxWater = 0;
        while (i < j) {
            maxWater = max(maxWater, (j - i) * min(height[i], height[j]));
            if (height[i] < height[j])
                i++;
            else
                j--;
        }
        return maxWater;
    }
};
```
