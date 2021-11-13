# [739. Daily Temperatures](https://leetcode.com/problems/daily-temperatures/) 🌟🌟

Given an array of integers `temperatures` represents the daily temperatures, return an array `answer` such that `answer[i]` is the number of days you have to wait after the `ith` day to get a warmer temperature. If there is no future day for which this is possible, keep `answer[i] == 0` instead.

### Brute Force

-   **TC: O(N^2)**
-   **SC: O(1)**
-   check for every day in an array, if the next day is grater or not.

### Code

```cpp
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temper) {
        vector<int> ans;
        int n = temper.size();
        for(int i=0;i<n;i++){
            int day=0;
            for(int j=i+1;j<n;j++){
                if(temper[j]>temper[i]){
                    day=j-i;
                    break;
                }
            }
            ans.push_back(day);
        }
        return ans;
    }
};
```

### Stack Solution

-   **TC: O(N)**
-   **SC: O(N)**
-   We iterate array from back.
-   We use stack to store the index of the days which have greater temperature than the current day.
-   Until the top element of the stack is not greater or the stack is empty, we pop the top element.
-   After the operation, if stack is empty, we set ith element of ans array to 0, else we set it to `st.top - i`.
-   return the ans vector.

### Code

```cpp
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temper)
    {
        int n = temper.size();
        stack<int> s;
        vector<int> ans(n);

        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && temper[i] >= temper[s.top()])
                s.pop();
            ans[i] = s.empty() ? 0 : s.top() - i;
            s.push(i);
        }

        return ans;
    }
};
```
