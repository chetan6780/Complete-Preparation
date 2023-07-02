# [852. Peak Index in a Mountain Array](https://leetcode.com/problems/peak-index-in-a-mountain-array/)

### linear O(N)

### Code

```cpp
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr)
    {
        int n = arr.size();
        for (int i = 1; i < n - 1; i++) {
            if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
                return i;
        }
        return n - 1;
    }
};
```

```cpp
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr)
    {
        int n = arr.size();
        int l = 0, r = n - 1;
        while(l<r){
            if(arr[l]<arr[r]){
                l++;
            }else{
                r--;
            }
        }
        return l;
    }
};
```

### Binary Search

### Code

-   if middle element is less than next element to it then increment left pointer
-   else set right pointer to mid.
-   **TC: O(logn)**
-   **SC: O(1)**

```cpp
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr)
    {
        int n = arr.size();
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (arr[mid] < arr[mid + 1])
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }
};
```
