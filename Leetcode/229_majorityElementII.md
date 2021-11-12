# [229. Majority Element II](https://leetcode.com/problems/majority-element-ii/) 🌟🌟

-   **GOOGLE QUESTION**

Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

### Brute force

-   We check for all the elements, if it appears more than n/3 times, we add it to the result vector.
-   **TC: O(N^2)**
-   **SC:O(1)**

### O(N) Time and O(1) space

-   we Can take a vector or unordered_map to store the frequency of each element.
-   We traverse the hash map/ vector to find the n/3 frequency.
-   if we found we return the element.
-   **TC: O(N)**
-   **SC:O(N)/O(N^2)** - _Yes if we use unordered_map it's worst case time complexity is **O(N^2)**, which occurs when all elements are divisible by prime number and result in collision_. But if we use frequency vector it's worst case time complexity is **O(N)**.

### Code

```cpp
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        n/=3;
        vector<int> ans;
        unordered_map<int,int> mp;
        for(int x:nums) mp[x]++;
        for(auto [x,f]:mp) {
            if(f>n) ans.push_back(x);
        }
        return ans;
    }
};
```

### Moore's Voting Algorithm

-   **TC:O(N)**
-   **SC:O(1)**
-   The intuition and method is same as `majority element` problem but here we maintain 2 cnt variables and 2 candidate because in the question it is given that at most 2 majority element will be present or there may be no element present.

```cpp
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums)
    {
        int cand1 = -1, cand2 = -1, cnt1 = 0, cnt2 = 0, n = nums.size();
        for (int x : nums) {
            if (x == cand1) cnt1++;
            else if (x == cand2) cnt2++;
            else if (cnt1 == 0) {
                cand1 = x;
                cnt1 = 1;
            } else if (cnt2 == 0) {
                cand2 = x;
                cnt2 = 1;
            } else {
                cnt1--, cnt2--;
            }
        }
        vector<int> ans;
        cnt1 = 0, cnt2 = 0;
        for (int x : nums) {
            if (x == cand1) cnt1++;
            else if (x == cand2) cnt2++;
        }
        if (cnt1 > n / 3) ans.push_back(cand1);
        if (cnt2 > n / 3) ans.push_back(cand2);
        return ans;
    }
};
```
