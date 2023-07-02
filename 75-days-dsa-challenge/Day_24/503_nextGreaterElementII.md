# [503. Next Greater Element II](https://leetcode.com/problems/next-greater-element-ii/)

### Brute force

-   **TC: O(n^2)**
-   **SC: O(1)**

### Code

```cpp
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,-1);
        for(int i = 0;i< n; i++){
            for(int j = 0; j < n ;j++){
                if(nums[i]<nums[(j+i)%n]){
                    ans[i] = nums[(j+i)%n];
                    break;
                }
            }
        }
        return ans;
    }
};
```

### Monotonic stack

-   We run loop for 2 times and push indexes instead of values.
-   Other method is same as next greater element - I.
-   **TC: O(n)**
-   **SC: O(n)**

### Code

```cpp
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums)
    {
        vector<int> ans(nums.size(),-1);
        stack<int> st;
        int n = nums.size();
        for(int i = 0; i< 2*n ; i++){
            while(!st.empty() && nums[st.top()]<nums[i%n]){
                ans[st.top()] = nums[i%n];
                st.pop();
            }
            st.push(i%n);
        }
        return ans;
    }
};
```
