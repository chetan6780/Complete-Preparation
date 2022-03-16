# [946. Validate Stack Sequences](https://leetcode.com/problems/validate-stack-sequences/description/) 🌟🌟

Given two integer arrays pushed and popped each with distinct values, return true if this could have been the result of a sequence of push and pop operations on an initially empty stack, or false otherwise.

### Greedy Intuitive

-   One by one we push all elements in the stack.
-   If we encounter an element from the popped stack, we start popping elements until `(!st.empty() && j < n && st.top() == popped[j])`.
-   Finally return true if stack is empty else false.
-   **Time Complexity: O(n)**
-   **Space Complexity: O(n)**

### Code

```cpp
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped)
    {
        stack<int> st;
        int n = popped.size();
        int j = 0;
        for (int i = 0; i < n; i++) {
            st.push(pushed[i]);
            while (!st.empty() && j < n && st.top() == popped[j]) {
                st.pop();
                j++;
            }
        }
        return st.empty();
    }
};
```
