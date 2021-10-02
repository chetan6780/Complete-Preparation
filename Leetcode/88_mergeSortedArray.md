# [88. Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array/) 🌟

You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

### O(M+N) Time and O(M+N) space

- Create new array with m+n elements.
- Traverse through both the given array, find min and insert in the new array.

### O(M\*N) without using extra Space

- Traverse through both the given array
- If arr1[i]>arr2[i] then swap the elements and sort the second array.(here sorting means just put swapped element at its right position not real sorting)

### O(M+N) Time and O(1) Space

- Code is self explanetory on leetcode

### Code

```cpp

class Solution{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int a = m - 1; // last index of nums1
        int b = n - 1; // last index of nums2
        int i = m + n - 1; // last index of extended nums1(with 0 wala)
        while (a >= 0 && b >= 0) // while we not reach start of any array
        {
            if (nums1[a] > nums2[b])
            {
                nums1[i] = nums1[a];
                i--, a--;
            }
            else
            {
                nums1[i] = nums2[b];
                i--, b--;
            }
        }
        while (b >= 0) // if there are elements remaining in b then put them in back
        {
            nums1[i] = nums2[b];
            i--, b--;
        }
    }
};
```

### Using GAP algorithm

**Here soon**

<!-- TODO: Write GAP algo -->
