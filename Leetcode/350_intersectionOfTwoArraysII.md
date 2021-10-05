# [350. Intersection of Two Arrays II](https://leetcode.com/problems/intersection-of-two-arrays-ii/) 🌟

Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

### O(N\*M) Time and O(N) Space

- Brute force
- for every element in nums1, check if it exists in nums2
- if it exists then add it to the ans and set it to -1 and break inner loop, so duplicats will not be included.
- return ans

### Code

```cpp
class Solution{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<int> ans;
        for (int i = 0; i < n1; i++){
            for (int j = 0; j < n2; j++){
                if (nums1[i] == nums2[j]){
                    ans.emplace_back(nums2[j]);
                    nums2[j] = -1;
                    break;
                }
            }
        }
        return ans;
    }
};
```
