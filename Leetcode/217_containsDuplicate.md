# [217. Contains Duplicate](https://leetcode.com/problems/contains-duplicate/)

Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

### O(N^2) Time and constant space

- Cheak for every element, if it is present in the array using 2 loops.

### Pseudo code

```
for i(0,n)
    for j(i+1,n)
        if nums[i] == nums[j]
            return true
return false
```

---

### O(N log N) Time and constant space

- We can sort the array, so duplicate elements will be next to each other.

### Code

```cpp
class Solution{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 1; i < n; i++)
        {
            if (nums[i - 1] == nums[i])
            {
                return true;
            }
        }
        return false;
    }
};
```

---

### O(N) Time and O(N) Space

- We can use a hash table to store the elements.

### Code

```cpp
class Solution{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_set<int> st;
        for (auto &x : nums)
        {
            if (st.find(x) != st.end()) return true;
            st.insert(x);
        }
        return false;
    }
};
```
