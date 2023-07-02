# [Help Classmates](https://practice.geeksforgeeks.org/problems/fab3dbbdce746976ba35c7b9b24afde40eae5a04/1/)

### Next smaller element

### Code

```cpp
class Solution {
public:
    vector<int> help_classmate(vector<int> arr, int n)
    {
        stack<pair<int, int>> st;
        vector<int> ans(n, -1);
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && st.top().first > arr[i])
            {
                ans[st.top().second] = arr[i];
                st.pop();
            }
            st.push({arr[i], i});
        }
        return ans;
    }
};
```
