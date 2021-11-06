# [260. Single Number III](https://leetcode.com/problems/single-number-iii/) 🌟🌟

Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. You can return the answer in any order.

You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.

### O(N^2) Time

- Brute force

### O(NlogN) Time Sorting solution

- Since we have condition that `exactly two elements appear only once and all the other elements appear exactly twice.`
- First we sort the nums array.
- if we found duplicates we increase i by 2 else we add number in ans.
- if ans.size()==2 thn we can break loop, since we have only 2 unique elements.

### Code

```cpp
class Solution{
public:
    vector<int> singleNumber(vector<int> &nums){
        sort(nums.begin(), nums.end());
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < n - 1; i++){
            if (nums[i] == nums[i + 1]){
                i++;
            }
            else{
                ans.push_back(nums[i]);
                if (ans.size() == 2)
                    break;
            }
        }
        if (ans.size() == 1)
            ans.push_back(nums.back());
        return ans;
    }
};
```

### O(N) Time HashMap solution

- We can use `set` or `map` to solve this problem in O(N) time.

### Code

```cpp
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto x:nums){
            mp[x]++;
        }
        vector<int> ans;
        for(auto x:mp){
            if(x.second==1){
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};
```

### O(N) Time O(1) Bit Manipulation solution

Idea is to use property of XOR:

```
1. xor(a, a) = 0
2. xor(a, 0) = xor(0, a) = a
3. xor(1, 1) = xor(0, 0) = 0
4. xor(1, 0) = xor(0, 1) = 1
5. xor(a, b) = c => xor(a, c) = b and xor(b, c) = a
```

Let two distinct elements be: first and sec. Now, firstXorSec := xor(first, sec) = xor(nums[i], 0), 0 <= i < [n:= nums.size()], why? because nums has odd and even freq. elements, doing xor will cancel out elements with even freq. using the 1. property of xor. So, at the end, xor of only odd freq. elements i.e first and sec remains.

Now, first != sec => there is at least 1 set bit in firstXorSec. Using 4. property of xor, one of first and sec, must have a set bit (Let it be first). We find/ denote this rightmost set bit using mask: has all bits 0 except the rightmost set bit in firstXorSec. So, we can divide the elements in nums in two groups A and B, where:

```
1. groupA: (num & mask) == 1 i.e bit is set
2. groupB: (num & mask) == 0 i.e bit is not set
```

Clearly, both first and sec belong to different groups and since, all other elements occurs in pair, so, we can safely again use 1. property of xor to generate first. Finally, using 5. property of xor, we have `sec = xor(firstXorSec, first)`

### Code

```cpp
class Solution {
public:
    vector<int> singleNumber(vector<int> &nums){
        int firstXorSec = 0, mask = 1, first = 0;
        // get xor of first and sec
        for (auto &num : nums)
            firstXorSec ^= num;
        // get rightmost set bit in above xor
        while (!(firstXorSec & mask))
            mask <<= 1;
        // get first distinct number
        for (auto &num : nums)
            if (num & mask)
                first ^= num;
        // return ans
        return {first, firstXorSec ^ first};
    }
};
```

### MUST READ

- [C++ Easy & Clean Solution | Fastest | All (4+) Methods | Detailed Explanation & Comments](<https://leetcode.com/problems/single-number-iii/discuss/1561852/C%2B%2B-Easy-and-Clean-Solution-or-Fastest-or-All-(4%2B)-Methods-or-Detailed-Explanation-and-Comments>)
- [C++ Clean Code Solution | Fastest | All (15+) Sorting Methods | Detailed](<https://leetcode.com/problems/sort-an-array/discuss/1401412/C%2B%2B-Clean-Code-Solution-or-Fastest-or-All-(15%2B)-Sorting-Methods-or-Detailed>)
