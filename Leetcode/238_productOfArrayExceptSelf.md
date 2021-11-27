# [238. Product of Array Except Self](https://leetcode.com/problems/product-of-array-except-self/) 🌟🌟

Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

### Intuitive Solution

-   We can take the product of all the elements in the array and then divide it by the element at the current index.
-   We should take care of cases where num == 0.
-   If there are more than 1 zero ans array will be all 0.
-   If there is only one 0 then ans array will be all 0 except at the index where 0 appears.
-   **TC: O(N)**
-   **SC: O(1)**

### Using Extra space

-   Since we need product of left and right elements, we can think of following solution
-   We precalculate the product form left side in the left array and the product from right side in the right array.
-   Here corner cases are:
    -   ans[0] = right[1]
    -   ans[n-1] = left[n-2]
-   **TC: O(N)**
-   **SC: O(N)**, since we are using 2 extra vectors to store the prefix product and suffix product.

### Code

```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> left(n), right(n);
        vector<int> ans(n);
        int prod = 1;
        for (int i = 0; i < n; i++) {
            prod *= nums[i];
            left[i] = prod;
        }
        prod = 1;
        for (int i = n - 1; i >= 0; i--) {
            prod *= nums[i];
            right[i] = prod;
        }

        ans[0] = right[1], ans[n - 1] = left[n - 2];
        for (int i = 1; i < n - 1; i++) {
            ans[i] = left[i - 1] * right[i + 1];
        }
        return ans;
    }
};
```

### Space optimization

-   Instead of using 2 extra left and right array for storing prefix and suffix product, we can use owr ans vector to do both.since its given that ans vector will not considered as extra space.
-   first store the prefix multiplication in ans vector.
-   Then we ge ans[i] by multiplying `ans[i-1] and right[i+1]` here `right[i+1]=prod` so `ans[i] = ans[i - 1] * prod;`
-   from right each time we get num from right side and multiply it with the previous product.
-   finally `ans[0]=prod` itself

### Code

```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> ans;

        int prod = 1;
        for (int i = 0; i < n; ++i) {
            prod *= nums[i];
            ans.push_back(prod);
        }

        prod = 1;
        for (int i = n - 1; i > 0; --i) {
            ans[i] = ans[i - 1] * prod;
            prod *= nums[i];
        }
        ans[0] = prod;
        return ans;
    }
};
```

### Read

-   [[C++/Python] 4 Simple Solutions w/ Explanation | Prefix & Suffix product O(1) space approach](<https://leetcode.com/problems/product-of-array-except-self/discuss/1597994/C%2B%2B-3-Simple-Solutions-w-Explanation-or-Prefix-and-Suffix-product-O(1)-space-approach>)

```

```
