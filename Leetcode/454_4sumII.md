# [454. 4Sum II](https://leetcode.com/problems/4sum-ii/) 🌟🌟

Given four integer arrays nums1, nums2, nums3, and nums4 all of length n, return the number of tuples (i, j, k, l) such that:

-   `0 <= i, j, k, l < n`
-   `nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0`

### Brute force (TLE)

-   we can count for every quadruplet if their sum is 0;
-   **TC: O(N^4)**
-   **SC: O(1)**

### Code

```cpp
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int cnt=0;
        for(auto a:nums1){
            for(auto b:nums2){
                for(auto c:nums3){
                    for(auto d:nums4){
                        if(a+b+c+d==0)cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};
```

### O(N^3) (TLE)

-   If we can take reference of 2 sum problem here we can store num4 values in hashmap so we can access them in O(1) time.
-   **TC: O(N^3)**
-   **SC: O(N)**

### Code

```cpp
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int cnt=0;
        unordered_map<int, int> mp;
        for(auto d:nums4) mp[d]++;
        for(auto a:nums1){
            for(auto b:nums2){
                for(auto c:nums3){
                    cnt+=mp[-(a+b+c)];
                }
            }
        }
        return cnt;
    }
};
```

### O(N^2) Optimized (AC)

-   we can use hashmap to store a+b and then we can find -(c+d) to get total count.
-   **TC: O(N^2)**
-   **SC: O(N)**

### Code

```cpp
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4)
    {
        int cnt = 0;
        unordered_map<int, int> mp;
        for (auto a : nums1) {
            for (auto b : nums2) {
                mp[a + b]++;
            }
        }
        for (auto c : nums3) {
            for (auto d : nums4) {
                cnt += mp[-(c + d)];
            }
        }
        return cnt;
    }
};
```
