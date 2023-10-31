# [1679. Max Number of K-Sum Pairs](https://leetcode.com/problems/max-number-of-k-sum-pairs/description) 🌟🌟

You are given an integer array nums and an integer k.

In one operation, you can pick two numbers from the array whose sum equals k and remove them from the array.

Return the maximum number of operations you can perform on the array.

### Brute force(TLE)

-   Try all possible combinations of numbers and find the maximum number of operations out of them.
-   **Time complexity:** O(n^2)
-   **Space complexity:** O(1)

### Code

```cpp
class Solution {
public:
    int maxOperations(vector<int>& nums, int k)
    {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] + nums[j] == k) {
                    ans++;
                    // erase the elements from the array and reduce the size of by 2
                    nums.erase(nums.begin() + j);
                    nums.erase(nums.begin() + i);
                    n -= 2;
                    i--; // to check the element at i again
                    break;
                }
            }
        }
        return ans;
    }
};
```

### Two pointer approach

-   To optimize the brute force approach, we can use two pointer approach.
-   sort the array.
-   take one pointer at the start and one at the end.
-   if the sum of the elements at both the pointers is less than k, then we need to increase the sum, so we will move the pointer at the start to the next element.
-   if the sum of the elements at both the pointers is greater than k, then we need to decrease the sum, so we will move the pointer at the end to the previous element.
-   if it is equal to k, then we will increase the count of operations and move both the pointers to the next and previous element respectively.
-   repeat the process until both the pointers meet.
-   **Time complexity:** O(nlogn)
-   **Space complexity:** O(1)

### Code

```cpp
class Solution {
public:
    int maxOperations(vector<int>& nums, int k)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = 0, j = n - 1;
        int ans = 0;
        while (i < j) {
            if (nums[i] + nums[j] < k)
                i++;
            else if (nums[i] + nums[j] > k)
                j--;
            else {
                ans++;
                i++;
                j--;
            }
        }
        return ans;
    }
};
```

### Hashmap

-   We can use a hashmap to store the frequency of each element.
-   we will check for pair of elements whose sum is equal to k.(i.e.{nums[i], k - nums[i]})
-   if we find such a pair, then we will increase the count of operations and decrease the frequency of both the elements by 1.
-   if we don't find such a pair, then we will increase the frequency of the element by 1.
-   repeat the process until we reach the end of the array.
-   **Time complexity:** O(n)
-   **Space complexity:** O(n)

### Code

```cpp
class Solution {
public:
    int maxOperations(vector<int>& nums, int k)
    {
        unordered_map<int, int> mp;
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            int num = k - nums[i];
            if (mp[num] > 0) {
                ans++;
                mp[num]--; // pair found, decrease the frequency
            } else {
                mp[nums[i]]++; // pair not found, add the element to the map
            }
        }
        return ans;
    }
};
```
