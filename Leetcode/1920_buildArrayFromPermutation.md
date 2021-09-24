# <a href="https://leetcode.com/problems/build-array-from-permutation/" style="color: green">1920. Build Array from Permutation</a>

Given a zero-based permutation nums (0-indexed), build an array ans of the same length where ans[i] = nums[nums[i]] for each 0 <= i < nums.length and return it.
A zero-based permutation nums is an array of distinct integers from 0 to nums.length - 1 (inclusive).

---

### O(n) time and O(n) space solution

- For i=0 to n , simply do what they have asked to.
- Push_back(nums[nums[i]])

### Code

```cpp
class Solution{
public:
    vector<int> buildArray(vector<int> &nums)
    {
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            ans.push_back(nums[nums[i]]);
        }
        return ans;
    }
};
```

---

### O(n) time and O(1) space optimization

- This is done to keep both old and new value together.
- going by the example of [5,0,1,2,3,4], n = 6(size of array)
- `nums[i] = nums[i]+(n*(nums[nums[i]]%n));`
- after this nums[0] will be 5 + 6\*(4%6) = 5 + 24 = 29;
- now for next index calulation we might need the original value of num[0] which can be obtain by num[0]%6 = 29%6 = 5;
- if we want to get just the new value of num[0], we can get it by num[0]/6 = 29/6 = 4

### Code

```cpp
class Solution{
public:
    vector<int> buildArray(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            nums[i] = nums[i] + (n * (nums[nums[i]] % n));
        }
        for (int i = 0; i < n; i++)
        {
            nums[i] /= n;
        }
        return nums;
    }
};
```
