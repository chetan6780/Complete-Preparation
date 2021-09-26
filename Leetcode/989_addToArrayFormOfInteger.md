# [989. Add to Array-Form of Integer](https://leetcode.com/problems/add-to-array-form-of-integer/) 🌟

The array-form of an integer num is an array representing its digits in left to right order.

- For example, for num = 1321, the array form is [1,3,2,1].

Given num, the array-form of an integer, and an integer k, return the array-form of the integer num + k.

### O(N) Time and O(1) Space

- We use k itself as carry.
- From last to first we fill array with addition and mod.
- If after loop, k have some carry we insert k to the start of array untill it becomes 0.

### Code

```cpp
class Solution{
public:
    vector<int> addToArrayForm(vector<int> &num, int k)
    {
        for (int i = num.size() - 1; i >= 0 && k > 0; --i)
        {
            num[i] += k;
            k = num[i] / 10;
            num[i] %= 10;
        }
        while (k > 0)
        {
            num.insert(num.begin(), k % 10);
            k /= 10;
        }
        return num;
    }
};
```
