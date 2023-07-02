# [4. Median of Two Sorted Arrays](./Day_16/4_medianOfTwoSortedArrays.md)

### Solution

### Code

```cpp
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> ans;
        ans.insert(ans.end(), nums1.begin(), nums1.end());
        ans.insert(ans.end(), nums2.begin(), nums2.end());

        sort(ans.begin(), ans.end());

        int n = ans.size();
        if (n & 1) {
            return ans[n / 2];
        } else {
            return (ans[n / 2] + ans[(n - 1) / 2]) / (double)2;
        }

        return 0;
    }
};
```
