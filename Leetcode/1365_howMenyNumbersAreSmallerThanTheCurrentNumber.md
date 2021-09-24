# [1365. How Many Numbers Are Smaller Than the Current Number](https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/) 🌟

Given the array nums, for each nums[i] find out how many numbers in the array are smaller than it. That is, for each nums[i] you have to count the number of valid j's such that j != i and nums[j] < nums[i].

Return the answer in an array.

### O(N^2) Time solution

- Brute force for each array element.

### Code

```cpp
class Solution{
public:
    vector<int> smallerNumbersThanCurrent(vector<int> &nums)
    {
        int n = nums.size();
        int cnt = 0;
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            cnt = 0;
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                {
                    if (nums[j] < nums[i])
                        cnt++;
                }
            }
            ans[i] = cnt;
        }
        return ans;
    }
};
```

### O(N) Time O(N) space optimization

-Store the count in a bucket and take the running sum.

### Code

```cpp
class Solution{
public:
    vector<int> smallerNumbersThanCurrent(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n);
        vector<int> cnt(101, 0);

        for (int i = 0; i < n; i++)
            cnt[nums[i]]++;

        for (int i = 1; i <= 100; i++)
            cnt[i] += cnt[i - 1];

        for (int i = 0; i < n; i++)
            ans[i] = ((nums[i] == 0) ? 0 : cnt[nums[i] - 1]);

        return ans;
    }
};
```
